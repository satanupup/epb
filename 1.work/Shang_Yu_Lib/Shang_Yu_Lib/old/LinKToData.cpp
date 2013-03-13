
#include <winsock2.h>
#include "applay_entry.h"
#include <epb_BoostClass.h>
#include <epb_Container.h>
#include <boost/filesystem.hpp>



bool soft_install_check(std::string softname)
{	
	
	Sleep(100);
	//範例 soft_install_check("C:\\c++");  會判斷整個路徑
	int bb = epb::Container::a_multimap::AppCount.size();
	bool abc = false;

	//MessageBox(NULL, wTmp.c_str() ,"這是這是這是這是這是這是這是這是這是這是這是這是這是這是判斷local是否存在的地方 GG2 應該要印兩次" , MB_OK);
	
	for(int i=0 ; i < bb ; i++)
	{	
		MessageBoxA(NULL, "ccccccccccccc" ,epb::Container::a_multimap::AppCount[i].second.c_str() , MB_OK);
		if(softname == epb::Container::a_multimap::AppCount[i].second.c_str())		
		{							
		//	MessageBox(NULL, softname.c_str() ,"軟體路徑列表中有這個軟體目錄" , MB_OK);
			boost::filesystem::path p( softname.c_str() );
			if( exists( p ) && is_directory( p ) )
			{				
		//		MessageBox(NULL, softname.c_str() ,"local有此目錄" , MB_OK);	
				abc = true;
			}
			else
			{
				MessageBox(NULL, softname.c_str() ,"local沒有此目錄" , MB_OK);	
			}		
		}
		else
		{				
			//MessageBox(NULL, softname.c_str() ,"沒有這個軟體目錄" , MB_OK);				
		}
	}

	return abc;
}
bool reg_Check()
{
	return true;
}

bool network_check()
{
	//網路連結確認
	
		if(pinger::network_check_2 == true)
		{
			if(pinger::network_check == true)
			{
				return true;
			}
		}
		else
		{
			return false;
		}	
	//return true;
}

std::string softpath_get (std::string softname )
{
	//檔案路徑確認
	//取得smba的軟體資料夾路徑
	std::string hng;
		hng = "P:\\";		
		hng += softname.c_str();
		softname = hng;
		//MessageBox(NULL, softname.c_str() ,"Error" , MB_OK);
		return softname;
}
void MSG_show(std::string Msg)
{
	MessageBox(NULL, Msg.c_str() ,"Phancloud" , MB_OK);
	//訊息輸出
}