/*
一個結構的大小是固定的，當要寫入一個結構時，可以使用這樣的語法： 
fout.write(reinterpret_cast<const char*> (&student), sizeof(Student)); 
其中student是Student自訂struct所宣告的變數名稱，由於write接受const char*型態的變數，
所以使用reinterpret_cast<const char*> 將之轉換為const char*指標。 
*/

#include <iostream> 
#include <fstream> 
#include "Student.h" 
using namespace std; 

int main(int argc, char* argv[]) { 
  
       
	cout << "指令: create <filename>" << endl; 
	 
    ofstream fout("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt", ios::binary); 

    if(!fout) { 
        cerr << "檔案輸出失敗" << endl; 
        return 1; 
    } 

    int count; 
    cout << "要建立幾筆資料？ "; 
    cin >> count; 

    Student student = {0, "", 0.0}; 

    for(int i = 0; i < count; i++) { 
        fout.write(reinterpret_cast<const char*> (&student), 
            sizeof(Student)); 
    } 

    fout.close(); 
	std::system("pause");
    return 0; 
}

   

	