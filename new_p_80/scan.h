//---------------------------------------------------------------------------

#ifndef scanH
#define scanH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vcl.h>
#include <winsock.h>

//---------------------------------------------------------------------------
class scaner : public TThread
{            
private:
protected:
        void __fastcall Execute();
        
public:
        __fastcall scaner(bool CreateSuspended,AnsiString,int,int);

        AnsiString miIP;
        int start,stop;
        SOCKET  misock;


};
//---------------------------------------------------------------------------
#endif
