//---------------------------------------------------------------------------
//
// Common.h
//
// SUBSYSTEM:   
//              Monitoring process creation and termination  
//				
// DESCRIPTION: Common header 
//             
// AUTHOR:		Ivo Ivanov
//
//---------------------------------------------------------------------------
#if !defined(_COMMON_H_)
#define _COMMON_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//-----------------------Windows Version Build Option -----------------------

//#define _WIN32_WINNT 0x0500

//---------------------------Unicode Build Option ---------------------------

// To compile using Unicode on the x86 CPU, uncomment the line below.

#define UNICODE

// When using Unicode Windows functions, use Unicode C-Runtime functions too.
#ifdef UNICODE
#define _UNICODE
#endif

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include <windows.h>


//---------------------------------------------------------------------------
//
// struct _QueuedItem
//
//---------------------------------------------------------------------------
typedef struct _QueuedItem  
{
	HANDLE  hParentId;
    HANDLE  hProcessId;
    BOOLEAN bCreate;
} QUEUED_ITEM, *PQUEUED_ITEM;


#endif // !defined(_COMMON_H_)

//--------------------- End of the file -------------------------------------
