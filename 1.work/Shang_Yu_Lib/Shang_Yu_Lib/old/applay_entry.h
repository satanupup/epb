#include <iostream>
#include <stdio.h>
#include <stdlib.h>



#include <string>
#include <io.h>
#include <windows.h>
bool soft_install_check(std::string softname);
bool reg_Check();
void all_work(std::string softname,std::string chack_catah);
//客戶端開始
bool network_check();
void MSG_show(std::string Msg);

std::string softpath_get (std::string softname );
//應用層訊息反饋

int soft_list(std::string list[] ,int item_num);

typedef struct Test_intput_msg
{
	std::string a1;
	std::string a2;

}Test_intput_msg;

typedef struct test_output_msg
{
	std::string o1;
}Test_output_msg;

Test_output_msg Debug_item(Test_intput_msg a);