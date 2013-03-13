//---------------------------------------------------------------------------
//
// QueueContainer.h
//
// SUBSYSTEM: 
//              Monitoring process creation and termination  
//				
// MODULE:    
//              Implement a multithreaded thread safe queue
// 
// DESCRIPTION:
//
// AUTHOR:		Ivo Ivanov
//                                                                         
//---------------------------------------------------------------------------

#if !defined(_QUEUECONTAINER_H_)
#define _QUEUECONTAINER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//---------------------------------------------------------------------------
//
// Includes
//
//---------------------------------------------------------------------------

#include "common.h"
#include "CallbackHandler.h"
#include "RetrievalThread.h" 
#include <assert.h>
#include <deque>
using namespace std;
//---------------------------------------------------------------------------
//
// class CQueueContainer
//
//---------------------------------------------------------------------------
class CQueueContainer
{
public:
	CQueueContainer(CCallbackHandler* pHandler);
	virtual ~CQueueContainer();
	//
	// Initates the process of handling notification
	//
	BOOL StartReceivingNotifications();
	//
	// Shutdown if there is something in progress
	//
	void StopReceivingNotifications();
	//
	// Insert data into the queue
	//
	BOOL Append(const QUEUED_ITEM& element);
	//
	// A method for accessing handle to an internal event handle
	//
	HANDLE Get_ElementAvailableHandle() const;
	//
	// Get data from the kernel mode driver
	//
	void WaitOnElementAvailable();
	//
	// Set an external parameter, thus we could take the advantage 
	// of it later on in the callback routine
	//
	void SetExternalParam(PVOID pvParam);
	//
	// Delegate this method to a call of CCallbackHandler 
	//
	void OnProcessEvent(PQUEUED_ITEM pQueuedItem);
private:
	//
	// Initialize the system
	//
	void Init();
	//
	// Release all allocated resources
	//
	void Done();
	//
	// Implement specific behavior when kernel mode driver notifies the user-mode app
	//
	void DoOnProcessCreatedTerminated();
	//
	// Thread that gets all queued event items 
	//
	CRetrievalThread* m_pRetrievalThread;
	//
	// Event which is signaled when there is available element
	// in the queue to be retrieved
	//
	HANDLE m_evtElementAvailable;
	//
	// An event for shutting down the remove action
	//
	HANDLE m_evtShutdownRemove;
	//
	// Underlying STL container
	//
	deque<QUEUED_ITEM> m_Queue;
	//
	// Monitor mutex
	//
	HANDLE m_mtxMonitor;
	//
	// Callback handler
	//
	CCallbackHandler* m_pHandler;
	//
	// Pointer to anything
	//
	PVOID m_pvParam;
};

#endif // !defined(_QUEUECONTAINER_H_)
//----------------------------End of the file -------------------------------