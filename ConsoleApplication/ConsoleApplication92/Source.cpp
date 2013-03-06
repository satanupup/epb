// string::copy
#include <iostream>
#include <string>
using namespace std;
int main ()
{
  char buffer[20];
  std::string  str ("Test string...");  
  int length = str._Copy_s(buffer,6,5);
  buffer[length]='\0';
  std::cout << "buffer contains: " << buffer << '\n';
  system("pause");
  return 0;
}