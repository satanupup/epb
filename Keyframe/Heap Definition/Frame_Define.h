#ifndef _FRAME_DEFINE_H
#define _FRAME_DEFINE_H

#include <iostream>
#include <string>
#include  <sstream> 
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define PixelsNum 27648 //每一楨包含的像素個數
#define FramesNum 80 //視頻包含的總楨數

string VideoName = "kylie"; //視頻的名稱，放在debug文件夾內。



class Frame{

public:
	Frame(){}
	Frame(int i); //構造函數
	~Frame() { delete [] L; delete [] A;} //析構函數

	Frame & operator =(const Frame &fr);

	double Distance(const Frame &f);

	void Print(){

		for(int k=0;k<3*PixelsNum;k++)
		cout<<L[k]<<endl;
	}


private:
	double *L;//每個像素的L值.用堆動態分配內存
	double *A;//HSV的一維矢量化.A=H+S+V
	double first;//像素HSV一維矢量化後的一階距
	double second;//像素HSV一維矢量化後的二階距
	double third;//像素HSV一維矢量化後的三階距
};
Frame & Frame::operator =(const Frame &fr)
{
	if(this == &fr)
		return *this;

	L = new double[3*PixelsNum];
	A = new double[PixelsNum]; 
	for(int i=0;i<3*PixelsNum;i++)
		L[i] = fr.L[i];
	for(int i=0; i<PixelsNum; i++)
		A[i] = fr.A[i];

	first = fr.first;
	second = fr.second;
	third = fr.third;
		

	return *this;
}

Frame::Frame(int i){ //從相應文件中讀取數據,初始化 (關於讀取和字符串操作，查！)
	

	string filename;
	stringstream ss;
	ss<<i;
	ss>>filename;
	
	string filenametxt=VideoName+"_80_unitary/("+filename+")_unitary.txt";
	fstream infile;

	cout<<filenametxt<<endl;

	infile.open( filenametxt.c_str() ,ios::in);
	if(!infile){
		std::cout<<"Can not open file!\n";
		abort();
	}

	L = new double[3*PixelsNum]; //用new在堆裡動態分配內存
	A = new double[PixelsNum]; 

	char s[20];
	//將文件中記錄的每一個像素的rgb記錄到數組中，再做處理。
	for(int j=0; j<3*PixelsNum; j++){
		infile.getline( s, sizeof(s) );
		L[j] = atof(s);
	}

	infile.close();


	//將每個像素的rgb歸一化，使他們在[0，1]中。並且將rgb轉成hsv。對HSV做一維矢量化，每一個像素HSV一維矢量化的結果存入數組A
	i = 0;
	for(int j=0; j<3*PixelsNum; j+=3){
		double tempmax3, tempmin3;
		tempmax3 = tempmin3 = L[j];
		for(int k=1; k<3; k++){
			if( L[j+k] > tempmax3 ) tempmax3 = L[j+k];//得到一個像素rgb三者的最大值，記為tempmax3
			if( L[j+k] < tempmin3 ) tempmin3 = L[j+k];//得到一個像素rgb三者的最小值，記為tempmin3
		}
	//	cout<<"tempmax3 ="<<tempmax3<<endl;
	//	cout<<"tempmin3 ="<<tempmin3<<endl;
		if( tempmax3 > 1 ){ //如果這個最大值比一大，則將此像素的rgb歸一化。
			L[j] /= tempmax3;
			L[j+1] /= tempmax3;
			L[j+2] /= tempmax3;
		}

		double r, g, b;
		double h, s, v;
		r = L[j];
		g = L[j+1];
		b = L[j+2];

	//	cout<<"r="<<r<<endl;
	//	cout<<"g="<<g<<endl;
	//	cout<<"b="<<b<<endl;

		
		double delta = tempmax3 - tempmin3; 

		if( delta != 0 ){//此時非rgb三者相等；色度H有定義，像素有顏色；飽和度S也有定義
		//	if R = max, H = (G-B)/(max-min) 
		//	if G = max, H = 2 + (B-R)/(max-min) 
		//	if B = max, H = 4 + (R-G)/(max-min) 
		//	H = H * 60 
		//	if H < 0, H = H + 360 

			if( r == tempmax3 ) h = (g - b)/delta;
			if( g == tempmax3 ) h = 2 + (b - r)/delta;
			if( b == tempmax3 ) h = 4 + (r - g)/delta;

			h *= 60;
			if( h < 0 ) h += 360;

			h /= 360;//h歸一化至[0,1]，與s,v相同
			s = delta / tempmax3;
			v = tempmax3;
		}
		else{//此時rgb三者相等，沒有色度只有灰度；色度H無定義
			h = -1;//h無定義
			if(tempmax3 ==0){//此時r=g=b=0 黑色
				s = -1;//黑色 S無定義
				v = tempmax3;
			}
			else{//此時r=g=b!=0 灰色或白色
				s = 0;
				v = tempmax3;
			}
		}
		
	//	//S=(max-min)/max 
	//	if( tempmax3 != 0 ) s = delta/tempmax3;
	//	else{ //此時像素點的rgb都是0
	//		s = 0;
	//		v = -1;//v無定義
	//		h = -1;//h無定義
	//	}

		

	

		L[j] = h; 
		L[j+1] = s;
		L[j+2] = v;
		
	//	cout<<"h = "<<h<<endl;
	//	cout<<"s = "<<s<<endl;
	//	cout<<"v = "<<v<<endl;

		if( h<0 ) h=0;
		if( s<0 ) s=0;
		if( v<0 ) v=0;	

		A[i] = h + s + v;  //如果HSV有定義就把他們一維矢量化。沒定義的不加。
		
	//	cout<<"A["<<i<<"] = "<<A[i]<<endl;
		i++;

	}

//	for(int i=0; i<PixelsNum; i++)
//		cout<<"A["<<i<<"] = "<<A[i]<<endl;
//cout<<"A[29999] = "<<A[29999]<<endl;
//cout<<"A[30000] = "<<A[30000]<<endl;
//cout<<"A[30001] = "<<A[30001]<<endl;
	double temp = 0;
	for(int j=0; j<PixelsNum; j++)
		temp += A[j];
	cout<<"temp = "<<temp<<endl; 
	first = temp/PixelsNum;

	temp = 0;
	for(int j=0; j<PixelsNum; j++ )
		temp += pow( (A[j] - first) , 2);
//	cout<<"temp_second = "<<temp<<endl;
//	cout<<"temp_second/PixelsNum ="<<temp/PixelsNum<<endl;
	second = pow( (temp / PixelsNum) , 0.5);

	temp = 0;
	for(int j=0; j<PixelsNum; j++)
		temp += pow( fabs(A[j] - first) , 3);
	third = pow( (temp / PixelsNum) , 0.333333);

	
    cout<<"first = "<<first<<endl;
		cout<<"second = "<<second<<endl;
		cout<<"third = "<<third<<endl;



}


