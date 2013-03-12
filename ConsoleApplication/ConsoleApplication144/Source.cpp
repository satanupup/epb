#include <iostream>
using namespace std;
class rectangle
{
public:
	class point
	{
	public:
		void setx(int X){x=X;}
		void sety(int Y){y=Y;}
		int getx(){return x;}
		int gety(){return y;}
	private:
		int x;
		int y;
	};
	point GetUpLeft()const{return upleft;}
	point GetLowerLeft()const{return lowerleft;}
	point GetUpRight()const{return upright;}
	point GetLowRight()const{return lowerright;}
	rectangle(int top,int left,int bottom,int right);	
	int GetArea()const
	{
		int width = Right-Left;
		int height = Bottom-Top;
		return (width * height);
	}
	int GetTop()const{return Top;}
	int GetLeft()const{return Left;}
	int GetBottom()const{return Bottom;}
	int GetRight()const{return Right;}
	void SetTop(int top){Top=top;}
	void SetLeft(int left){Left=left;}
	void SetRight(int right){Right=right;}
	void SetBottom(int bottom){Bottom=bottom;}
	void SetUpLeft(){upleft.setx(Left);upleft.sety(Top);}
	void SetLowLeft(){lowerleft.setx(Left);lowerleft.sety(Bottom);}
	void SetLowRight(){lowerright.setx(Right);lowerright.sety(Bottom);}
	void SetUpRight(){upright.setx(Right);upright.sety(Top);}
private:
	point upleft;
	point lowerleft;
	point upright;
	point lowerright;
	int Top;
	int Left;
	int Bottom;
	int Right;
};
rectangle::rectangle(int top,int left,int bottom,int right)
{
	Top=top;
	Left=left;
	Bottom=bottom;
	Right=right;
	upleft.setx(Left);
	upleft.sety(Top);
	lowerleft.setx(Left);
	lowerleft.sety(Bottom);
	upright.setx(Right);
	upright.sety(Top);
	lowerright.setx(Right);
	lowerright.sety(Bottom);
}
class point
{
public:
	int GetArea(rectangle&rec){return rec.GetArea();}
};
int main()
{
	rectangle date(40,50,60,80);
	cout<<"Left is: "<<date.GetLeft()<<endl;
	cout<<"Bottom is: "<<date.GetBottom()<<endl;
	cout<<"x of the lower left: "<<date.GetLowerLeft().getx()<<endl;
	cout<<"y of the lower left: "<<date.GetLowerLeft().gety()<<endl;
	cout<<"Rectangle is Area: "<<date.GetArea()<<endl;
	cout<<"Reset the Left and Bottom value"<<endl;
	date.SetLeft(0);
	date.SetBottom(100);
	date.SetLowLeft();
	cout<<"Left is: "<<date.GetLeft()<<endl;
	cout<<"bottom is: "<<date.GetBottom()<<endl;
	cout<<"X-coordinates of the lower left: "<<date.GetLowerLeft().getx()<<endl;
	cout<<"Y-coordinates of the lower left: "<<date.GetLowerLeft().gety()<<endl;
	system("pause");
	point pt;
	cout<<"Rectangular area of: "<<pt.GetArea(date)<<endl;
	return 0;
}