#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    char ch;        
	cout << "指令: copy <input> <output>" << endl; 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt", ios::in | ios::binary); 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\b.txt", ios::out | ios::binary); 

    if(!fin) { 
        cout << "檔案讀入失敗" << endl; 
        return 1; 
    } 

    if(!fout) { 
        cout << "檔案輸出失敗" << endl; 
        return 1; 
    } 

    while(!fin.eof()) { 
        fin.get(ch); 
        if(!fin.eof()) 
            fout.put(ch); 
    } 

    fin.close(); 
    fout.close(); 

    return 0;
}