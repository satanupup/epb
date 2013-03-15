#include <iostream> 
#include "SafeArray.h"
#include "Exception.h"
#include "ArrayIndexOutOfBoundsException.h"
using namespace std; 

int main() {

	SafeArray<int> safeArray1(10);
	SafeArray<double> safeArray2(10);
	SafeArray<char> safeArray3(10);
	try {
		char bb[10] = "apple";
		for(int i = 0; i < safeArray3.length; i++) {
			safeArray3.set(i,bb[i]);
		}

		for(int i = 0; i < safeArray3.length; i++) {
			cout << safeArray3.get(i) << " ";
		}

		cout << endl;


		//
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