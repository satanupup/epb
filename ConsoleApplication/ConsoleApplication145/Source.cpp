#include <iostream> 
#include "SafeArray.h"
#include "Exception.h"
#include "ArrayIndexOutOfBoundsException.h"
using namespace std; 

int main() {
	
    SafeArray<int> safeArray1(10);
    SafeArray<double> safeArray2(10);
 
    try {
        for(int i = 0; i < safeArray1.length; i++) {
            safeArray1.set(i, (i + 1) * 10);
        }
 
        for(int i = 0; i < safeArray1.length; i++) {
            cout << safeArray1.get(i) << " ";
        }

        cout << endl;

        for(int i = 0; i < safeArray2.length; i++) {
            safeArray2.set(i, (i + 1) * 0.1);
        }
 
        for(int i = 0; i < safeArray2.length; i++) {
            cout << safeArray2.get(i) << " ";
        }
 
        cout << endl;
    }
    catch(ArrayIndexOutOfBoundsException e) {
        cout << endl
             << e.message()
             << endl;
		
    }
    catch(Exception e) {
        cout << endl
             << e.message()
             << endl;
    }
 system("pause");
    return 0; 
} 