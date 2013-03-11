#include <iostream>
using namespace std;
class TV
{
public:	
	TV():on_off(off),volume(20),channel(1),mode(tv){}
private:
	friend class Tele;
	enum{on,off};
	enum{tv,av};
	enum{mincl,maxcl=60};
	enum{minve,maxve=100};
	bool on_off;
	int channel;
	int volume;
	int mode;
};
class Tele
{
public:
	void OnOff(TV&t){t.on_off=(t.on_off==t.on)?t.off:t.on;}
	void SetMode(TV&t){t.mode=(t.mode==t.tv)?t.av:t.tv;}
	bool VolumeDown(TV&t);
	bool VolumeUp(TV&t);
	bool ChanelUp(TV&t);
	bool ChanelDown(TV&t);
	void Show(TV&t)const;
private:
};
bool Tele::VolumeDown(TV&t)
{
	if(t.volume>t.minve)
	{
		t.volume--;
		return true;
	}
	else
		return false;
}
bool Tele::VolumeUp(TV&t)
{
	if(t.volume<t.maxve)
	{
		t.volume++;
		return true;
	}
	else
		return false;
}
bool Tele::ChanelUp(TV&t)
{
	if(t.channel<t.maxve)
	{
		t.channel++;
		return true;
	}
	else
		return false;
}
bool Tele::ChanelDown(TV&t)
{
	if(t.channel>t.minve)
	{
		t.channel--;
		return true;
	}
	else
		return false;
}
void Tele::Show(TV&t)const
{
	if(t.on_off==t.on)
	{
		cout<<"TV now Open"<<endl;
		cout<<"volume size is: "<<t.volume<<endl;
		cout<<"The signal receiving mode: "<<(t.mode==t.tv?"TV":"AV")<<endl;
		cout<<"The current channel is: "<<t.channel<<endl;
	}
	else
		cout<<"TV now closed"<<endl;
}
int main()
{
	Tele t1;
	TV t2;
	t1.Show(t2);
	t1.OnOff(t2);
	t1.Show(t2);
	cout<<"Turn up the sound"<<endl;
	t1.VolumeUp(t2);
	cout<<"To adjust the channel"<<endl;
	t1.ChanelUp(t2);
	cout<<"Conversion mode"<<endl;
	t1.SetMode(t2);
	t1.Show(t2);
	system("pause");
	return 0;
}
