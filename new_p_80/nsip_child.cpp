//---------------------------------------------------------------------------

#include <vcl.h>
#include "FileClass.h"
#include "nsip.h"
#pragma hdrstop

#include "nsip_child.h"
#include <winsock.h>
#include "main.h"
#pragma package(smart_init)

__fastcall newscanip_child::newscanip_child(
                                            bool CreateSuspended,
                                            AnsiString ip,
                                            int port,
                                            mi_buffer_nsip *buffer
                                            )
        : TThread(CreateSuspended)
{
mi_port=port;
mi_ips=ip;
uk_buffer=buffer;


}
//---------------------------------------------------------------------------
void __fastcall newscanip_child::Execute()
{
mi_SocketOption *s=new mi_SocketOption;
SOCKET miSOCKET=s->CreateSocket();
uk_buffer[0].resultat=s->IniScan(mi_ips,uk_buffer[0].nport,miSOCKET);
closesocket(miSOCKET);
delete s;
uk_buffer[0].status=false;
}
//---------------------------------------------------------------------------
