#include <iostream> 
using namespace std; 

class Point { 
    int x, y; 
public: 
    Point() { 
        x = y = 0; 
    } 

    Point(int x, int y) { 
        this->x = x; 
        this->y = y; 
    } 

    friend istream &operator>>(istream &s, Point &p); 
    friend ostream &operator<<(ostream &s, Point p); 
}; 

istream &operator>>(istream &s, Point &p) { 
    cout << "¿é¤JÂI®y¼Ð: "; 
    s >> p.x >> p.y; 
    return s; 
} 

ostream &operator<<(ostream &s, Point p) { 
    s << "("<< p.x << ", " << p.y << ")"; 
    return s; 
} 

int main() { 
    Point p1; 

    cin >> p1; 
    cout << "p1: " << p1 << endl; 
	
	system("pause");  
    return 0; 
} 