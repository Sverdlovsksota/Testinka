//---------------------------------------------------------------------------

#ifndef nsip_childH
#define nsip_childH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "nsip.h"
//---------------------------------------------------------------------------
class newscanip_child : public TThread
{            
private:
protected:
        void __fastcall Execute();
public:
        __fastcall newscanip_child(
                                   bool CreateSuspended,
                                   AnsiString ,
                                   int ,
                                   struct mi_buffer_nsip * 
                                   );
        int mi_port;
        AnsiString mi_ips;
        struct mi_buffer_nsip *uk_buffer;
};
//---------------------------------------------------------------------------
#endif
