#include <iostream> 
#include <fstream> 
using namespace std; 

int main(int argc, char* argv[]) { 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt", ios::out | ios::binary); 
    if(!fout) { 
        cout << "無法讀取檔案" << endl; 
        return 1; 
    } 

    int arr[5] = {1, 2, 3, 4, 5}; 
    fout.write((char*) arr, sizeof(arr)); 
    fout.close(); 

    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\temp.txt", ios::in | ios::binary); 
    if(!fin) { 
        cout << "無法讀取檔案" << endl; 
        return 1; 
    } 
    
    fin.read((char*) arr, sizeof(arr)); 
    cout << "arr: "; 
    for(int i = 0; i < 5; i++) 
        cout << arr[i] << ' '; 
    cout << endl; 

    fin.close(); 

	system("pause");

    return 0; 
}