#include <iostream> 
#include <fstream> 
#include <iomanip> 
using namespace std; 

int main(int argc, char* argv[]) { 
    char ch; 
    int count = 0; 
	cout<<"下面這個程式可以讀入任意檔案，每次讀入一個位元組，\n並將讀入的資料以16進位數顯示，\
		若讀入的資料前導位元為1，\n為了輸出的對齊，則使用其補數加以顯示： \n"<<endl;
     
	cout << "指令: read <filename>" << endl; 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt", ios::in | ios::binary); 
    if(!fin) { 
        cout << "無法讀取檔案" << endl; 
        return 1; 
    } 

    while(!fin.eof()) { 
        fin.get(ch); 
        if(ch < 0) 
            ch = ~ch; // 負數取補數 
        cout << setw(2) << hex << (int)ch << " "; 
        count++; 
        if(count > 16) {  // 換行 
            cout << endl; 
            count = 0; 
        } 
    } 
    cout << endl; 

    fin.close(); 
	
	system("pause");
    return 0; 
}
