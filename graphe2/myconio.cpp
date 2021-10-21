
#include <windows.h>
#include <WinDef.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include "myconio.h"



void gotoxy(int x, int y)
{
HANDLE hConsoleOutput;
COORD dwCursorPosition;
fflush(stdout);
dwCursorPosition.X = x;
dwCursorPosition.Y = y;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);

}

void clrscr()
{		
		system("cls");
}
void textcolor(int fontcolor)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_attribute=BLACK;
	color_attribute = _rotl(color_attribute,4) | fontcolor;
	SetConsoleTextAttribute(hConsoleOutput,color_attribute);
}


void Ecran(int Mode) // parametre Mode : 1=plein ecran et 2=mode fenetre
{
	//typedef BOOL WINAPI (*SetConsoleDisplayModeT)(HANDLE,DWORD,DWORD*);
	typedef  BOOL (*SetConsoleDisplayModeT)(HANDLE,DWORD,DWORD*);

	SetConsoleDisplayModeT SetConsoleDisplayMode;

	HINSTANCE hLib=LoadLibrary(TEXT("KERNEL32.DLL"));
	SetConsoleDisplayMode=(SetConsoleDisplayModeT)
	GetProcAddress(hLib,"SetConsoleDisplayMode");

	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	DWORD oldmode;

	SetConsoleDisplayMode(hConsoleOutput,Mode,&oldmode);
  }






int wherex()
{
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (! GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return 0;
        return csbiInfo.dwCursorPosition.X;
        //rny=csbiInfo.dwCursorPosition.Y;
}

int wherey()
{
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (! GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return 0;
        return csbiInfo.dwCursorPosition.Y;
}

int getmaxx()
{
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (! GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return 0;
        return csbiInfo.dwSize.X;
}
int getmaxy()
{
        CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
		HANDLE hConsoleOutput;
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (! GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return 0;
        return csbiInfo.dwSize.Y;
}