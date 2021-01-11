#ifndef TAB.H
#define TAB.H

#include <vcl.h>
#include <windows.h>
#include <winsock.h>

//Структура заголовка IP-пакета

typedef struct IPHeader {
  UCHAR   iph_verlen;   // версия и длина заголовка
  UCHAR   iph_tos;      // тип сервиса
  USHORT  iph_length;   // длина всего пакета
  USHORT  iph_id;       // Идентификация
  USHORT  iph_offset;   // флаги и смещения
  UCHAR   iph_ttl;      // время жизни пакета
  UCHAR   iph_protocol; // протокол
  USHORT  iph_xsum;     // контрольная сумма
  ULONG   iph_src;      // IP-адрес отправителя
  ULONG   iph_dest;     // IP-адрес назначения
} IPHeader;



class RisTable
{
public :
IN_ADDR mi_in_addr;
AnsiString GetFrom(char *buffer)
                               {
AnsiString s;
IPHeader * hdr = (IPHeader *)buffer;
mi_in_addr.S_un.S_addr=hdr->iph_src;
s=inet_ntoa(mi_in_addr);
return s;
                               }

int GetLong(char *buffer)
{
IPHeader* hdr = (IPHeader *)buffer;
WORD lbyte=hdr->iph_length<<8;
WORD rbyte=hdr->iph_length>>8;
rbyte=rbyte+lbyte;
return rbyte;
}

BYTE GetId(char *buffer)
{
IPHeader* hdr = (IPHeader *)buffer;
return(hdr->iph_id);
}
AnsiString GetTo(char *buffer)
{
AnsiString s;
IPHeader* hdr = (IPHeader *)buffer;
mi_in_addr.S_un.S_addr=hdr->iph_dest;
s=inet_ntoa(mi_in_addr);
return s;
}

AnsiString GetProto(char *buffer)
{
AnsiString s;
IPHeader* hdr = (IPHeader *)buffer;
s="?";

switch (hdr->iph_protocol)
{
case 0 : {s="IP";break;}
case 1 : {s="ICMP";break;}
case 2 : {s="IGMP";break;}
case 3 : {s="GGP";break;}
case 6 : {s="TCP";break;}
case 12 : {s="PUP";break;}
case 17 : {s="UDP";break;}
case 22 : {s="IDP";break;}
case 77 : {s="ND";break;}
case 255 : {s="RAW";break;}
case 256 : {s="MAX";break;}
}
return s;
}


void BildBit(TMemo *m,char *b,int addr,int cout)
{
AnsiString s,sl; BYTE mib;

int i,j,pos; pos=cout/16;if(pos<1)pos=1;
             pos++;
for(i=0;i<pos;i++)
                 {
             sl=s+s.IntToHex(addr+(i*16),4)+"\t";
for(j=0;j<16;j++)
                 {
             mib=(BYTE)b[j+(i*16)];
             sl=sl+s.IntToHex(mib,2)+" ";
             cout--;
             if(cout<=0)break;
                 }
for(int d=0;d<(16-j)-1;d++)sl=sl+"   ";
             sl=sl+"  ";
for(int l=0;l<(16-(16-j));l++)
                 {
             if(b[l+(i*16)]>0x19){if(b[l+(i*16)]<0x7F) sl=sl+b[l+(i*16)];}
             else sl=sl+".";
                 }
             m->Lines->Add(sl);
              if(cout<=0)break;
                 }
             m->Lines->Add(" ");    
}


};



#endif
 