//Library version v1.15

#include <Windows.h>
#include <iostream>
#include <wincrypt.h>
#include <mmsystem.h>
#include <string>
#include <conio.h>

// by xndRs7

using namespace std;

int sx = GetSystemMetrics(SM_CXSCREEN);
int sy = GetSystemMetrics(SM_CYSCREEN);
HDC desktop = GetDC(NULL);
HWND upWind = GetForegroundWindow();
HDC upHdc = GetDC(upWind);
CURSORINFO curInf;


void print(string text) {  //ne straday NO COUT
	cout << text;
}


//CURSOR CLASS//
void DublicateCursor(int CursorPosX, int CursorPosY, int Duration) {
	GetCursorInfo(&curInf);
	curInf.cbSize = sizeof(curInf);
	DrawIcon(desktop, CursorPosX, CursorPosY, curInf.hCursor);
	Sleep(Duration);
}
void DrawIconOnCursor(LPCWSTR IDI__, int Duration) {
	GetCursorInfo(&curInf);
	curInf.cbSize = sizeof(curInf);
	DrawIcon(desktop, curInf.ptScreenPos.x, curInf.ptScreenPos.y, LoadIcon(NULL, IDI__));
	Sleep(Duration);
}
//CURSOR CLASS END//

//GDI CLASS//
void CreateGDI(int x, int y, int x2, int y2, DWORD EffectCode, int Duration) {
	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);
	BitBlt(desktop, x, y, sx, sy, upHdc, x2, y2, EffectCode);
	Sleep(Duration);
}
void JustGDI(int Duration) {
	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);
	BitBlt(desktop, 0, 0, sx, sy, upHdc, 0, 0, 0x555555);
	Sleep(Duration);
}
void MadGDI(int Duration) {
	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);

	Sleep(Duration);
	BitBlt(desktop, rand() % sx, rand() % sy, rand() % sx, rand() % sy, upHdc, rand() % sx, rand() % sy, 0xc909090);
	Sleep(Duration);
	BitBlt(desktop, rand() % sx, rand() % sy, rand() % sx, rand() % sy, upHdc, rand() % sx, rand() % sy, 0xc555555);
}
void TunnelGDI(int Duration) {
	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(0);
	sy = GetSystemMetrics(1);
	StretchBlt(desktop, 50, 50, sx - 100, sy - 100, desktop, 0, 0, sx, sy, SRCCOPY);
	Sleep(Duration);
}
void GlitchGDI(int Duration) {
	int meltX = 1;
	int meltX2 = 1;
	int meltY = 1;
	int meltY2 = 1;
	meltX =+ 1 + rand() % 500;
	meltX2 =- 1 + rand() % 500;
	meltY =+ 1 + rand() % 500;
	meltY2 =- 1 + rand() % 500;

	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);
	CreateGDI(rand() % meltX, rand() % meltY, rand() % meltX2, rand() % meltY2, 0xc777777, Duration);
	CreateGDI(rand() % meltX, rand() % meltY, rand() % meltX2, rand() % meltY2, 0x555555, Duration);

	meltX = 1;
	meltX2 = 1;
	meltY = 1;
	meltY2 = 1;
}
void InsertColorsGDI() {
	desktop = GetDC(NULL);
	upWind = GetForegroundWindow();
	upHdc = GetDC(upWind);
	sx = GetSystemMetrics(SM_CXSCREEN);
	sy = GetSystemMetrics(SM_CYSCREEN);
	BitBlt(desktop, 0, 0, sx, sy, upHdc, 0, 0, 0x555555);
}
//GDI CLASS END//
