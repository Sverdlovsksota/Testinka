//---------------------------------------------------------------------------

#include <vcl.h>
#include <winsock.h>
#include <windows.h>
#pragma hdrstop

#include "main.h"
#include "FileClass.h"

#include "pina.h"
#include "scan.h"
#include "tracert.h"
#include "sniffer1.h"

#include "contr.h"
#include "pr.h"
     #include "Ustanovka_ip.h"
     #include "nsip.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define pr(x) logos->Lines->Add(x)


Tma *ma;
       snif *_snif;
       bool snif_ok=false;

LRESULT CALLBACK NewWindowProc(HWND hWnd, UINT msg, WPARAM w,LPARAM l);
//---------------------------------------------------------------------------
__fastcall Tma::Tma(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tma::FormCreate(TObject *Sender)
{
WSADATA wsaData;

int err=WSAStartup(101, &wsaData);
if(err!=0)pr("Библиотека не инициализированна");

OldWindowProc = (WNDPROC)SetWindowLong(Application->Handle,
                         GWL_WNDPROC, (long)NewWindowProc);
InitializeCriticalSection(&cs);
InitializeCriticalSection(&ds);
InitializeCriticalSection(&ss);
InitializeCriticalSection(&sl);
PinOtvet=new miOtvet[300];
ColPinReal=0;
 //_hIcmp = LoadLibrary("ICMP.DLL");


}
//---------------------------------------------------------------------------
void Tma::DecPing()
{
EnterCriticalSection(&cs);
ColPinReal--;
LeaveCriticalSection(&cs);

return;
}
void Tma::IncPing()
{
EnterCriticalSection(&cs);
ColPinReal++;
Plus++;
LeaveCriticalSection(&cs);

return;
};
int Tma::Rea()
{
EnterCriticalSection(&cs);
int result=ColPinReal;
LeaveCriticalSection(&cs);
return(result);
}
void __fastcall Tma::FormDestroy(TObject *Sender)
{


DeleteCriticalSection(&cs);
DeleteCriticalSection(&ds);
DeleteCriticalSection(&ss);
DeleteCriticalSection(&sl);
SetWindowLong(Application->Handle, GWL_WNDPROC, (long)OldWindowProc);
WSACleanup();
//  delete _hIcmp;// = LoadLibrary("ICMP.DLL");
}


 LRESULT CALLBACK NewWindowProc(HWND hWnd, UINT msg, WPARAM w,LPARAM l)
{
//if(msg==WM_CLOSE){MessageBox(0,"?","?",0);return(true);}
//int port=(unsigned)msg-WM_USER;
//ma->pr(msg);
//if(StrToInt(ma->port_start->Text)<=port)
//                             {
//                             if(StrToInt(ma->port_end->Text)>=port)
//                             {
//ma->pr(port);
//if(msg==WM_USER+100)         //------------------------------ сообщения серверу


//switch ((char)l)

//{
//case FD_CONNECT  : {ma->pr("connect  "+IntToStr(port));}



//case FD_READ     : {}

//case FD_CLOSE    : {};//{ma->pr("close "+IntToStr(port));}

//}
//                                }}
return CallWindowProc((FARPROC)ma->OldWindowProc, hWnd, msg, w, l);
}
//---------------------------------------------------------------------------
void __fastcall Tma::Button6Click(TObject *Sender)
{
mi_pin();
}

bool Tma::mi_pin()
                 {
                 AnsiString s=TrimRight(ip->Text);
info *test=new info;
if (test->TestIp(s)==false)
                          if(test->GetNameIp(s)==true)s=test->list[0];
                          else
                          {
                          MessageBox(0,"Ошибка ввода адреса","error",0);
                          return false;
                          }
delete test;
pina *ping=new pina(true,s,0,true,1,false);
ping->FreeOnTerminate=true;
ping->Resume();
                 return true;
                 }

//---------------------------------------------------------------------------
void __fastcall Tma::skanClick(TObject *Sender)
{
AnsiString s=ip->Text;
info *test=new info;
if(test->TestIp(s)==false){
                          MessageBox(0,"Неверный стартовый адрес","ERROR",0);
                          delete test;
                          return;
                          }
BYTE ip_start[4];
memcpy((BYTE*)&ip_start[0],(BYTE*)&test->CIP[0],4);
                          delete test;
int i,j;
try
{
i=StrToInt(end_ip->Text);
}
catch(...)
{
MessageBox(0,"Неверный стартовый адрес","ERROR",0);
return;
}
if(ip_start[3]>i){
               MessageBox(0,"Неверный стартовый адрес","ERROR",0);
               return;
               }
int con=i-ip_start[3];
int pos=ip_start[3];
AnsiString addr,miaddr;
addr=IntToStr(ip_start[0]);
addr=addr+".";
addr=addr+IntToStr(ip_start[1]);
addr=addr+".";
addr=addr+IntToStr(ip_start[2]);
addr=addr+".";

ColPinReal=0;

Plus=0;
bar->Max=con;
bar->Min=0;
bar->Position=0;


for(int del=0;del<con;del++)
                            {
                            PinOtvet[del].tipa=0;
                            PinOtvet[del].names="";
                            PinOtvet[del].ips="";
                            }

skan->Enabled=false;
pr("Проверка ответа хостов в заданном диапазоне...");

bool name=GetName->Checked;

for(int cikl=0;cikl<=con;cikl++)
{
miaddr=addr;
miaddr=miaddr+IntToStr(pos);
pina *p=new pina(true,miaddr,pos,false,0,name);
     p->FreeOnTerminate=true;
     p->Resume();
     bar->Position++;
pos++;
Application->ProcessMessages();
}
DWORD d=GetTickCount();
do
{
Application->ProcessMessages();
bar->Position=ReaScan();
}while((GetTickCount()-d)<1000);

do
{
Application->ProcessMessages();
Sleep(1);
bar->Position=ReaScan();
}while(ReaScan()!=0);

pr("Сканирование заданного диапазона окончено...");

int pos_buffer=ip_start[3];
do
{
if(PinOtvet[pos_buffer].tipa==2)
                               {
                               AnsiString name=PinOtvet[pos_buffer].ips;
                               name=name+"\t";
                               name=name+PinOtvet[pos_buffer].names;
                               pr(name);

                               }
pos_buffer++;
Application->ProcessMessages();
}while(pos_buffer<=i);

skan->Enabled=true;
bar->Position=0;
}
//---------------------------------------------------------------------------
void __fastcall Tma::gethostipClick(TObject *Sender)
{
AnsiString s=TrimRight(ip->Text);
info *test=new info;
if(test->GetNameIp(s)==false)
                             {
                             if(test->GetIpName(s)==true)
                             {
                             pr(test->mi_name);
                             int pos=0;
 AnsiString q;
 char *cq;
 do{
   cq=test->h->h_aliases[pos];
   q[pos+1]=(char )&cq;
      pos++ ;
   }while(cq!=0);
                             logos->Lines->Add(q);

                             ip->Text=test->mi_name;
                             }
                             else
                             MessageBox(
                                        0,
                                        "Неверно введено имя хоста",
                                        "error",
                                        0
                                        );
                              }

                            else
                            {
                            int con=test->cout_list;
if(con!=0)
         {
         for(int j=0;j<con;j++)pr(s+": "+test->list[j]);
         ip->Text=test->list[0];
         ip->Text=test->list[0];
         }
         else
         pr("IP адрес не получен");
                            }
                            delete test;
}

//---------------------------------------------------------------------------
void __fastcall Tma::Button5Click(TObject *Sender)
{
info *GetMac=new info;
TMemo *m;m=logos;
GetMac->GetInfoMac(m);
delete GetMac;
}
//---------------------------------------------------------------------------
void __fastcall Tma::spClick(TObject *Sender)
{

bool ports[500]; int tipscan=0; ZeroMemory((bool*)&ports[0],449);

if(C_mail->Checked==true){ports[25]=true;ports[110]=true;tipscan++;}
if(C_http->Checked==true){ports[80]=true;tipscan++;}
if(C_ftp->Checked==true){ports[21]=true;tipscan++;}
if(C_telnet->Checked==true){ports[23]=true;tipscan++;}
if(C_netbios->Checked==true){ports[135]=true;ports[139]=true;ports[445]=true;tipscan++;}

ColPinReal=0;
Plus=0;
bar->Max=445;
bar->Min=0;
bar->Position=0;

if(tipscan!=0)
              {
              sp->Enabled=false;
              pr("Старт сканирования...");
              for(int i=0;i<=445;i++)
              {
              Application->ProcessMessages();
              if(ports[i]==true)
              {
               scaner *sc=new scaner(true
                    ,ip->Text,i,i);
                    sc->FreeOnTerminate=true;
                    sc->Resume();
              }
              bar->Position++;
              }
              }
        else
            {
info *test=new info;
AnsiString s=port_start->Text,e=port_end->Text;
if(test->TestPorts(s,e)==false)
                              {
                               pr("Неверно высталенны порты для скана...");
                               delete test;
                               return;
                              }
if(test->TestIp(ip->Text)==false)
                              {
                              pr("Неверно выстален ip для скана...");
                              delete test;
                              return;

                              }
delete test;
int i_start=StrToInt(s),
i_end=StrToInt(e),
con=e-s;
sp->Enabled=false;
Panel3->Enabled=false;
int pos=StrToInt(port_start->Text);

                               pr("Старт сканирования...");
bar->Max=con;

     for(int j=0;j<i_end-i_start;j++){
     Application->ProcessMessages();
     Sleep(1);
                    scaner *sc=new scaner(true
                    ,ip->Text,pos,i_end);
                    sc->FreeOnTerminate=true;
                    sc->Resume();
                    bar->Position++;
                    pos++;

                     }
                     }
//-----------------------------------------------------------------------------
DWORD d=GetTickCount();
do
{
Application->ProcessMessages();
bar->Position=ReaScan();
}while((GetTickCount()-d)<1000);
//-----------------------------------------------------------------------------
int col=0;
do
{
col=ReaScan();
Application->ProcessMessages();
Sleep(1);
bar->Position=ReaScan();
}while(col!=0);

                             pr("Процесс сканированния окончен...");
Panel3->Enabled=true;
sp->Enabled=true;
}
//---------------------------------------------------------------------------
void Tma::DecScan()
{
EnterCriticalSection(&ss);
ColScanReal--;
LeaveCriticalSection(&ss);

}
void Tma::IncScan()
{
EnterCriticalSection(&ss);
ColScanReal++;
Plus++;
LeaveCriticalSection(&ss);
}
int Tma::ReaScan()
{
int i;
EnterCriticalSection(&ss);
i=ColScanReal;
LeaveCriticalSection(&ss);
return (i);
}

int Tma::ReaPlus()
{
int i;
EnterCriticalSection(&ss);
i=Plus;
LeaveCriticalSection(&ss);
return (i);
}



void __fastcall Tma::traceClick(TObject *Sender)
{
trace->Enabled=false;
TMemo *l=logos;
tracerts(l,ip->Text.c_str(),GetName->Checked);
trace->Enabled=true;
}
//---------------------------------------------------------------------------

void Tma::OutLogo(char *l)
{
EnterCriticalSection(&sl);
    logos->Lines->Add(l);
LeaveCriticalSection(&sl);
return;
}


void Tma::Controli ()
              {
              if(startscan==true){
                    startscan=false;
                    Application->ProcessMessages();
                    _snif->Terminate();
                    delete _snif;
                    snif_ok=false;
                    Kontrol->Caption="Контроль";
                    Panel6->Enabled=true;
                    }
                    else
                    {
 //                   int ret=MessageBox(NULL,"Создать базу данных ?","Запрос...",MB_YESNOCANCEL);
 // if(ret==IDCANCEL)return;
 //if(ret==IDYES){}
 //if(ret==IDNO){}

                    startscan=true;
                    TMemo *m=cont->c_logos;//logosa;
                    BYTE f[256]; FillMemory(&f,sizeof(f),0);
if(C_tcp->Checked==true)
                    {
                    f[6]=0x01;
                    if(tcp_self->Checked!=true)SetTcp();
                    else
                    {
                    f[6]=f[6]^0x02;
                    if(tcp_in->Checked==true)f[6]=f[6]^0x04;
                    if(tcp_out->Checked==true)f[6]=f[6]^0x08;
                    if(f[6]<=0x03){f[6]=0;C_tcp->Checked=false;}
                    }
                    }
if(C_icmp->Checked==true)
                    {
                    f[1]=0x01;
                    if(icmp_self->Checked!=true)SetIcmp();
                    else
                    {
                    f[1]=f[1]^0x02;
                    if(icmp_in->Checked==true)f[1]=f[1]^0x04;
                    if(icmp_out->Checked==true)f[1]=f[1]^0x08;
                    if(f[1]<=0x03){f[1]=0;C_icmp->Checked=false;}
                    }
                    }
if(C_igmp->Checked==true)
                    {
                    f[2]=0x01;
                    if(igmp_self->Checked!=true)SetIgmp();
                    else
                    {
                    f[2]=f[2]^0x02;
                    if(igmp_in->Checked==true)f[2]=f[2]^0x04;
                    if(igmp_out->Checked==true)f[2]=f[2]^0x08;
                    if(f[2]<=0x03){f[2]=0;C_igmp->Checked=false;}
                    }
                    }
if(C_udp->Checked==true)
                    {
                    f[17]=0x01;
                    if(udp_self->Checked!=true)SetUdp();
                    else
                    {
                    f[17]=f[17]^0x02;
                    if(udp_in->Checked==true)f[17]=f[17]^0x04;
                    if(udp_out->Checked==true)f[17]=f[17]^0x08;
                    if(f[17]<=0x03){f[17]=0;C_udp->Checked=false;}
                    }
                    }
                    if(C_tcp->Checked!=false){}
                    else
                    if(C_icmp->Checked!=false){}
                    else
                    if(C_igmp->Checked!=false){}
                    else
                    if(C_udp->Checked!=false){}
                    else
                    {
                    MessageBox(0,"Нет выбранных условий ","Ошибка ввода",0);
                    return;
                    }
                    if(tabl->Checked==true)f[250]=1;
                    if(golova->Checked==true)f[251]=1;
                    if(alien->Checked==true)f[252]=1;
             //       if(TestL->Checked==true)f[253]=1;
                    Panel6->Enabled=false;
             //       IPBuffer=new StructForLog;
if(vis->Checked==true)cont->Show();
                    
                    _snif=new snif(false," ",m,f);
                    snif_ok=true;
                    Kontrol->Caption="Stop";
            //        Tlogos->Items->Clear();
                    }


              }



void __fastcall Tma::tcp_selfClick(TObject *Sender)
{
if(tcp_self->Checked==false) SetTcp();
  else
  SetUpTcp();
}
//---------------------------------------------------------------------------
void Tma::SetTcp()
{
tcp_in->Checked=false;
tcp_out->Checked=false;
}
void Tma::SetUdp()
{
udp_in->Checked=false;
udp_out->Checked=false;
}
void Tma::SetIcmp()
{
icmp_in->Checked=false;
icmp_out->Checked=false;
}
void Tma::SetIgmp()
{
igmp_in->Checked=false;
igmp_out->Checked=false;
}
void Tma::SetSelf()
{
tcp_self->Checked=false;
udp_self->Checked=false;
icmp_self->Checked=false;
igmp_self->Checked=false;

}




void Tma::SetUpTcp()
{
tcp_in->Checked=true;
tcp_out->Checked=true;
}
void Tma::SetUpUdp()
{
udp_in->Checked=true;
udp_out->Checked=true;
}
void Tma::SetUpIcmp()
{
icmp_in->Checked=true;
icmp_out->Checked=true;
}
void Tma::SetUpIgmp()
{
igmp_in->Checked=true;
igmp_out->Checked=true;
}
void Tma::SetUpSelf()
{
tcp_self->Checked=true;
udp_self->Checked=true;
icmp_self->Checked=true;
igmp_self->Checked=true;

}




void __fastcall Tma::icmp_selfClick(TObject *Sender)
{
if(icmp_self->Checked==false)SetIcmp();
else SetUpIcmp();
}
//---------------------------------------------------------------------------

void __fastcall Tma::igmp_selfClick(TObject *Sender)
{
if(igmp_self->Checked==false)SetIgmp();
else SetUpIgmp();
}
//---------------------------------------------------------------------------

void __fastcall Tma::udp_selfClick(TObject *Sender)
{
if(udp_self->Checked==false)SetUdp();
else SetUpUdp();
}
//---------------------------------------------------------------------------

void __fastcall Tma::alienClick(TObject *Sender)
{
if(alien->Checked==true)
{
   SetSelf();
}
   else
{
    SetUpSelf();
}
}
//---------------------------------------------------------------------------


void __fastcall Tma::C_tcpClick(TObject *Sender)
{
if(C_tcp->Checked==false){SetTcp();tcp_self->Checked=false;}
else {SetUpTcp();tcp_self->Checked=true;}
}
//---------------------------------------------------------------------------

void __fastcall Tma::C_icmpClick(TObject *Sender)
{
if(C_icmp->Checked==false){SetIcmp();icmp_self->Checked=false;}
else{SetUpIcmp();icmp_self->Checked=true;}
}
//---------------------------------------------------------------------------

void __fastcall Tma::C_igmpClick(TObject *Sender)
{
if(C_igmp->Checked==false){SetIgmp();igmp_self->Checked=false;}
else{SetUpIgmp();igmp_self->Checked=true;}        
}
//---------------------------------------------------------------------------

void __fastcall Tma::C_udpClick(TObject *Sender)
{
if(C_udp->Checked==false){SetUdp();udp_self->Checked=false;}
else{SetUpUdp();udp_self->Checked=true;}        
}
//---------------------------------------------------------------------------


void __fastcall Tma::Button7Click(TObject *Sender)
{
 logos->Lines->SaveToFile("log.txt");
}
//---------------------------------------------------------------------------




void __fastcall Tma::Button3Click(TObject *Sender)
{
 ShellExecute(0,"open","cmd.exe",NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------




void __fastcall Tma::CheckBox1Click(TObject *Sender)
{
   if(vis->Checked==true)cont->Show();
        else
        cont->Close();        
}
//---------------------------------------------------------------------------

void __fastcall Tma::KontrolClick(TObject *Sender)
{
Controli();
}
//---------------------------------------------------------------------------

void __fastcall Tma::Button4Click(TObject *Sender)
{
cont->c_logos->Lines->SaveToFile("tabl.txt");        
}
//---------------------------------------------------------------------------





void __fastcall Tma::Button2Click(TObject *Sender)
{
    cont->c_logos->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall Tma::Button8Click(TObject *Sender)
{
//MessageBox(0,"Поиск блокирован....","сообщение",0);
//resursi->Show();

}
//---------------------------------------------------------------------------

void __fastcall Tma::Button9Click(TObject *Sender)
{
 logos->Clear();       
}
//---------------------------------------------------------------------------



void Tma::ToScanIp()
                   {
//-------------------  тест входніх данніх ------------------------------------
AnsiString s=ip->Text;
info *test=new info;
if(test->TestIp(s)==false){
                          MessageBox(0,"Неверный стартовый адрес","ERROR",0);
                          delete test;
                          return;
                          }
BYTE ip_start[4];
memcpy((BYTE*)&ip_start[0],(BYTE*)&test->CIP[0],4);
                          delete test;
int i,j;
try
{
i=StrToInt(end_ip->Text);
}
catch(...)
{
MessageBox(0,"Неверный стартовый адрес","ERROR",0);
return;
}
if(ip_start[3]>i){
                  MessageBox(0,"Неверный стартовый адрес","ERROR",0);
                  return;
                 }
//------------------------ определить порты для скана -------------------------
bool ports[1024]; int tipscan=0; ZeroMemory((bool*)&ports[0],1024);
bool *mi_ukas_ports=&ports[0];
if(C_mail->Checked==true){ports[25]=true;ports[110]=true;tipscan++;}
if(C_http->Checked==true){ports[80]=true;tipscan++;}
if(C_ftp->Checked==true){ports[21]=true;tipscan++;}
if(C_telnet->Checked==true){ports[23]=true;tipscan++;}
if(C_netbios->Checked==true){ports[135]=true;ports[139]=true;ports[445]=true;tipscan++;}
//-----------------------------------------------------------------------------
                   TMemo *mi_ukas;
                   mi_ukas=logos;                  //--- окно для вывода данных
                   bar->Max=1024;
                   bar->Min=0;
                   bar->Position=0;
                   int ik=0;

AnsiString addr,mi_addr;
addr=IntToStr(ip_start[0]);
addr=addr+".";
addr=addr+IntToStr(ip_start[1]);
addr=addr+".";
addr=addr+IntToStr(ip_start[2]);
addr=addr+".";
                     logos->Lines->Add("start scan - "+addr);
                     bar->Position=0;
                     bar->Max=255;
//-----------------------------------------------------------------------------
            for(int ii=0;ii<255;ii++)
                   {
mi_addr=addr+IntToStr(ii);
                   newscanip *scanblok=new newscanip(true,&ports[0],mi_addr,0);
                   scanblok->FreeOnTerminate=true;
                   scanblok->Resume();
                   Application->ProcessMessages();
                   Sleep(100);
                   bar->Position=ii;
                   }
                    logos->Lines->Add("end scan");
                    bar->Position=0;
                 }

void __fastcall Tma::SpeedButton1Click(TObject *Sender)
{
// ToScanIp();
}
//---------------------------------------------------------------------------

void __fastcall Tma::Button1Click(TObject *Sender)
{
ShellExecute(0,"open","ipconfig.exe",NULL,NULL,SW_SHOWNORMAL);        
}
//---------------------------------------------------------------------------

void __fastcall Tma::Button10Click(TObject *Sender)
{
 ShellExecute(0,"open","nslookup.exe",NULL,NULL,SW_SHOWNORMAL);       
}
//---------------------------------------------------------------------------

