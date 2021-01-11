#include <vcl.h>
#include <winsock.h>
#include "Peremen.h"
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>


#include <Menus.hpp>

#define NO_FLAGS 0			// ����� �� ���������
#define ICMP_ECHO 8			// An ICMP echo message
#define ICMP_ECHOREPLY 0		// An ICMP echo reply message
#define	ICMP_HEADERSIZE 8
#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001

struct StructForLog
                  {
                  AnsiString ipname;                   //--- ip
                  TTreeNode *ipnode,*innode,*outnode;//--- ���� �� ������
                  int incount,outcount;              //--- ���������� �������
                  TMemoryStream *m;                  //--- ����� ��� �������
                  };





int iHostAddrLength;		// ����� ������ �������� ����������
int iIPHeadLength;		// ����� ��������� IP-����������
AnsiString HostName;
char Buffer[MAX_PACKET_SIZE];   // 64 Kb
//int ct;
SOCKET      s;                  // C�������� �����.
struct icmp *pIcmpHeader;	// ��������� �� ��������� ICMP
struct ip *pIpHeader;		// ��������� �� ���������-��������� IP
char src[10];
char dest[10];
char ds[15];
unsigned short lowbyte;
unsigned short hibyte;
BYTE mif[256];
TMemo *miMem;
SOCKADDR_IN	sockAddrHost;
SOCKET hSocket;		    	// ���������� ������
LPHOSTENT lpHostEntry;		// ��������� ������ �
LPPROTOENT lpProtocolEntry;	// ��������� ������ � ����������� � ���������
BYTE IcmpRecvPacket[4096];	// ����� ��� ����������� ������
int iReceivedBytes;		// ���������� �������� ������


StructForLog *IPBuffer;
int CountStructForLog=0;
