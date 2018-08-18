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

	render_report = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Generuj raport", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 350, top + 20, 120, 45, hWnd, (HMENU)ID_GENERUJ_RAPORT, hInst, NULL);

	render_csv = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Generuj CSV", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 350, top + 80, 120, 45, hWnd, (HMENU)ID_GENERUJ_CSV, hInst, NULL);
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

	std::wstring upper_window::get_number()
	{
		std::wstring tmpstr = L"";
		LPWSTR tmp = (LPWSTR)tmpstr.c_str();
		GetWindowText(number_edit, tmp, 100);
		tmpstr = tmp;
		if (tmpstr.empty())
		{
			std::wstring wyjatek = L"Nie wype³niono pola: Numer biwaku";
			throw wyjatek;
		}
		return tmpstr;
	}

date upper_window::get_date()
	{
		std::wstring tmpstr = L"11.11.11";
		LPWSTR tmp = (LPWSTR)tmpstr.c_str();
		GetWindowText(date2_edit, tmp, 100);
		tmpstr = tmp;
		if (tmpstr.empty())
		{
			std::wstring wyjatek = L"Nie wype³niono pola: Data zakoñczenia";
			throw wyjatek;
		}
		date tmpdate(tmpstr);
		return tmpdate;
	}

date upper_window::get_start_date()
{
	std::wstring tmpstr = L"11.11.11";
	LPWSTR tmp = (LPWSTR)tmpstr.c_str();
	GetWindowText(date1_edit, tmp, 100);
	tmpstr = tmp;
	if (tmpstr.empty())
	{
		std::wstring wyjatek = L"Nie wype³niono pola: Data startu";
		throw wyjatek;
	}
	date tmpdate(tmpstr);
	return tmpdate;
}