double Frame::Distance(const Frame &f){
//	double distance=0;
//
//	
//	for(int i=0;i<3*PixelsNum;i+=3)
//		distance += pow( ( pow((L[i]-f.L[i]),2) + pow((L[i+1]-f.L[i+1]),2) + pow((L[i+2]-f.L[i+2]),2) ), 0.5);
//	return distance;

	double distance;
	double sigma = 0;//類相關係數

//	cout<<"first ="<<first<<endl;
//	cout<<"f.first ="<<f.first<<endl;

	for(int j=0; j<PixelsNum; j++){
		sigma += (A[j] - first) * (f.A[j] - f.first);
//		cout<<"A["<<j<<"] = "<<A[j]<<endl;
//		cout<<"f.A["<<j<<"] = "<<f.A[j]<<endl;
//		cout<<"() = "<<A[j] - first<<endl;
//		cout<<"(f) ="<<f.A[j] - f.first<<endl;
	}
	sigma /= PixelsNum *second * f.second ;
//	cout<<"second = "<<second<<endl;
//	cout<<"f.second = "<<f.second<<endl;
//	cout<<"/() = "<<PixelsNum * second * f.second<<endl;

//	cout<<"sigma ="<<sigma<<endl;

//	distance = (1-sigma) * pow( ( ( pow( (first - f.first), 2 ) + pow( (second - f.second), 2 ) + pow( (third - f.third), 2) ) / 3 ) , 0.5); 
//  cout<<"distance = "<<distance<<endl;
//	distance = 1- (sigma * (2*first*f.first/(pow(first,2)+pow(f.first,2))) * (2*second*f.second/(pow(second,2)+pow(f.second,2)))* (2*third*f.third/(pow(third,2)+pow(f.third,2))));//* (pow(pow((first - f.first),2),0.5) +pow(pow((second - f.second),2),0.5)  );
//	distance = sigma*fabs(first - f.first)/ (first+f.first) * fabs(second-f.second)/(second+f.second) ;
//	distance =  ( fabs( first - f.first ) + fabs( second - f.second ) + fabs(third-f.third)) ; 
	distance = 1 - sigma * min(fabs(first/f.first),fabs(f.first/first)) * min(fabs(second/f.second),fabs(f.second/second))*min(fabs(third/f.third),fabs(f.third/third));
	return distance; 



}
		
	
#endif


 














