#include <iostream> 
#include <fstream> 
using namespace std; 

/*
filename是檔案名稱，而mode決定檔案的開啟模式，它是由ios類別所定義的常數來決定，下面列出openmode的值與用途： 
ios::in			檔案open為輸入模式(istream default)
ios::out		檔案open為寫入(ostream default)
ios::ate		從檔案尾端輸入輸出
ios::app		在檔案尾端以append模式寫入
ios::trunc		如果檔案存在，則清除檔案內容
ios::binary		以二進位模式open檔案
*/
int main() 
{ 

	char ch; 

    ifstream fin;
    fin.open("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt");                       
                            
    if(!fin) { 
        cout << "檔案I/O失敗" << endl; 
        return 1; 
    } 
                                            
    while(!fin.eof()) { 
        fin.get(ch); 
        cout << ch; 
    } 
          
	cout<<endl;
    fin.close(); 
	system("pause");
    return 0; 
}