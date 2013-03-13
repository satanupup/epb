//---------------------------------------------------------------------------
//
// RetrievalThread.h
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//              Provides an interface for handling queued items
//
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------

#if !defined(_RETRIEVALTHREAD_H_)
#define _RETRIEVALTHREAD_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------
#include "CustomThread.h"

//---------------------------------------------------------------------------
//
// Forward declarations
//
//---------------------------------------------------------------------------

class CQueueContainer;

//---------------------------------------------------------------------------
//
// class CRetrievalThread
//
//---------------------------------------------------------------------------

class CRetrievalThread: public CCustomThread  
{
public:
	CRetrievalThread(
		TCHAR*           pszThreadGuid,
		CQueueContainer* pQueue
		);
	virtual ~CRetrievalThread();
private:
	//
	// A pointer to the queue object
	//
	CQueueContainer* m_pQueue;
protected:
	//
	// A user supplied implementation of the thread function.
	// Override Run() and insert the code that should be executed when 
	// the thread runs.
	//
	virtual void Run();
};

#endif // !defined(_RETRIEVALTHREAD_H_)
//----------------------------End of the file -------------------------------