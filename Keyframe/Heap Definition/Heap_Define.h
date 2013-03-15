#ifndef _HEAP_DEFINE_H  
#define _HEAP_DEFINE_H

//#include "Heap.h"
#include "Frame_Define.h"
//#include "math.h"
//#include "fstream"


//#include "stdlib.h"
//#include "iostream"

using namespace std;



struct Heap_Node{
	int id;
	
	int taoleft;
	int taoright;
	int tao;

	double Eleft;
	double Eright;
	double deltaE;

};//定義堆節點

typedef struct Heap_Node Node;


class MinHeap{

public:

	MinHeap (int n, int sz, Frame *frame ); //帶有堆的初始值的構造函數
	
	~MinHeap () { delete [] node; } //堆的析構函數

	void BuildHeap (); //建立最小堆
	double DeleteMin ( Node & x, Frame *frame); //刪除最小堆中的最小元素，即堆頂元素。並且按照算法第二、三步修改節點的相關屬性。重建堆



	int IsEmpty () const {return CurrentSize==0;} //判堆空麼？
	int IsFull () {return CurrentSize==MaxSize;} //判堆滿麼？
	bool IsTheIdAlive(int i);//判斷此id的禎是否還在堆中
	int FrameIdToNodeIndex(int i);//從禎的Id到Node的索引
	int FindNodeNeighbourId(Node & x, int IdOffset);//尋找被刪除的禎的相鄰禎的Id

	int GetCurrentSize(){return CurrentSize;}//讀取堆的當前節點數
	void ShowCurrentNode(){//輸出堆的當前節點信息

		int sortflag = 1; //以關鍵楨在視頻流中的位置為關鍵字排序
		Node temp; 

		for(int i=1; (i<CurrentSize)&&(sortflag==1); i++){
			sortflag = 0;
			for(int j=1; j<=CurrentSize-i; j++){
		//		sortflag = 0;
				if(node[j].id > node[j+1].id){
					temp = node[j]; 
					node[j] = node[j+1];
					node[j+1] = temp;

					sortflag = 1;
				}
			}

		}


		fstream outfile; //將關鍵楨的選取結果寫入文件

		outfile.open("result.txt", ios::out);
		if(! outfile){
			cout<< "result.txt can not open.\n";
			abort();
		}
		
		outfile<<VideoName<<endl; //視頻名
        outfile<<FramesNum<<endl; //楨的總數
		outfile<<CurrentSize<<endl; //關鍵楨的數量 

		for(int i=1; i<=CurrentSize; i++){
			cout<<"node["<<i<<"].id="<<node[i].id<<" , taoright="<<node[i].taoright<<" , taoleft="<<node[i].taoleft<<endl;
			
			outfile<<node[i].taoleft<<endl;
			outfile<<node[i].id<<endl;
			outfile<<node[i].taoright<<endl;

		}

		outfile.close();
	}
	 
	int GetNode_Id(int index) { return node[index].id; }
	int GetNode_Taoleft(int index) { return node[index].taoleft; }
	int GetNode_Taoright(int index) { return node[index].taoright; }


	void Clear () {CurrentSize=0;} //置堆空，堆中沒有一個元素


private:

	Node * node; //保存堆的數組
	int CurrentSize; //堆當前的節點個數
	int MaxSize; //數組可以保存的結點的最大數目
	
	void SiftDown (int j);

};

MinHeap::MinHeap(int n, int sz, Frame *frame ){

	
	CurrentSize = n;
	MaxSize = sz;
	node = new Node[sz+1];
	int i;
	for( i=1; i<=n; i++){

		node[i].id = i;
		node[i].Eleft = node[i].Eright = 0;
		node[i].taoleft = i;
		node[i].taoright = i+1;

	
		
		if( i==1 ){
			node[i].tao = 1;
	//		node[i].taoleft = 1;
	//		node[i].taoright = 2;
		}
		if( i==n ){
			node[i].tao = n;
	//		node[i].taoright = n;
	//		node[i].taoleft = n;
		}
		
		if(! (i==1||i==n) ){

	//		node[i].taoleft = i;
	//		node[i].taoright = i+1;

			if( frame[i].Distance(frame[i-1]) <= frame[i].Distance(frame[i+1]) )
				node[i].tao = i;
			else
				node[i].tao = i+1;
		}

	
		if( i==1 )
			node[i].deltaE = pow(frame[1].Distance(frame[2]), 2);
		else if( i==FramesNum )
			node[i].deltaE = pow(frame[FramesNum].Distance(frame[FramesNum-1]), 2);
		else 
			node[i].deltaE = min( pow(frame[i].Distance(frame[i+1]), 2) , pow(frame[i].Distance(frame[i-1]), 2) );



		
//		switch(i){
//			case 1 : node[i].deltaE = pow(frame[1].Distance(frame[2]),2);
//			case FramesNum : node[i].deltaE = pow(frame[FramesNum].Distance(frame[FramesNum-1]),2);
//			default: node[i].deltaE = min( pow(frame[i].Distance(frame[i+1]),2), pow(frame[i].Distance(frame[i-1]),2) );
//		}
//		cout<<node[i].deltaE<<endl;

	}
	    
	BuildHeap();

	

	for(i=1; i<=n; i++){
		cout<<"id="<<node[i].id<<endl;
		cout<<"deltaE="<<node[i].deltaE<<endl;
	cout<<"tao="<<node[i].tao<<endl;
	}
		

}//給堆節點初始化和建立最小堆

