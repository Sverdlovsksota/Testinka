#include <vcl.h>
#include <windows.h>

#include "FileClass.h"
#include <winsock.h>


info :: info()
            {
            name=new char[300];
            ClearBuffer();           //    �������� ������
            list=new AnsiString[25]; //    ������� ������ ��� �������� ip
            cout_list=0;             //    ���������� ip
            GetLocalHost();
            } ;




