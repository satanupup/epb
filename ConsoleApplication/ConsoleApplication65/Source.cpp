#include <iostream> 
#include <fstream> 
using namespace std; 

int main(int argc, char* argv[]) { 
    
	cout << "指令: copy <input> <output>" << endl; 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\a.txt"); 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\b.txt"); 

    if(!fin) { 
        cout << "無法讀入來源檔案" << endl; 
        return 1; 
    } 

    if(!fout) { 
        cout << "無法輸出目的檔案" << endl;
        fin.close();
        return 1; 
    } 

    char ch; 

    fin.unsetf(ios::skipws); // 不忽略空白 
    while(!fin.eof()) { 
        fin >> ch; 
        if(ch >= 97 && ch <= 122) 
            ch -= 32; 
        if(!fin.eof()) 
            fout << ch; 
    } 

    fin.close(); 
    fout.close(); 
	system("pause");
    return 0; 
}