#include "Frame_Define.h"

#include "Heap_Define.h"
#include "math.h"
#include <time.h>
#include "windows.h"

#define KeyframesNum 10 //要選取關鍵楨的數量

int main(){
	//建立禎Frame類的對象frame
	Frame frame[FramesNum+1];
	
	for(int i=1; i<=FramesNum; i++){
		frame[i] = Frame(i);
//	frame[i].Print();
	}

	


	int s = GetTickCount();
	//建立最小堆MinHeap類的對象minheap
	MinHeap minheap( FramesNum, FramesNum, frame );
	
//	int s = GetTickCount();

	double VideoDistance = 0 ;
	
	while(minheap.GetCurrentSize() > KeyframesNum){//在關鍵楨集合中的關鍵楨數量大於用戶設定的數量時，刪除關鍵楨

	//	cout<<minheap.GetCurrentSize()<<endl;
		Node n; 
		VideoDistance += minheap.DeleteMin(n, frame);
	}

	cout<<GetTickCount() - s<<endl;
	minheap.ShowCurrentNode();

	
	cout<<"VideoDistance for HEAP keyframe is "<<VideoDistance<<endl;

	
	
	
	double VideoDistanceCheck = 0;
//	for(int i=1; i<11; i++)
//		VideoDitanceCheck += frame[3].Distance(frame[i]);
//	for(;i<23; i++)
//		VideoDitanceCheck += frame[16].Distance(frame[i]);
//	for(;i<33; i++)
//		VideoDitanceCheck += frame[29].Distance(frame[i]);
//	for(;i<45; i++)
//		VideoDitanceCheck += frame[36].Distance(frame[i]);
//	for(;i<55; i++)
//		VideoDitanceCheck += frame[51].Distance(frame[i]);
//	for(;i<60; i++)
//		VideoDitanceCheck += frame[58].Distance(frame[i]);
//	for(;i<66; i++)
//		VideoDitanceCheck += frame[62].Distance(frame[i]);
//	for(;i<80; i++)
//		VideoDitanceCheck += frame[71].Distance(frame[i]);

//	cout<<"VideoDistanceCheck for HEAP keyframe is "<<VideoDitanceCheck<<endl;


	
	VideoDistanceCheck = 0;
	for(int j=1; j<=KeyframesNum; j++){
	//	cout<<"Taoleft "<<minheap.GetNode_Taoleft(j)<<endl;
	//	cout<<"Taoright "<<minheap.GetNode_Taoright(j)<<endl;
	//	cout<<"Id "<<minheap.GetNode_Id(j)<<endl;
	//	cout<<"____________________________"<<endl;

		for(int k=minheap.GetNode_Taoleft(j); k<minheap.GetNode_Taoright(j); k++)
			VideoDistanceCheck += frame[minheap.GetNode_Id(j)].Distance(frame[k]);
	}
	//VideoDitanceCheck += frame[minheap.GetNode_Id(7)].Distance(frame[80]);

	cout<<"VideoDistanceCheck for HEAP keyframe is "<<VideoDistanceCheck<<endl;



//	int a;
//	cin>>a;

//	system("OpenGL_Display.exe");
 WinExec("visualization in MFC.exe", SW_SHOW); 
	int a;
	cin>>a;

}



		
