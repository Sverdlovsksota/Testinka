#include <vcl.h>
#include <winsock.h>
#include "Peremen.h"
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>


#include <Menus.hpp>

#define NO_FLAGS 0			// Флаги не указываем
#define ICMP_ECHO 8			// An ICMP echo message
#define ICMP_ECHOREPLY 0		// An ICMP echo reply message
#define	ICMP_HEADERSIZE 8
#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001

struct StructForLog
                  {
                  AnsiString ipname;                   //--- ip
                  TTreeNode *ipnode,*innode,*outnode;//--- ноды на экране
                  int incount,outcount;              //--- количество записей
                  TMemoryStream *m;                  //--- буфер для пакетов
                  };





int iHostAddrLength;		// Длина адреса сетевого компьютера
int iIPHeadLength;		// Длина заголовка IP-датаграммы
AnsiString HostName;
char Buffer[MAX_PACKET_SIZE];   // 64 Kb
//int ct;
SOCKET      s;                  // Cлущающий сокет.
struct icmp *pIcmpHeader;	// Указатель на структуру ICMP
struct ip *pIpHeader;		// Указатель на структуру-заголовок IP
char src[10];
char dest[10];
char ds[15];
unsigned short lowbyte;
unsigned short hibyte;
BYTE mif[256];
TMemo *miMem;
SOCKADDR_IN	sockAddrHost;
SOCKET hSocket;		    	// Дескриптор сокета
LPHOSTENT lpHostEntry;		// Структура данных с
LPPROTOENT lpProtocolEntry;	// Структура данных с информацией о протоколе
BYTE IcmpRecvPacket[4096];	// Буфер для принимаемых данных
int iReceivedBytes;		// Количество принятых байтов


StructForLog *IPBuffer;
int CountStructForLog=0;
