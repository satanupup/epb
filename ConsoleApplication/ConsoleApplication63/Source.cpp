#include <iostream> 
#include <fstream> 
using namespace std; 

int main(int argc, char* argv[]) { 
    
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt"); 
    if(!fout) { 
        cout << "無法寫入檔案\n"; 
        return 1; 
    } 

    fout << "Justin" << "\t" << 90 << endl; 
    fout << "momor" << "\t" << 80 << endl; 
    fout << "Bush" << "\t" << 75; 

    fout.close(); 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt"); 
    if(!fin) { 
        cout << "無法讀入檔案\n"; 
        return 1; 
    } 
    
    char name[80]; 
    int score; 
    
    cout << "Name\tScore\n"; 
    while(!fin.eof()) { 
        fin >> name >> score; 
        cout << name << "\t" << score << endl; 
    } 

    fin.close();

	system("pause");
    return 0; 
}