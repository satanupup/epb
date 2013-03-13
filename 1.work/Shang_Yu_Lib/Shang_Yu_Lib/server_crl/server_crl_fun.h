
#define _server_crl_fun_H
BOOL CreatrServic(SC_HANDLE schmang , LPSTR szpath,LPSTR servername , LPSTR showname);
BOOL DeleteService( SC_HANDLE schmang,LPSTR ServiceName );

BOOLEAN EnumService();
BOOLEAN StopService ();
BOOLEAN StaetService(SC_HANDLE sc ,LPTSTR ServiceName);