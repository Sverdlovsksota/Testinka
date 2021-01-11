//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "contr.h"
#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tcont *cont;
//---------------------------------------------------------------------------
__fastcall Tcont::Tcont(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall Tcont::FormClose(TObject *Sender, TCloseAction &Action)
{
 ma->vis->Checked= false;
}
//---------------------------------------------------------------------------



