//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pina.h"
#include "main.h"
#include "FileClass.h"
#pragma package(smart_init)

#define pr(x)  ma->logos->Lines->Add(x);

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

__fastcall pina::pina(bool CreateSuspended,
                      AnsiString ip,
                      int nomer,
                      bool status,
                      int kol,
                      bool GetName)
        : TThread(CreateSuspended)

{
       miIP = ip;
       minomer = nomer;
       Status = status;
       mikol = kol;
       miGetName = GetName;
   //    hIcmp=ma->_hIcmp;
}
//---------------------------------------------------------------------------
void __fastcall pina::Execute()
{
bool result;

ma->IncScan();
result=SendPing((char*)miIP.c_str());

EnterCriticalSection(&ma->ds);
ma->PinOtvet[minomer].ips=miIP;
if(result==false)ma->PinOtvet[minomer].tipa=1;
else
ma->PinOtvet[minomer].tipa=2;
LeaveCriticalSection(&ma->ds);
if(miGetName==true)
{

info *f=new info;
if(f->GetIpName(miIP)==true)ma->PinOtvet[minomer].names=f->mi_name;
delete f;
}
ma->DecScan();
Terminate();
}
//---------------------------------------------------------------------------

bool pina::SendPing(char* AddressIP )
{

int result=false;
hIcmp = LoadLibrary("ICMP.DLL");
if( hIcmp == 0 )
{
return (result);
}


struct hostent* phe;
//MessageBox(0,AddressIP,"",0);
if( ( phe = gethostbyname( AddressIP ) ) == 0 )
{
return (result);
}

typedef HANDLE (WINAPI* pfnHV)(VOID);
typedef BOOL (WINAPI* pfnBH)(HANDLE);
typedef DWORD (WINAPI* pfnDHDPWPipPDD)(HANDLE, DWORD, LPVOID, WORD, PIP_OPTION_INFORMATION, LPVOID, DWORD, DWORD);

pfnHV pIcmpCreateFile;
pfnBH pIcmpCloseHandle;
pfnDHDPWPipPDD pIcmpSendEcho;

pIcmpCreateFile = (pfnHV)GetProcAddress( hIcmp, "IcmpCreateFile" );
pIcmpCloseHandle = (pfnBH)GetProcAddress( hIcmp, "IcmpCloseHandle" );
pIcmpSendEcho = (pfnDHDPWPipPDD)GetProcAddress( hIcmp,"IcmpSendEcho" );
if( ( pIcmpCreateFile == 0 ) || ( pIcmpCloseHandle == 0 ) || ( pIcmpSendEcho == 0 ) )
{

FreeLibrary( hIcmp );
return(result)  ;
}

HANDLE hIP = pIcmpCreateFile();
if( hIP == INVALID_HANDLE_VALUE )
{

FreeLibrary( hIcmp );
return(result) ;
}

char acPingBuffer[64];
memset( acPingBuffer, '\xAA', sizeof( acPingBuffer ) );
PIP_ECHO_REPLY pIpe = (PIP_ECHO_REPLY)GlobalAlloc( GMEM_FIXED | GMEM_ZEROINIT, sizeof( IP_ECHO_REPLY ) + sizeof( acPingBuffer ) );
if( pIpe == 0 )
{
GlobalFree( pIpe );
FreeLibrary( hIcmp );
return (result);
}


pIpe->Data = acPingBuffer;
pIpe->DataSize = sizeof( acPingBuffer );

DWORD dwStatus = pIcmpSendEcho( hIP, *( (DWORD*)phe->h_addr_list[0] ), acPingBuffer, sizeof( acPingBuffer ), NULL, pIpe, sizeof( IP_ECHO_REPLY ) + sizeof( acPingBuffer ), 5000 );
if( dwStatus != 0 )
{
if(Status==true)
{
AnsiString st=IntToStr(minomer);
st=st+".   ";st=st+"[";
st=st+int(LOBYTE(LOWORD(pIpe->Address)));st=st+".";
st=st+int(HIBYTE(LOWORD(pIpe->Address)));
st=st+".";st=st+int(LOBYTE(HIWORD(pIpe->Address)));
st=st+".";st=st+int(HIBYTE(HIWORD(pIpe->Address)));st=st+"]  ";
st=st+"Time: " ;st=st+ int(pIpe->RoundTripTime);
st=st+" ms  ";st=st+"TTL: ";st=st+ int(pIpe->Options.Ttl);

ma->OutLogo(st.c_str());
}
result=true;
}
else
{
}

GlobalFree( pIpe );
FreeLibrary( hIcmp );
return (result);
}






