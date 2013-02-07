#include <iostream> 
#include <fstream> 
#include "Student.h" 
using namespace std; 

int main(int argc, char* argv[]) { 
    Student student; 
    int count = 0, number; 

        cout << "指令: read <filename>" << endl; 


    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt", ios::in | ios::binary); 
    if(!fin) { 
        cerr << "無法讀取檔案" << endl; 
        return 1; 
    } 

    while(true) { 
        fin.read(reinterpret_cast<char *> (&student), 
            sizeof(Student)); 
        if(!fin.eof()) 
            count++; 
        else 
            break; 
    } 
    fin.clear(); 

    cout << "輸入學號(1-" << count << ")"  << endl
         << "輸入0離開"; 

    while(true) { 
        cout << "\n學號? "; 
        cin >> number; 
        if(number == 0) 
            break; 
        else if(number > count) { 
            cout << "輸入學號(1-" << count << ")" << endl; 
            continue; 
        } 
                                                                                
        cout << "\n學號\t姓名\t\t分數" << endl; 
                                                                                
        fin.seekg((number - 1) * sizeof(Student)); 
        fin.read(reinterpret_cast<char*> (&student), 
            sizeof(Student)); 
        cout << student.studyNumber << "\t" 
             << student.name << "\t\t" 
             << student.score << endl; 
    } 

    fin.close(); 

    return 0; 
}

/*

在判斷資料筆數時還有更簡單的方法，就是開啟檔案後先使用ios::end將指標移至檔案尾，
然後使用tellg()得到目前的檔案指標位置，再除以資料結構的大小除可得知資料筆數，例如： 
file.seekg(0, ios::end); 
count = file.tellg() / sizeof(資料結構); 
*/