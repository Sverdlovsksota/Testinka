//---------------------------------------------------------------------------

#ifndef pinaH
#define pinaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Winsock.h>
#include <vcl.h>
//---------------------------------------------------------------------------
class pina : public TThread
{

typedef struct
{
unsigned char Ttl;
unsigned char Tos;
unsigned char Flags;
unsigned char OptionsSize;
unsigned char *OptionsData;
} IP_OPTION_INFORMATION, * PIP_OPTION_INFORMATION;

typedef struct
{
unsigned long  Address;
unsigned long Status;
unsigned long RoundTripTime;
unsigned short DataSize;
unsigned short Reserved;
void *Data;
IP_OPTION_INFORMATION Options;
} IP_ECHO_REPLY, * PIP_ECHO_REPLY;


private:
protected:
        void __fastcall Execute();
public:
        HINSTANCE hIcmp;
        __fastcall pina(bool CreateSuspended,
        AnsiString ip,
        int nomer,
        bool status,
        int kol,
        bool GetName);

        bool SendPing(char* AddressIP );
        AnsiString miIP;
        int minomer;
        bool Status;
        int mikol;
        bool miGetName;
};
//---------------------------------------------------------------------------
#endif
