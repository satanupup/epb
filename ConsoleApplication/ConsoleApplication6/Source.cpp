#include <iostream>
using namespace std;

class Father
{
protected:
	int FatherTall,Fatherweight;
public:
	void SetFatherTall(int FatherSTall){FatherTall = FatherSTall;}
	void SetFatherweight(int FatherSweight){Fatherweight = FatherSweight;}
	void PrintFatherTallweight()
	{
		cout<<"Tall="<<FatherTall<<"\t"<<"weight="<<Fatherweight<<endl;
	}
};
class Son :public Father
{
private:
	int SonWidth,SonLong;
public:
	void SetSonWidth(int SonSWidth){SonWidth = SonSWidth;}
	void SetSonLong(int SonSLong){SonLong = SonSLong;}
	void PrintSonWidthLong()
	{
		cout<<"Width="<<SonWidth<<"\t"<<"Long="<<SonLong<<endl;
	}
	void show()
	{
			cout<<"Tall="<<FatherTall<<"\t"<<"weight="<<Fatherweight<<endl;		
			cout<<"Width="<<SonWidth<<"\t"<<"Long="<<SonLong<<endl;
	}
};
int main()
{
	Son LiMing;
	LiMing.SetFatherTall(180);
	LiMing.SetFatherweight(80);
	LiMing.SetSonLong(134);
	LiMing.SetSonWidth(65);
	LiMing.show();
	system("pause");
	return 0;
}
