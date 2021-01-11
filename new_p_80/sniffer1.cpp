//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop
#include "FileClass.h"
#include "sniffer1.h"

#include "main.h"
#include "tab.h"
#include "Peremen.cpp"
#pragma package(smart_init)

//void TestLogin(char *Buffer,int count,IPHeader *);
AnsiString GetStr(IPHeader *,char *);

AnsiString miHost;
int NomerPacketa=0;
void RisDerevoOt(char *Buffer,IPHeader *hdr,int sm) ;
void derevo(char *Buffer,IPHeader *hdr);
void RisDerevoIn(char *Buffer,IPHeader *hdr,int sm,AnsiString);
void RisDerevoOut(char *Buffer,IPHeader *hdr,int sm,AnsiString);


DWORD WINAPI WaveInThread (void *Arg)
{
AnsiString nom,mit;
int ct;
                   IPBuffer=new StructForLog[255];
                   CountStructForLog=0;
NomerPacketa=0;
                   do
                   {
                   Application->ProcessMessages();
                   ct = recv( s, Buffer, sizeof(Buffer), 0 );
                   if( ct >= sizeof(IPHeader) )
                   {
                   IPHeader* hdr = (IPHeader *)Buffer;
                   BYTE b=mif[hdr->iph_protocol];
                   if(b!=0)
                   {
                   RisTable *t=new RisTable;
                   mit="";
if(mif[252]==1)                      //------- принимать только чужие пакеты
                   {
                   if(miHost!=t->GetFrom(Buffer))
                   if(miHost!=t->GetTo(Buffer))
                   GetStr(hdr,Buffer);
                   }
                   else
                   {
if((b & 0x02)==0)GetStr(hdr,Buffer); //-- принимать вообще все пакеты
                   else
                   {                 //-- принимать только свои пакеты
if((b & 0x04)==0x04)                 //-- исходящие
                   {
                   nom=t->GetTo(Buffer);
                   if((b & 0x02)==02) if(nom==miHost) mit=GetStr(hdr,Buffer);
                   }

if((b & 0x08)==0x08)
                   {                  //-- входящие
                   nom=t->GetFrom(Buffer);
                   if((b & 0x02)==02)if(nom==miHost) mit=GetStr(hdr,Buffer);
                   }
                   }
                   }
       //            TestLogin(Buffer,ct,hdr);
                   NomerPacketa++;
                   delete t;
                   }
                   }
                   else
                 //  miMem->Lines->Add("--> Некорректный пакет...");
                   Application->ProcessMessages();
                   }
                   while(ma->startscan==true);
                   delete IPBuffer;
}


void derevo(char *Buffer,IPHeader *hdr)
{
if(CountStructForLog!=0){
                        RisTable *t=new RisTable;
                        AnsiString sd=t->GetTo(Buffer);
                        AnsiString sc=t->GetFrom(Buffer);
                        delete t;
//------------------------------------------------------------------------------
int r=0;
for(int i=0;i<CountStructForLog;i++)
                        {
                        if(IPBuffer[i].ipname==sc)
                        {
                        RisDerevoOut(Buffer,hdr,i,sd);
                        return;
                        }
                        if(IPBuffer[i].ipname==sd)
                        {
                        RisDerevoIn(Buffer,hdr,i,sc);
                        return;
                        }
                        }

                        if(CountStructForLog>=sizeof(struct StructForLog))return;
                        RisDerevoOt(Buffer,hdr,CountStructForLog);
                        RisDerevoOut(Buffer,hdr,CountStructForLog,sd);
                        CountStructForLog++;
//------------------------------------------------------------------------------
                        }
                        else
                        {
                        RisDerevoOt(Buffer,hdr,CountStructForLog);
                        CountStructForLog++;
                        }

}

void RisDerevoOt(char *Buffer,IPHeader *hdr,int sm)                  // sm смещение по IPBuffer
{
//RisTable *t=new RisTable;
//IPBuffer[sm].ipname=t->GetFrom(Buffer);
//IPBuffer[sm].ipnode=ma->Tlogos->Items->AddFirst(NULL,IPBuffer[sm].ipname.c_str());
//IPBuffer[sm].ipnode->ImageIndex=1;
//IPBuffer[sm].ipnode->SelectedIndex=2;
//IPBuffer[sm].outnode=ma->Tlogos->Items->AddChild(IPBuffer[sm].ipnode,"out packets");
//IPBuffer[sm].outnode->ImageIndex=1;
//IPBuffer[sm].outnode->SelectedIndex=2;
//IPBuffer[sm].innode=ma->Tlogos->Items->AddChild(IPBuffer[sm].ipnode,"in packets");
//IPBuffer[sm].innode->ImageIndex=1;
//IPBuffer[sm].innode->SelectedIndex=2;

//delete t;
}
void RisDerevoIn(char *Buffer,IPHeader *hdr,int sm,AnsiString s)
{
return;
int count=IPBuffer[sm].ipnode->Item[1]->Count;
if(count!=0)
           {
           for(int i=0;i<count;i++)
           {
           if(IPBuffer[sm].ipnode->Item[1]->Item[i]->Text==s)
           {

if(hdr->iph_protocol==6) //-- tcp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[0]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[0]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==17) //-- udp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[1]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[1]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==1) //-- icmp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[2]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[2]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==2) //-- igmp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[3]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[1]->Item[i]->Item[3]->Item[0]->Text=IntToStr(cif);
                       return;
                       }

           }
           }
           }
