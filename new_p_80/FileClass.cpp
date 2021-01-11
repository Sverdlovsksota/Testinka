#include <vcl.h>
#include <windows.h>

#include "FileClass.h"
#include <winsock.h>


info :: info()
            {
            name=new char[300];
            ClearBuffer();           //    очистить буффер
            list=new AnsiString[25]; //    создать буффер для наличных ip
            cout_list=0;             //    количество ip
            GetLocalHost();
            } ;




