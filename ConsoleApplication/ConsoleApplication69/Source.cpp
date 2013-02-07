
#include <iostream> 
#include <fstream> 
using namespace std; 
/*
在C+ +中使用兩個指標來操作檔案，一個是 get 指標，它會指向檔案中下一個輸入讀取的位置，另一個是 put 指標，
它會指向檔案中下一個輸出寫入的位置，這兩個指標在每一次讀取或寫入時，都會循序的往下一個位置移動，
我們可以使用seekg()來操作 get 指標，使用seekp()來操作 put 指標，令檔案作非循序的存取。 

seekg()與seekp()的函式雛型如下： 
istream &seekg(off_type type, seekdir origin); 
ostream &seekg(off_type, seekdir origin); 


其中off_type是ios所定義的整數型態，通常是一個long整數，而seekdir則是由ios所定義的列舉值，如下： 
ios::beg	由檔案首seek
ios::cur	由目前的位置seek
ios::end	由檔案尾端seek
seekg()與seekp()若不指定seekdir，則由目前的位置開始，我們也可以由tellg()或tellp()來得到目前 get 指標與 put 指標的位置： 
pos_type tellg() 
pos_type tellp() 


要進行非循序的檔案存取，通常會使用二進位模式，並且將資料以一定大小的資料結構包裝起來，
下一個主題就會看到，但操作 get 指標對循序性的檔案也有其好處，
例如我們可以在文字檔案中儲存學生的資料並進行查詢，查詢的動作並不一定經過一次，
所以我們可以在每次查詢後，將get指 標移至檔案首，以便再次查詢，下面這個程式是個簡單的示範： 
*/
int main() { 
    ifstream fin("C:\\c++\\epbgit\\ConsoleApplication\\Debug\\out\\data.txt"); 
    if(!fin) { 
        cout << "無法讀取檔案\n"; 
        return 1; 
    } 

    char name[30]; 
    int request, account, score; 

	
    cout << "輸入選項:" << endl
         << "1) 顯示所有學生與分數" << endl
         << "2) 顯示及格學生與分數" << endl
         << "3) 顯示不及格學生與分數" << endl
         << "4) 離開" << endl;
	
    while(true) { 
        cout << "\n選項? "; 
        cin >> request; 
        if(request == 4) 
            break; 

        switch(request) { 
            case 1: 
                cout << "\n所有學生與分數:" << endl;
                break; 
            case 2: 
                cout << "\n及格學生與分數:" << endl;
                break; 
            case 3: 
                cout << "\n不及格學生與分數:" << endl;
                break; 
			default:
				break;
        } 
		
	std::system("cls");
    cout << "輸入選項:" << endl
         << "1) 顯示所有學生與分數" << endl
         << "2) 顯示及格學生與分數" << endl
         << "3) 顯示不及格學生與分數" << endl
         << "4) 離開\n" << endl;
	

        fin >> account >> name >> score; 
        while(!fin.eof()) { 
            if((request == 1) || (request == 2 && score >= 60) || 
               (request == 3 && score < 60)) 
                cout << account << "\t" << name << "\t" << score << endl; 

            fin >> account >> name >> score; 
        } 

        fin.clear();  // 重置 eof 
        fin.seekg(0);  // get 指標移至檔案首 
    } 

    fin.close(); 
	std::system("pause");

    return 0; 
}


/*
如果data.txt的檔案內容如下： 
 1       Justin  90 
2       Momor   90 
3       Bush    75 
4       John    50 
5       Bob     65 
6       Rich    53 
7       Doe     41 
8       Bill    85 
9       Jason   67 
10      Jones   88

//

為何文字檔案不適合非循序存取，理由很簡單，文字檔案的內容都經過字元轉換，假設現在有個檔案中有兩筆資料如下，其中空白為'\t'： 
1       Justin  90 
2       Momor   90 


如果現在我更改了第一筆資料如下： 
1       caterpillar  90 


則第二筆資料會被覆蓋，如果是在Linux下，換行為'\n'，則結果會如下： 
1       caterpillar  90or   90 

由於字元轉換後的資料長度並不固定，所以文字檔案並不適合非循序存取。 
*/