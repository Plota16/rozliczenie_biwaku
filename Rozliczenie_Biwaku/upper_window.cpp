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
	HFONT hFont = CreateFont(18, 0, 0, 0, 700, FALSE, FALSE, FALSE, ANSI_CHARSET,
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, TEXT("Calibri"));

	HFONT hFont2 = CreateFont(18, 0, 0, 0, 400, FALSE, FALSE, FALSE, ANSI_CHARSET,
		OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, TEXT("Calibri"));

	date1_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left+20, top+20, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(date1_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(date1_static, L"Rozpoczêcie biwaku:");

	date2_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top+50, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(date2_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(date2_static, L"Zakoñczenie biwaku:");

	date3_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top + 80, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(date3_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(date3_static, L"Data ksiêgowania:");

	number_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top+110, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(number_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(number_static, L"Numer biwaku: ");

	hufiec_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top + 140, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(hufiec_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(hufiec_static, L"Hufiec:");

	komendant_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 20, top + 170, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(komendant_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(komendant_static, L"Komendant biwaku:");

	date1_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left+180, top + 20, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(date1_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);

	date2_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 50, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(date2_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);

	date3_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 80, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(date3_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);

	number_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 110, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(number_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);

	hufiec_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
		SS_LEFT, left + 180, top + 140, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(hufiec_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);

	komendant_edit = CreateWindowEx(0, L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL |
		SS_LEFT, left + 180, top + 170, 80, 25, hWnd, NULL, hInst, NULL);
	SendMessage(komendant_edit, WM_SETFONT, (WPARAM)hFont2, TRUE);



	add_document = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Dodaj dokument", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 425, top + 180, 140, 35, hWnd, (HMENU)ID_DODAJ_DOKUMENT, hInst, NULL);

	render_report_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 350, top + 25, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(render_report_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(render_report_static, L"Plik do wydruku:");

	render_csv_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 350, top + 65, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(render_csv_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(render_csv_static, L"Plik do ksiêgowania:");

	preliminarz_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 350, top + 105, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(preliminarz_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(preliminarz_static, L"Uzupe³nij plan:");

	zaliczki_static = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE |
		SS_LEFT, left + 350, top + 145, 150, 25, hWnd, (HMENU)BIALY, hInst, NULL);
	SendMessage(zaliczki_static, WM_SETFONT, (WPARAM)hFont, TRUE);
	SetWindowText(zaliczki_static, L"Uzupe³nij zaliczki:");
	

	render_report = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Generuj raport", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 500, top + 20, 120, 35, hWnd, (HMENU)ID_GENERUJ_RAPORT, hInst, NULL);

	render_csv = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Generuj CSV", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 500, top + 60, 120, 35, hWnd, (HMENU)ID_GENERUJ_CSV, hInst, NULL);

	preliminarz_button = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Preliminarz", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 500, top + 100, 120, 35, hWnd, (HMENU)ID_PRELIMINARZ, hInst, NULL);

	zaliczki = CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"Zaliczki", WS_CHILD | WS_VISIBLE |
		WS_BORDER, left + 500, top + 140, 120, 35, hWnd, (HMENU)ID_ZALICZKI, hInst, NULL);

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