RisTable *t=new RisTable;
//TTreeNode *innode=ma->Tlogos->Items->AddChild(IPBuffer[sm].innode,(t->GetFrom(Buffer)).c_str());
//innode->ImageIndex=1;
//innode->SelectedIndex=2;

//TTreeNode *tcpnode=ma->Tlogos->Items->AddChild(innode,"TCP");
//tcpnode->ImageIndex=0;
//tcpnode->SelectedIndex=0;
//TTreeNode *_tcpnode=ma->Tlogos->Items->AddChild(tcpnode,'0');
//_tcpnode->ImageIndex=0;
//_tcpnode->SelectedIndex=0;

//TTreeNode *udpnode=ma->Tlogos->Items->AddChild(innode,"UDP");
//udpnode->ImageIndex=0;
//udpnode->SelectedIndex=0;
//TTreeNode *_udpnode=ma->Tlogos->Items->AddChild(udpnode,'0');
//_udpnode->ImageIndex=0;
//_udpnode->SelectedIndex=0;

//TTreeNode *icmpnode=ma->Tlogos->Items->AddChild(innode,"ICMP");
//icmpnode->ImageIndex=0;
//icmpnode->SelectedIndex=0;
//TTreeNode *_icmpnode=ma->Tlogos->Items->AddChild(icmpnode,'0');
//_icmpnode->ImageIndex=0;
//_icmpnode->SelectedIndex=0;

//TTreeNode *igmpnode=ma->Tlogos->Items->AddChild(innode,"IGMP");
//igmpnode->ImageIndex=0;
//igmpnode->SelectedIndex=0;
//TTreeNode *_igmpnode=ma->Tlogos->Items->AddChild(igmpnode,'0');
//_igmpnode->ImageIndex=0;
//_igmpnode->SelectedIndex=0;

//if(t->GetProto(Buffer)=="TCP")
//                             {
//                             int c=StrToInt(_tcpnode->Text);
//                             c++;
//                             _tcpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="UDP")
//                             {
//                             int c=StrToInt(_udpnode->Text);
//                             c++;
//                             _udpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="ICMP")
//                             {
//                             int c=StrToInt(_icmpnode->Text);
//                             c++;
//                             _icmpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="IGMP")
//                             {
//                             int c=StrToInt(_igmpnode->Text);
//                             c++;
//                             _igmpnode->Text=IntToStr(c++);
//                             }

delete t;

}
void RisDerevoOut(char *Buffer,IPHeader *hdr,int sm,AnsiString s)
{
return;
int count=IPBuffer[sm].ipnode->Item[0]->Count;
if(count!=0)
           {
           for(int i=0;i<count;i++)
           {
           if(IPBuffer[sm].ipnode->Item[0]->Item[i]->Text==s)
           {
if(hdr->iph_protocol==6) //-- tcp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[0]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[0]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==17) //-- udp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[1]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[1]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==1) //-- icmp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[2]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[2]->Item[0]->Text=IntToStr(cif);
                       return;
                       }
if(hdr->iph_protocol==2) //-- igmp
                       {
                       int cif=StrToInt(IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[3]->Item[0]->Text);
                       cif++;
                       IPBuffer[sm].ipnode->Item[0]->Item[i]->Item[3]->Item[0]->Text=IntToStr(cif);
                       return;
                       }

           }
           }
           }
//RisTable *t=new RisTable;
//TTreeNode *outnode=ma->Tlogos->Items->AddChild(IPBuffer[sm].outnode,(t->GetTo(Buffer)).c_str());
//outnode->ImageIndex=1;
//outnode->SelectedIndex=2;

//TTreeNode *tcpnode=ma->Tlogos->Items->AddChild(outnode,"TCP");
//tcpnode->ImageIndex=0;
//tcpnode->SelectedIndex=0;
//TTreeNode *_tcpnode=ma->Tlogos->Items->AddChild(tcpnode,'0');
//_tcpnode->ImageIndex=0;
//_tcpnode->SelectedIndex=0;

