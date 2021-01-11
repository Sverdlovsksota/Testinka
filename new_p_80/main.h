//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>

#include "FileClass.h"
#include <Menus.hpp>
#include <Buttons.hpp>
#include <IdBaseComponent.hpp>
#include <ImgList.hpp>
//#include <IdCoder.hpp>
//#include <IdCoderMessageDigest.hpp>
//---------------------------------------------------------------------------
struct miOtvet
{
int tipa;
AnsiString names;
AnsiString ips;
};



class Tma : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TLabel *Label1;
        TEdit *ip;
        TLabel *Label3;
        TEdit *end_ip;
        TPanel *Panel3;
        TButton *gethostip;
        TButton *skan;
        TButton *trace;
        TButton *Button5;
        TButton *Button6;
        TProgressBar *bar;
        TCheckBox *GetName;
        TLabel *Label4;
        TButton *sp;
        TPanel *Panel5;
        TEdit *port_start;
        TEdit *port_end;
        TLabel *Label5;
        TCheckBox *C_netbios;
        TPanel *Panel6;
        TCheckBox *C_tcp;
        TCheckBox *C_icmp;
        TCheckBox *C_igmp;
        TCheckBox *C_udp;
        TCheckBox *tcp_out;
        TCheckBox *tcp_in;
        TCheckBox *icmp_out;
        TCheckBox *icmp_in;
        TCheckBox *igmp_out;
        TCheckBox *igmp_in;
        TCheckBox *udp_out;
        TCheckBox *udp_in;
        TCheckBox *tcp_self;
        TCheckBox *icmp_self;
        TCheckBox *igmp_self;
        TCheckBox *udp_self;
        TCheckBox *tabl;
        TCheckBox *golova;
        TLabel *Label2;
        TLabel *Label6;
        TLabel *Label7;
        TCheckBox *alien;
        TImageList *ImageList1;
        TPanel *Panel8;
        TMemo *logos;
        TButton *Button3;
        TPanel *Panel9;
        TButton *Kontrol;
        TCheckBox *vis;
        TButton *Button4;
        TButton *Button7;
        TPanel *Panel1;
        TButton *Button2;
        TButton *Button8;
        TTimer *TimerBar;
        TButton *Button9;
        TCheckBox *C_http;
        TCheckBox *C_telnet;
        TCheckBox *C_ftp;
        TCheckBox *C_mail;
        TCheckBox *CheckBox1;
        TSpeedButton *SpeedButton1;
        TButton *Button1;
        TButton *Button10;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall skanClick(TObject *Sender);
        void __fastcall gethostipClick(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall spClick(TObject *Sender);
        void __fastcall traceClick(TObject *Sender);
        void __fastcall tcp_selfClick(TObject *Sender);
        void __fastcall icmp_selfClick(TObject *Sender);
        void __fastcall igmp_selfClick(TObject *Sender);
        void __fastcall udp_selfClick(TObject *Sender);
        void __fastcall alienClick(TObject *Sender);
        void __fastcall C_tcpClick(TObject *Sender);
        void __fastcall C_icmpClick(TObject *Sender);
        void __fastcall C_igmpClick(TObject *Sender);
        void __fastcall C_udpClick(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall KontrolClick(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tma(TComponent* Owner);

        CRITICAL_SECTION(cs);
        CRITICAL_SECTION(ds);
        CRITICAL_SECTION(ss);
        CRITICAL_SECTION(sl);
        int ColPinReal;                   //------ количество активных протоков
        int Rea();                        //- получить количество потоков пинга
        void DecPing();
        void IncPing();
        WNDPROC OldWindowProc;
        miOtvet *PinOtvet;
        int ColScanReal;

        void DecScan();
        void IncScan();
        int  ReaScan();
        int  Plus;
        int  ReaPlus();
        void OutLogo(char *);
        bool startscan;

        void SetTcp();
        void SetIcmp();
        void SetIgmp();
        void SetUdp();
        void SetSelf();
        void SetUpTcp();
        void SetUpIcmp();
        void SetUpIgmp();
        void SetUpUdp();
        void SetUpSelf();

        void Controli();
        bool mi_pin();

        void ToScanIp();

        bool p_80,p_135,p_139,p_145;

        bool res_scan[255][255];
    //    HINSTANCE _hIcmp;

        };
//---------------------------------------------------------------------------
extern PACKAGE Tma *ma;

//---------------------------------------------------------------------------
#endif
