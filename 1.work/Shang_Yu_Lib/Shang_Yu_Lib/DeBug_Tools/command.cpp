
//#include "command.h"
#ifndef _applay_entry_H
#include "..\\applay_entry.h"
#endif
#include "command_func.h"
bool command_line_run(std::string a,std::string b)
{
	if(a.length()==b.length())
	{
		for(ULONG i=0;i< (a.length());i++)
		{
			if(a.c_str()[i]!=b.c_str()[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
std::string command_line_intput()
{
	 char c;
	 std::string str;

       // std::cin >> str;
	//	 cin>>lpu;
	//	  str=lpu;
	    str = "";
		while(true)
		{
			c = fgetc(stdin);
			if (c == '\n')
			{
				break;
			}
		    else
			{
				str += c;
			}						
		}
		return str;
}
