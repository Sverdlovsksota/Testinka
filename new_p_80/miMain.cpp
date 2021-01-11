//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("main.cpp", ma);
USEFORM("pr.cpp", resursi);
USEFORM("Ustanovka_ip.cpp", Ust);
USEFORM("contr.cpp", cont);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(Tma), &ma);
                 Application->CreateForm(__classid(Tresursi), &resursi);
                 Application->CreateForm(__classid(TUst), &Ust);
                 Application->CreateForm(__classid(Tcont), &cont);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
