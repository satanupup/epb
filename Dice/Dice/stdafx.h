// stdafx.h : 可在此標頭檔中包含標準的系統 Include 檔，
// 或是經常使用卻很少變更的
// 專案專用 Include 檔案
//

#pragma once

#define WIN32_LEAN_AND_MEAN             // 從 Windows 標頭排除不常使用的成員
// Windows 標頭檔:
#include <winsock2.h>
#include <windows.h>

// C RunTime 標頭檔
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <ctime>            // std::time

#include <atlbase.h>
#include <atlconv.h>

#include <CommCtrl.h>
#pragma comment(lib, "comctl32.lib")

#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

//
#include <boost/random/linear_congruential.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/generator_iterator.hpp>


#include <cstdlib>
#include <deque>
#include <boost/thread/thread.hpp>
#include "chat_message.hpp"


//#include "epb_BearLib.h"
//#include "epb_SendMessageGetString.h"

#include <Shlobj.h>
#include <assert.h>
#include <strsafe.h>

#pragma   comment(lib,"mpr")

using namespace std;
// TODO: 在此參考您的程式所需要的其他標頭
