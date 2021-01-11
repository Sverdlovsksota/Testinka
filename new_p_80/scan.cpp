//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "scan.h"
#include "main.h"
#include "FileClass.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall scaner::scaner(bool CreateSuspended,AnsiString ip,int s,int e)
        : TThread(CreateSuspended)
{
miIP=ip;
start=s;
stop=e;
}
//---------------------------------------------------------------------------

void __fastcall scaner::Execute()
{
                          int i;
//---------------------------------------------------------------------------
                          mi_SocketOption *test=new mi_SocketOption;
                          ma->IncScan();
                          misock=test->CreateSocket();
                          bool r=test->IniScan(miIP,start,misock);
                          delete test;
                if(r==true)
                          {
                          TMemoryStream *mm=new TMemoryStream;
                          mm->LoadFromFile("spisok.txt");
                          int size=mm->Size;
                          char *mms=new char[size];
                          mm->Seek(0,0);
                          mm->Read((char*)&mms[0],size );
                          delete mm;
                          int pos=AnsiPos(IntToStr(start),((AnsiString)mms));pos--;
                          if(pos==0)ma->OutLogo((miIP+" Port : "+IntToStr(start)).c_str());
                          else
                          {
                          int pos_end=0;
                          bool metka=false;
//------------------------------------------------------------------------------
                          do
                          {
                          if(mms[pos+pos_end]==0xD){metka=true;break;}
                          pos_end++;
                          Application->ProcessMessages();
                          }while(size!=pos_end);
//------------------------------------------------------------------------------
                          if(metka!=false)
                          {
                          char *mis=new char[pos_end+10];
                          memcpy((char*)&mis[0],(char*)&mms[pos],pos_end);mis[pos_end]=0;
                          ma->OutLogo(mis);
                          delete mis;
                          }
                          }
                          delete mms;
                          }
                          closesocket(misock);
                          ma->DecScan();
//------------------------------------------------------------------------------
                          Terminate();

}


//---------------------------------------------------------------------------
