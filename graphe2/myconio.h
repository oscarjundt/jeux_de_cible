#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128



void gotoxy(int x, int y);
void clrscr();
void textcolor(int fontcolor);
void Ecran(int mode);
int wherex();
int wherey();
void clrscr();

//using namespace System;
//using namespace System::Runtime::InteropServices;
//[DllImport("user32.dll")]
//
// extern bool MessageBeep(int type);