void MinHeap::SiftDown(int j){
	
	int MinSon;//用於記錄小兒子的下標地址
	node[0] = node[j];

	
	for(; j*2<=CurrentSize; j=MinSon){
		MinSon = 2*j;
		if( MinSon != CurrentSize && node[MinSon+1].deltaE < node[MinSon].deltaE ) MinSon++; 
		if( node[MinSon].deltaE < node[0].deltaE )
			node[j] = node[MinSon];

		else break;
	}
	node[j] = node[0];

}

void MinHeap::BuildHeap(){
	for(int j=CurrentSize/2; j>0; j--)
		SiftDown(j);

//	cout<<"The current node[1]'s id is "<<node[1].id<<endl;
}

bool MinHeap::IsTheIdAlive(int i){
	int j;
	for( j=1;j<=CurrentSize;j++){
		if(node[j].id==i)
		break;
	}

	if(j<=CurrentSize) return true;
	else return false;
}
int MinHeap::FrameIdToNodeIndex(int i){
	int j;
	for( j=1;j<=CurrentSize;j++){
		if(node[j].id==i)
		break;
	}
	return j;
}

int MinHeap::FindNodeNeighbourId(Node & x, int IdOffset){
	if(IdOffset>0){//從當前禎向後找還在堆中的IdOffset的禎
		int alives=0;
		int id;
		for( id=x.id+1; id<=FramesNum; id++){
			if(IsTheIdAlive(id)) alives++;
			if(alives == IdOffset) break;
		}
		if(id<=FramesNum) return id;//確實找到
		else return -1;//沒找到，返回一個非法整數
	}
	else{//從當前禎向前找還在堆中的IdOffset的禎
		int alives=0;
		int id;
		for( id=x.id-1; id>0; id--){
			if(IsTheIdAlive(id)) alives++;
			if(alives == (0-IdOffset)) break;
		}
		if(id>0) return id;//確實找到
		else return -1;//沒找到，返回一個非法整數
	}
}

	
double MinHeap::DeleteMin( Node & x, Frame *frame){

	
	x = node[1];//node[1]為當前堆的堆頂節點，即最小節點
	node[1] = node[CurrentSize--];

	SiftDown(1);//重建堆


	cout<<"Delete "<<x.id<<" frame."<<endl;
	cout<<"Current deltaE = "<<x.deltaE<<endl;
	
	
	int IdKFPOne, IdKFNOne, IdKFPTwo, IdKFNTwo;
	int IndexPOne, IndexNOne, IndexPTwo, IndexNTwo; 
	//找到與被刪除的當前禎Id前後相差1、2的堆中現存關鍵禎的Id及他們在堆中的節點的Index
	IdKFPOne = FindNodeNeighbourId(x, 1);
	IdKFNOne = FindNodeNeighbourId(x, -1);
	IdKFPTwo = FindNodeNeighbourId(x, 2);
	IdKFNTwo = FindNodeNeighbourId(x, -2);

	if(IdKFPOne!=-1) IndexPOne = FrameIdToNodeIndex(IdKFPOne);
	if(IdKFNOne!=-1) IndexNOne = FrameIdToNodeIndex(IdKFNOne);
	if(IdKFPTwo!=-1) IndexPTwo = FrameIdToNodeIndex(IdKFPTwo);
	if(IdKFNTwo!=-1) IndexNTwo = FrameIdToNodeIndex(IdKFNTwo);


	//按照算法第二步修改節點的屬性值

	if(IdKFNOne==-1){//被刪除的當前禎左邊不存在未被刪除的關鍵禎，則只處理當前禎右邊相鄰關鍵禎
		
		node[IndexPOne].taoleft = 1;
		
		double s=0;
		for(int i=1; i<IdKFPOne; i++)
			s += pow(frame[i].Distance(frame[IdKFPOne]), 2);
		node[IndexPOne].Eleft = s ;
	}

	if(IdKFPOne==-1){//被刪除的當前禎右邊不存在未被刪除的關鍵禎，則只處理當前禎左邊相鄰關鍵禎
		
		node[IndexNOne].taoright = FramesNum;

		double s=0;
		for(int i=FramesNum; i>IdKFNOne; i--)
			s += pow(frame[i].Distance(frame[IdKFNOne]), 2);
		node[IndexNOne].Eright = s;
	}

	if(!(IdKFPOne==-1 || IdKFNOne==-1)){//被刪除的當前禎左右都至少有一個未被刪除的關鍵禎，處理兩邊的未刪除的關鍵禎
		
		node[IndexNOne].taoright = x.tao;

		double s=0;
		for(int i=IdKFNOne+1; i<x.tao; i++)
			s += pow(frame[i].Distance(frame[IdKFNOne]), 2);
		node[IndexNOne].Eright = s;

		
		node[IndexPOne].taoleft = x.tao;

		s=0;
		for(int i=x.tao; i<IdKFPOne; i++)
			s += pow(frame[i].Distance(frame[IdKFPOne]), 2);
		node[IdKFPOne].Eleft = s;
	}

	
	
	//按照算法第三步修改節點的屬性值
	
	int Mmin;
	double FirstResult; 
	double FirstUp;
	double FirstDown;

//	int aForDeltaE;
//	double Prior;
//	double Posterior;

	if(IdKFNOne!=-1){// 
		if(IdKFNTwo!=-1){//被刪除的當前禎左邊至少有2個尚未被刪除的關鍵禎
			if(IdKFPOne!=-1){//被刪除的當前禎右邊至少有1個尚未被刪除的關鍵禎
				//用文章中描述的經典方法修改p(j-1)的deltaE和tao
				
				FirstResult = FirstUp = FirstDown = 0;
				Mmin = 0;
				int  t;
				for(  t=IdKFNTwo; t<IdKFPOne; t++)
				FirstUp += pow(frame[t].Distance( frame[IdKFPOne]), 2);

				FirstResult = FirstUp + FirstDown;
				Mmin = IdKFNTwo;

				for(int m=IdKFNTwo+1; m<IdKFPOne; m++){
					double result=0;
					double up=0;
					double down=0;

					for(t=IdKFNTwo+1; t<=m-1; t++)
						up += pow(frame[t].Distance( frame[IdKFNTwo]), 2);
					for(; t<IdKFPOne; t++)
						down += pow(frame[t].Distance( frame[IdKFPOne]), 2);

					result = up + down;

					if( result<FirstResult ){
						FirstResult = result;
						Mmin = m;
					}
				}
				
//				cout<<"The Prior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
//				Prior = node[IndexNOne].deltaE;
				node[IndexNOne].deltaE = FirstResult - node[IndexNTwo].Eright - node[IndexPOne].Eleft;// - (node[IndexNOne].Eleft + node[IndexNOne].Eright) ;
				node[IndexNOne].tao = Mmin;
//				cout<<"The Posterior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
//				Posterior = node[IndexNOne].deltaE; 
//				if ( Prior > Posterior ){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Left Frame = "<<IdKFNOne<<endl;
//					cin>>aForDeltaE; 
//				}
			
			
			}


			else{//被刪除的當前禎右邊沒有尚未被刪除的關鍵禎
				//方法1
				node[IndexNOne].tao = FramesNum;

				double s=0;
				for(int i=node[IndexNOne].taoleft; i<FramesNum; i++)
					s += pow(frame[i].Distance(frame[IdKFNTwo]), 2);

//				cout<<"The Prior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
//				Prior = node[IndexNOne].deltaE;			
				node[IndexNOne].deltaE = s - (node[IndexNOne].Eleft + node[IndexNOne].Eright);
//				cout<<"The Posterior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
			
//				Posterior = node[IndexNOne].deltaE; 
//				if ( Prior > Posterior){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Left Frame = "<<IdKFNOne<<endl;
//					cin>>aForDeltaE; 
//				}
			
			}
		}

		else{//被刪除的當前禎左邊只有1個尚未被刪除的關鍵禎
			//方法2
			node[IndexNOne].tao = 1;

			double s=0;
			for(int i=1; i<x.tao; i++)
				s += pow(frame[i].Distance(frame[IdKFPOne]), 2);
			
//			cout<<"The Prior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
//			Prior = node[IndexNOne].deltaE;	
			node[IndexNOne].deltaE = s - (node[IndexNOne].Eleft + node[IndexNOne].Eright);
//			cout<<"The Posterior DeltaE = "<<node[IndexNOne].deltaE<<endl;  
//
//			Posterior = node[IndexNOne].deltaE; 
//			if ( Prior > Posterior){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Left Frame = "<<IdKFNOne<<endl;
//					cin>>aForDeltaE; 
//			}
		}
	}

	
	
	if(IdKFPOne!=-1){//被刪除的當前禎右邊至少有1個尚未被刪除的關鍵禎
		if(IdKFPTwo!=-1){//被刪除的當前禎右邊至少有2個尚未被刪除的關鍵禎
			if(IdKFNOne!=-1){//被刪除的當前禎左邊至少有1個尚未被刪除的關鍵禎
				//用文章中描述的經典方法修改p(j-1)的deltaE和tao
				FirstResult = FirstUp = FirstDown = 0;
				Mmin = 0;
				int t;
				for( t=IdKFNOne; t<IdKFPTwo; t++)
				FirstDown += pow(frame[t].Distance(frame[IdKFPTwo]), 2);

				FirstResult = FirstUp + FirstDown;
				Mmin = IdKFNOne;

				for(int m=IdKFNOne+1; m<IdKFPTwo; m++){
					double up = 0;
					double down = 0;
					double result = 0;
					for(t=IdKFNOne+1; t<=m-1; t++)
						up += pow(frame[t].Distance(frame[IdKFNOne]), 2);
					for(; t<IdKFPTwo; t++)
						down += pow(frame[t].Distance(frame[IdKFPTwo]), 2);
					result = up + down;

					if(result < FirstResult){
						FirstResult = result;
						Mmin = m;
					}
				}
				
//				cout<<"The Prior DeltaE = "<<node[IndexPOne].deltaE<<endl;  
//				Prior = node[IndexPOne].deltaE;
				node[IndexPOne].deltaE = FirstResult - node[IndexNOne].Eright - node[IndexPTwo].Eleft;// - (node[IndexPOne].Eleft + node[IndexPOne].Eright) ;
				node[IndexPOne].tao = Mmin;
//				cout<<"The Posterior DeltaE = "<<node[IndexPOne].deltaE<<endl;  
		
//				Posterior = node[IndexPOne].deltaE;
//				if ( Prior > Posterior ){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Right Frame = "<<IdKFPOne<<endl;
//					cin>>aForDeltaE; 
//				}

			}

			else{//被刪除的當前禎左邊沒有尚未被刪除的關鍵禎
				//方法3
				node[IndexPOne].tao = 1;

				double s=0;
				for(int i=1; i<node[IndexPOne].taoright; i++)
					s += pow(frame[i].Distance(frame[IdKFPTwo]), 2);

//				cout<<"The Prior DeltaE = "<<node[IndexPOne].deltaE<<endl;
//				Prior = node[IndexPOne].deltaE;
				node[IndexPOne].deltaE = s - (node[IndexPOne].Eleft + node[IndexPOne].Eright);
//				cout<<"The Posterior DeltaE = "<<node[IndexPOne].deltaE<<endl;  
//				
//				Posterior = node[IndexPOne].deltaE;
//				if ( Prior > Posterior ){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Right Frame = "<<IdKFPOne<<endl;
//					cin>>aForDeltaE; 
//				}
			}
		}

		else{//被刪除的當前禎右邊只有1個尚未被刪除的關鍵禎
			//方法4
			node[IndexPOne].tao = FramesNum;

			double s=0;
			for(int i=x.tao; i<FramesNum; i++)
				s += pow(frame[i].Distance(frame[IdKFNOne]), 2);

//			cout<<"The Prior DeltaE = "<<node[IndexPOne].deltaE<<endl;  
//			Prior = node[IndexPOne].deltaE;
			node[IndexPOne].deltaE = s - (node[IndexPOne].Eleft + node[IndexPOne].Eright);
//			cout<<"The Posterior DeltaE = "<<node[IndexPOne].deltaE<<endl;  
//		
//			Posterior = node[IndexPOne].deltaE;
//		
//			if ( Prior > Posterior ){
//					cout<<"!!!!!!!!!!!!!!!!"<<endl;
//					cout<<"The Prior DeltaE = "<<Prior<<endl;
//					cout<<"The Posterior DeltaE = "<<Posterior<<endl;
//					cout<<"The Right Frame = "<<IdKFPOne<<endl;
//					cin>>aForDeltaE; 
//			}
		}
	}

	
	//重建堆
	BuildHeap();

//	if(IdKFNOne!=-1) SiftDown(IndexNOne);
//	if(IdKFPOne!=-1) SiftDown(IndexPOne);

	return x.deltaE;

}
	



#endif



			











