//---------------------------------------------------------------------------
#include <vcl.h>
#include <winsock.h>

#ifndef sniffer1H
#define sniffer1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class snif : public TThread
{
private:
protected:
        void __fastcall Execute();

struct ip 				// Структура заголовка IP
{
	BYTE ip_verlen;			// Version and header length
	BYTE ip_tos;			// Type of service
	WORD ip_len;			// Total packet length
	WORD ip_id;			// Datagram identification
	WORD ip_fragoff;		// Fragment offset
	BYTE ip_ttl;			// Time to live
	BYTE ip_proto;			// Protocol
	WORD ip_chksum;			// Checksum
	in_addr ip_src_addr;		// Source address
	in_addr ip_dst_addr;		// Destination address
	BYTE ip_data[1];		// Variable length data area
};

struct icmp				// Структура заголовка ICMP
{
	BYTE icmp_type;			// Type of message
	BYTE icmp_code;			// Type "sub code" (zero for echos)
	WORD icmp_cksum;		// 1's complement checksum
	HINSTANCE icmp_id;		// Unique ID (the instance handle)
	WORD icmp_seq;			// Tracks multiple pings
	BYTE icmp_data[1];		// The start of optional data
};


public:
        __fastcall snif(bool CreateSuspended,
          AnsiString,TMemo *,BYTE *);

        char * GetIpName(char *sl);
        SOCKADDR_IN	sockAddrLocal;	// Структуры адреса сокета

bool miRecv();

};






//---------------------------------------------------------------------------
#endif
