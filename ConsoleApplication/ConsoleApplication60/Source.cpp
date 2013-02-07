#include <iostream> 
using namespace std; 

/*

以下先列出一些常用的格式化旗標： 
ios::boolalpha						將真與假以true與false顯示
ios::dec							10進位顯示
ios::fixed							正常方式顯示（非科學記號）
ios::hex							16進位顯示
ios::left							靠左
ios::oct							8進位顯示
ios::scientific						科學記號
ios::showbase						顯示基底
ios::showpoint						顯示小數點
ios::showpos						正數顯示+
ios::skipws							忽略空白字元
ios::uppercase						字母大寫

*/
int main() { 
    ios::fmtflags f; 

    cout.unsetf(ios::dec); 
    cout.setf(ios::oct | ios::showbase); 

    f = cout.flags(); 

    if(f & ios::left) {
        cout << "left flag on\n"; 
    }
    else {
        cout << "left flag off\n"; 
    }

    if(f & ios::dec) {
        cout << "dec flag on\n";
    }
    else {
        cout << "dec flag off\n"; 
    }

    if(f & ios::showbase) {
        cout << "showbase flag on\n"; 
    }
    else {
        cout << "showbase flag off\n"; 
    }

    if(f & ios::oct) {
        cout << "oct flag on\n"; 
    }
    else {
        cout << "left flag off\n"; 
    }
	system("pause");
    return 0; 
}