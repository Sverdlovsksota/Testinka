//---------------------------------------------------------------------------

#ifndef prH
#define prH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class Tresursi : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TEdit *e_ip;
        TLabel *Label1;
        TButton *st;
        TPanel *Panel3;
        TTreeView *TLogos;
        TImageList *ImageList1;
        void __fastcall stClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tresursi(TComponent* Owner);
        void GetNetResurs(AnsiString,AnsiString);
        void GetDomain(AnsiString );
        };
//---------------------------------------------------------------------------
extern PACKAGE Tresursi *resursi;
//---------------------------------------------------------------------------
#endif
