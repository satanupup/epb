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
	//在程式中我們先解除了ios::dec格式旗標，這個動作並不是一定需要，但在某些編譯器中，這個旗標會覆蓋其它的旗標，所以我們仍先清除比較保險。 
    cout.unsetf(ios::dec); // 取消10進位顯示 
    cout.setf(ios::hex | ios::scientific); // 16進位顯示或科學記號顯示 
    cout << 12345 << "  " << 100 << endl; 
                                                                                
    cout.setf(ios::showpos | ios::showpoint); // 正數顯示 + 號且顯示小數點 
    cout << 10.0 << ": " << -10.0 << endl; 
	system("pause");
    return 0; 
}
