#include "stdafx.h"
#include "upper_window.h"


upper_window::upper_window(int Xleft, int Xtop, int Xright, int Xbottom)
{
	left = Xleft;
	right = Xright;
	top = Xtop;
	bottom = Xbottom;
}


upper_window::~upper_window()
{
}

void upper_window::render(HWND hWnd, HINSTANCE hInst)
{
	date1_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left+20, top+20, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SetWindowText(date1_static, L"Rozpoczêcie biwaku:");

	date2_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top+60, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SetWindowText(date2_static, L"Zakoñczenie biwaku:");

	number_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top+100, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SetWindowText(number_static, L"Numer biwaku: ");

	date1_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left+180, top + 20, 80, 25, hWnd, NULL, hInst, NULL);


	date2_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 60, 80, 25, hWnd, NULL, hInst, NULL);

	number_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 100, 80, 25, hWnd, NULL, hInst, NULL);

	add_document = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Dodaj dokument", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 500, top + 45, 140, 55, hWnd, (HMENU)ID_DODAJ_DOKUMENT, hInst, NULL);
}

	void upper_window::paint(HDC hdc)
{
		HBRUSH PedzelBlaly,Pudelko;
		PedzelBlaly = CreateSolidBrush(0xFFFFFF);
		HPEN OlowekCzerw, Piornik;
		OlowekCzerw = CreatePen(PS_DOT, 1, 0xFFFFFF);
		Pudelko = (HBRUSH)SelectObject(hdc, PedzelBlaly);
		Piornik = (HPEN)SelectObject(hdc, OlowekCzerw);
		Rectangle(hdc, left,top,right,bottom);
		SelectObject(hdc, Pudelko);
		SelectObject(hdc, Piornik);
		DeleteObject(OlowekCzerw);
		DeleteObject(PedzelBlaly);

}