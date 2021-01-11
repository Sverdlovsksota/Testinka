//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "nsip.h"
#include "FileClass.h"
#include "main.h"
#include "nsip_child.h"
#pragma package(smart_init)
  mi_buffer_nsip mi_ust[1024];
__fastcall newscanip::newscanip(
                                bool CreateSuspended,
                                bool ust_array[],
                                AnsiString ip,
                                int start_port
                                )
                                : TThread(CreateSuspended)
{
 mi_ip=ip;
 for(int i=0;i<1024;i++)
                        {
                         Application->ProcessMessages();
                         mi_ust[i].for_scan=ust_array[i];
                         mi_ust[i].status=false;
                         mi_ust[i].uk=NULL;
                        }

}

//---------------------------------------------------------------------------
void __fastcall newscanip::Execute()
{
int i=0;
for(i=0;i<1024;i++)
                  {
                  if(mi_ust[i].for_scan==true)
                  {
                  Application->ProcessMessages();
//---------------------------------------------------------------------------
                  newscanip_child *mi_child=new newscanip_child(
                  true,
                  mi_ip,
                  i,
                  (struct mi_buffer_nsip *)&mi_ust[0+i]
                                                               );
                  mi_child->FreeOnTerminate=true;
                  mi_ust[i].status=true;
                  mi_ust[i].uk=mi_child;
                  mi_ust[i].mi_time=GetTickCount();
                  mi_ust[i].resultat=false;
                  mi_ust[i].nport=i;
                  mi_child->Resume();
//---------------------------------------------------------------------------
                  }
                  }
int status_plus=0;
int l;
DWORD mi_timers=GetTickCount();
Sleep(1000);
//ma->logos->Lines->Add("status "+BoolToStr(mi_ust[0].status));

do{
status_plus=0;
for(l=0;l<1024;l++)
                  {
                  Application->ProcessMessages();
                  if(mi_ust[l].status==true)status_plus++;
                  }
Application->ProcessMessages();
               //  ma->logos->Lines->Add("status "+BoolToStr(mi_ust[0].status));
}while(status_plus!=0);
AnsiString st=mi_ip+" [ ";
int tests=0;
for(i=0;i<1024;i++)
                  {
                  if(mi_ust[i].for_scan==true)
                                             {
                  if(mi_ust[i].resultat==true){tests++;st=st;st=st+IntToStr(mi_ust[i].nport)+" ";}

                                             }

                  }
                  if(tests!=0)
                  ma->logos->Lines->Add(st+"]");
                  Terminate();
}

