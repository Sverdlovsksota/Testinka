#ifndef FileClassH
#define FileClassH

#include <vcl.h>
#include <WinSock.h>
#include <windows.h>

#include "main.h"


#include "iphlpapi.h"
#pragma comment(lib, "IPHLPAPI.lib")

//-----------------------------------------------------------------------------
struct ScanerData
{
SOCKET miSocket;                //------------------------ ����� ��� ����������
bool Status;                    //------------------------------- ������� - ���
AnsiString ip,name;             //------------------------------- ��� �����, ip
unsigned int NomerPort[50];     //----------------------------- ���������� �����
} *ssd;
//-----------------------------------------------------------------------------


class info{

private:  char *name;
          //---------------------------------------------- ��������� ip �� �����
          bool Peresil(){while(h->h_addr_list[cout_list]){
          memcpy(&addr.sin_addr,h->h_addr_list[cout_list],h->h_length);
          list[cout_list]=inet_ntoa(addr.sin_addr);cout_list++;
          if(cout_list>10)return(false);}
          return(true);      }

          bool GetLocalHost(){bool b=gethostname(name,255);
                           mi_name=AnsiString(name);return(b);};

          void ClearBuffer(){FillMemory(name,0,255);return;}
          bool GetListIp(){h=gethostbyname(name);
                           if(h==NULL)return(false);
                           return(true);};

          void SetName(AnsiString s){ cout_list=0;ClearBuffer();
                           name=s.c_str();
                           return;}


          //--------------------------------------------------------------------
          struct   sockaddr_in  addr;
public:
          AnsiString mi_name;
          AnsiString *list;

