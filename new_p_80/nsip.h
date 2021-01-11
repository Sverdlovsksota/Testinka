//---------------------------------------------------------------------------

#ifndef nsipH
#define nsipH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "nsip_child.h"
//---------------------------------------------------------------------------
struct mi_buffer_nsip
                     {
                     bool for_scan;
                     bool status;
                     newscanip_child *uk;
                     DWORD mi_time;
                     int nport;
                     bool resultat;
                     DWORD prom;
                     };

class newscanip : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        AnsiString mi_ip;
       __fastcall newscanip(bool CreateSuspended,bool [] ,AnsiString ip,int);
        int  *mi_result;
};
//---------------------------------------------------------------------------
#endif
