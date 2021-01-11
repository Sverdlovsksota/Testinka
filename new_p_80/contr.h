//---------------------------------------------------------------------------

#ifndef contrH
#define contrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class Tcont : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMemo *c_logos;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall Tcont(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tcont *cont;
//---------------------------------------------------------------------------
#endif