          int cout_list;
          hostent *h;
          SOCKET mysocket,clientsocket;
          BYTE CIP[4];
          //--------------------------------------------------------------------
          info();
          ~info(){};
          //--------------------------------------------------------------------
bool TestPort(AnsiString s)
{
try
{
int i=StrToInt(s);
if(i<0)return(false);
if(i>65534)return(false);
}
catch(...)
{
return(false);
}

return(true);
}


bool TestIp(AnsiString s){//-------- ���� �� ��������� ��������� �����
          bool r=false;             //-------------------- ������������ ��������
          int i=s.Length();         //-- ���������� �������� � ���������� ������
          if(i<7)return(r);         //------------------- ���� ������ ... ������
          if(i>15)return(r);        //-------------------- ����� ������...������
          int pos=0, old=0, Tpos=0;
          char *miStr=s.c_str();    //---- ������ ��� ������� ... � char �������
          i--;                      //------ ��� ������ ������� 0 � ����� ������
          char kod[50];FillMemory(&kod[0],50,0);
          for(int j=0;j<=i;j++){
          if(miStr[j]!='.'){kod[Tpos]=miStr[j];Tpos++;}//- ������� ������ ��� ������������ �����
          else
          {
          if(j-old>3)return(r);                   //----- ������� �����...������
          if(j-old==0)return(r);                  //---- �������� �����...������
          try
                            {
                            int k=StrToInt(kod);  //-----  ���� �� ������� �����
                            if(pos>3)return(r);   //---------------- ����� �����
                            CIP[pos]=k;           //--------------- ����� ������
                            pos++;                //------------ ��������� �����
                            old=j;old++;          //-------------- ������� �����
                            FillMemory((char*)&kod[0],49,0);Tpos=0;//-�������� ������
                            }
                            catch(...)
                            {
                            return(r);
                            }
                            }
                            }
           if(Tpos==0)return(r);
           try
                            {
                            int k=StrToInt(kod);  //-----  ���� �� ������� �����
                            CIP[pos]=k;
                            }
                            catch(...)
                            {
                            return(r);
                            }
          if(pos!=3)return(r);                    //--- ���� �� ���������� �����
          r=true;
          return(r);
          }

bool GetNameIp(AnsiString ip)                 //-- �� ����� �������� ������ ip
                           {
                           SetName(ip);
                           if(GetListIp()==false)return(false);
                           if(Peresil()==false)return(false);
                           if(ip==list[0])return(false);
                           return(true);
                           }


bool GetIpName(AnsiString sl)                 //-- �� ip ��� ��������.
                           {
                           bool r=false;
                           mi_name="";
                           if(TestIp(sl)==false)return(r);
                           SetName(sl);
                           DWORD adr=inet_addr((char *)name);
                           if (adr==INADDR_NONE){return(r);}
                           h=gethostbyaddr((char *)&adr,sizeof(adr),PF_INET);
                           if(h!=NULL)
                           {
                           mi_name=AnsiString(h->h_name);
                           //cout_list=h->h_length;
                           }
                           r=true;
                           return(r);
                           }


bool GetInfoMac (TMemo *logi){

    #define log(x)  logi->Lines->Add(x)

    MIB_IPNETTABLE * pIpNetTable = (MIB_IPNETTABLE *) malloc (0xFFFF);
    ULONG        cbIpNetTable = 0xFFFF;
    AnsiString str;
    DWORD ip;
    if (NO_ERROR != GetIpNetTable (pIpNetTable, &cbIpNetTable, TRUE))
    {
    log("GetIpNetTable() failed:\t"+GetLastError ());
        return (false);
    }
    log  (" ");
    log("----ARP Table:");
    log(" ");
    for (DWORD i = 0; i < pIpNetTable->dwNumEntries; i++)
    {

ip=pIpNetTable->table[i].dwAddr;
str=
    (IntToStr((ip & 0x000000FF))+'.'+
    IntToStr(((ip)& 0x0000FF00)>>8)+'.'+
    IntToStr(((ip)& 0x00FF0000)>>16)+'.'+
    IntToStr(((ip)& 0xFF000000)>>24));
    str=str+"\t";

AnsiString    lstr=
          IntToHex( pIpNetTable->table[i].bPhysAddr[0], 2) + '-' +
          IntToHex( pIpNetTable->table[i].bPhysAddr[1], 2) + '-' +
          IntToHex( pIpNetTable->table[i].bPhysAddr[2], 2) + '-' +
          IntToHex( pIpNetTable->table[i].bPhysAddr[3], 2) + '-' +
          IntToHex( pIpNetTable->table[i].bPhysAddr[4], 2) + '-' +
          IntToHex( pIpNetTable->table[i].bPhysAddr[5], 2);
          log("ip:\t"+str+"\t"+"mac:\t"+lstr);

    }
         log(" ");
         log("----ARP Table end. ");
         log(" ");
free (pIpNetTable);



return (true);
}

bool TestPorts(AnsiString st,AnsiString en)
{
int ist,ien;
try
{
ist=StrToInt(st);          //------------------------------------ ���� �� �����
ien=StrToInt(en);
}
catch(...)
{
return(false);
}
if(ien>65535)return(false);
if(ist>ien)return(false); //---------------------------------- ���� �� ��������
return(true);
}

};
//------------------------------------------------------------------------------
class mi_SocketOption {
public:
bool Status;
SOCKET CreateSocket(){return( socket(AF_INET, SOCK_STREAM, 0));}
bool IniScan(AnsiString miIP,int NomerPort,SOCKET socks)
                      {
                      sockaddr_in dest_addr;
                      dest_addr.sin_family = AF_INET;
                      dest_addr.sin_port = htons(NomerPort);
                      HOSTENT *hst;
                      char *SERVERADDR=miIP.c_str();
                      if (inet_addr(SERVERADDR) != INADDR_NONE)
                      dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
                      else return false;
                      int ret=connect(socks,(sockaddr*)&dest_addr,sizeof(dest_addr));
                      if(ret!=-1) return true;
                      else
                      return false;
                      }
                      };//---------------------------- end class mi_SocketOption
//------------------------------------------------------------------------------
#endif
