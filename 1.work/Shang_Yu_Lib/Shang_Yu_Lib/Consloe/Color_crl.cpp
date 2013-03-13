		
#include "../applay_entry.h"



void dChangTextColor(WORD color, char *output)
{
				 WORD we;
				 CONSOLE_SCREEN_BUFFER_INFO cbd;//,cde;
				 HANDLE htdout = GetStdHandle(STD_OUTPUT_HANDLE);
				// printf("rrrrrr");
				 if(GetConsoleScreenBufferInfo(htdout , &cbd))
				 {
					 we = cbd.wAttributes;
				 }
				// RGB(212,138,10) ; ª÷¦â
				 SetConsoleTextAttribute(htdout, color);

				 printf("%s",output);
				  SetConsoleTextAttribute(htdout, we);
				/* //ChangeTextColor()
				 SetConsoleTextAttribute(htdout,FOREGROUND_RED|FOREGROUND_INTENSITY);
				 printf("FLASE\n");
				 SetConsoleTextAttribute(htdout,FOREGROUND_GREEN|FOREGROUND_INTENSITY);
				 printf("TURN\n");
				 SetConsoleTextAttribute(htdout,we);*/
}
