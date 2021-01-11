//---------------------------------------------------------------------------

#include <vcl.h>
#pragma comment(lib, "netapi32.lib")
//#pragma comment(lib, "mpr.lib")
//#pragma comment(lib, "ws2_32.lib")
#pragma hdrstop


#include <lm.h>
#include "pr.h"
#include "FileClass.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tresursi *resursi;

TTreeNode *node;

//---------------------------------------------------------------------------
__fastcall Tresursi::Tresursi(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Tresursi::GetNetResurs(AnsiString names,AnsiString ima)
{
   PSHARE_INFO_1  BufPtrS,pS;
   NET_API_STATUS res;
   DWORD er=0,tr=0,resume=0, i;
   AnsiString s;
   s=names; s=s+" - "+ima;


node=TLogos->Items->AddFirst(NULL,s);
node->SelectedIndex=1;
node->ImageIndex=0;
            
Application->ProcessMessages();
   do
   {
      res = NetShareEnum
                       (
                      StringToOleStr(names),
                      1,
                       (LPBYTE *) &BufPtrS,
                        -1,
                        &er,
                        &tr,
                        NULL
                        );

      if(res == ERROR_SUCCESS || res == ERROR_MORE_DATA)
      {
      if(er<=0)return;

         pS=BufPtrS;

    //     ma->logos->Lines->Add(er);
    //     return;
         for(i=0;i<er;i++)
         {
         Application->ProcessMessages();
    //        ma->logos->Lines->Add(pS->shi1_netname);
TTreeNode *c_node=TLogos->Items->AddChild(node,pS->shi1_netname);
  int ris=2;

if(((String)pS->shi1_netname).Length()==2)ris=7;

c_node->ImageIndex=ris;
c_node->SelectedIndex=ris;
         pS++;
         }
         NetApiBufferFree(BufPtrS);
      }
      else

{
TTreeNode *e_node=TLogos->Items->AddChild(node,"Ошибка - "+IntToStr(res));
e_node->ImageIndex=6;
e_node->SelectedIndex=6;
}
Application->ProcessMessages();
 }
      while (res==ERROR_MORE_DATA);

      GetDomain(names);
   return;
}

void __fastcall Tresursi::stClick(TObject *Sender)
{
     info *test=new info;
     if(test->TestIp(e_ip->Text)==false)
                                      {
                                      MessageBox(0,"Неверный стартовый адрес","ERROR",0);
                                      delete test;
                                      return;
                                      }

 //test->GetIpName(e_ip->Text);
 //if(test->mi_name.Length()==0)
   //                                   {
     //                                 delete test;
       //                               st->Enabled=true;
         //                             return;
           //                           }

  //  logos->Lines->Add(test->mi_name.Length());
     st->Enabled=false;
     AnsiString w=test->mi_name;
     w=e_ip->Text;

     delete test;


GetNetResurs(e_ip->Text,w);
st->Enabled=true;
}
//---------------------------------------------------------------------------

void Tresursi::GetDomain(AnsiString ima)
                                 {
unsigned char *Buffer;
DWORD size=255;

    int err;
    DWORD PrefMaxLen=-1;
    DWORD EnteriesRead=0;
    DWORD TotalEnteries=0;
    DWORD ResumeHandle=0;

   wchar_t *names;
 //  StringToWideChar(ima,names,ima.Length()+1);
    err=NetWkstaUserEnum(
                    StringToOleStr(ima),
                    1,
                    &Buffer,
                    PrefMaxLen,
                    &EnteriesRead,
                    &TotalEnteries,
                    &ResumeHandle
                    );


       if ((err == NERR_Success) || (err == ERROR_MORE_DATA))
                    {

       if(TotalEnteries<=0)return;
                    WKSTA_USER_INFO_1 *mi_buffer=(WKSTA_USER_INFO_1*)Buffer;

              for(int i=0;i<TotalEnteries;i++)
                    {
                    Application->ProcessMessages();
TTreeNode *u_node=TLogos->Items->AddChild(node,mi_buffer->wkui1_username);
u_node->ImageIndex=3;
u_node->SelectedIndex=3;
//
                    mi_buffer++;

                    }

                    }


NetApiBufferFree(Buffer);
                                 }