//TTreeNode *udpnode=ma->Tlogos->Items->AddChild(outnode,"UDP");
//udpnode->ImageIndex=0;
//udpnode->SelectedIndex=0;
//TTreeNode *_udpnode=ma->Tlogos->Items->AddChild(udpnode,'0');
//_udpnode->ImageIndex=0;
//_udpnode->SelectedIndex=0;

//TTreeNode *icmpnode=ma->Tlogos->Items->AddChild(outnode,"ICMP");
//icmpnode->ImageIndex=0;
//icmpnode->SelectedIndex=0;
//TTreeNode *_icmpnode=ma->Tlogos->Items->AddChild(icmpnode,'0');
//_icmpnode->ImageIndex=0;
//_icmpnode->SelectedIndex=0;

//TTreeNode *igmpnode=ma->Tlogos->Items->AddChild(outnode,"IGMP");
//igmpnode->ImageIndex=0;
//igmpnode->SelectedIndex=0;
//TTreeNode *_igmpnode=ma->Tlogos->Items->AddChild(igmpnode,'0');
//_igmpnode->ImageIndex=0;
//_igmpnode->SelectedIndex=0;

//if(t->GetProto(Buffer)=="TCP")
//                             {
//                             int c=StrToInt(_tcpnode->Text);
//                             c++;
//                             _tcpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="UDP")
//                             {
//                             int c=StrToInt(_udpnode->Text);
//                             c++;
//                             _udpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="ICMP")
//                             {
//                             int c=StrToInt(_icmpnode->Text);
//                             c++;
//                             _icmpnode->Text=IntToStr(c++);
//                             }
//if(t->GetProto(Buffer)=="IGMP")
//                             {
//                             int c=StrToInt(_igmpnode->Text);
//                             c++;
//                             _igmpnode->Text=IntToStr(c++);
//                             }
//
//delete t;

}



AnsiString GetStr(IPHeader *hdr,char *Buffer)
{
RisTable *t=new RisTable;
AnsiString mit=t->GetFrom(Buffer);

if(mif[250]==1)
      {              
miMem->Lines->Add("");
miMem->Lines->Add("Пакет: "+t->GetProto(Buffer)+"\t Номер: "+IntToStr(NomerPacketa));
miMem->Lines->Add("size: "+IntToStr(t->GetLong(Buffer)));
miMem->Lines->Add("TTL: "+IntToStr(hdr->iph_ttl));

miMem->Lines->Add("от: "+t->GetFrom(Buffer));
miMem->Lines->Add("кому: "+t->GetTo(Buffer));
miMem->Lines->Add("");

      int len=t->GetLong(Buffer);
      t->BildBit(miMem,Buffer,0,len);

      }

delete t;
  derevo(Buffer,hdr);

return mit;

}



__fastcall snif::snif(bool CreateSuspended,
                      AnsiString name,
                      TMemo *mi,
                      BYTE *filter) : TThread(CreateSuspended)
{
HostName = name;
miMem=mi;
memcpy((BYTE *)&mif[0],(BYTE*)&filter[0],256);
}

//---------------------------------------------------------------------------
void __fastcall snif::Execute()
{

  char        name[128];                      // Имя хоста (компьютера).
  HOSTENT*    phe;                            // Информация о хосте.
  SOCKADDR_IN sa;                             // Адрес хоста
  IN_ADDR sa1;
  unsigned long        flag = 1;              // Флаг PROMISC Вкл/выкл.

  s = socket( AF_INET, SOCK_RAW, IPPROTO_IP );
  gethostname(name, sizeof(name));
  phe = gethostbyname( name );
  ZeroMemory( &sa, sizeof(sa) );
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr =((struct in_addr *)phe->h_addr_list[0])->s_addr;
  AnsiString addrr=inet_ntoa(sa.sin_addr);
  miHost=addrr;
  miMem->Lines->Add("Прослушиваю по IP: "+addrr);
  bind(s, (SOCKADDR *)&sa, sizeof(SOCKADDR));

  ioctlsocket(s, SIO_RCVALL, &flag);
  miRecv();

do
  {
  Application->ProcessMessages();
  Sleep(10);
  }
  while(ma->startscan==true);

  closesocket( s );

}

bool snif::miRecv()
{
 DWORD WaveInThreadId;
 HANDLE WaveInThreadHandle = CreateThread(NULL,
                                                0,
                                                WaveInThread,
                                                NULL,
                                                0L,
                                                &WaveInThreadId);
  if(NULL == WaveInThreadHandle)
  {
  miMem->Lines->Add("Поток получения пакетов не создан...нажать кнопку Stop.");
  return false;
  }
  do
  {
  Application->ProcessMessages();
  Sleep(10);
  }while(ma->startscan==true);
  miMem->Lines->Add("Прослушивание остановлено...");
return(true);
}




