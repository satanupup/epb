//---------------------------------------------------------------------------
//
// LockMgr.cpp
//
// SUBSYSTEM: 
//				Generic libraries
//通用庫
// MODULE:    
//              Interface declaration of CCSWrapper CRITICAL_SECTION wrapper 
//接口的CCSWrapper CRITICAL_SECTION的包裝聲明
//
// DESCRIPTION:
//              
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------
#include "LockMgr.h"

//---------------------------------------------------------------------------
//
// class CCSWrapper 
//
// CRTICIAL_SECTION user object wrapper
// CRTICIAL_SECTION的用戶對象包裝
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
// Constructor
//
//---------------------------------------------------------------------------
CCSWrapper::CCSWrapper()
{
	m_nSpinCount = 0;
	::InitializeCriticalSection( &m_cs );
}

//---------------------------------------------------------------------------
//
// Destructor
//
//---------------------------------------------------------------------------
CCSWrapper::~CCSWrapper()
{
	::DeleteCriticalSection( &m_cs );
}


//---------------------------------------------------------------------------
// Enter 
//
// This function waits for ownership of the specified critical section object 
//這個函數等待指定的臨界區對象的所有權
//---------------------------------------------------------------------------
void CCSWrapper::Enter()
{
	::EnterCriticalSection( &m_cs );
	m_nSpinCount++;
}

//---------------------------------------------------------------------------
// Leave
//
// Releases ownership of the specified critical section object. 
//發布指定的臨界區對象的所有權。
//---------------------------------------------------------------------------
void CCSWrapper::Leave()
{
	m_nSpinCount--;
	::LeaveCriticalSection( &m_cs );
}

//--------------------- End of the file -------------------------------------
