#include "stdafx.h"
#include "line.h"

line::line()
{
	size = 0;
}

void line::set(std::vector<document> Xdokument, HWND XhWnd, HINSTANCE XhInst)
{
	dokumenty = Xdokument;
	size = Xdokument.size();
	hWnd = XhWnd;
	hInst = XhInst;
}


void line::draw()
{
	lp_static.clear();
	date_static.clear();
	symbol_static.clear();
	tresc_static.clear();
	kwota_static.clear();
	rodzaj_static.clear();
	edit_button.clear();
	delete_button.clear();
	for (int i = 0; i < dokumenty.size(); i++)
	{

		document dokument = dokumenty[i];
		std::wstring tmpstr = std::to_wstring(i+1);
		LPWSTR tmpLPWSTR = (LPWSTR)tmpstr.c_str();
		lp_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 50, 265 + 35 * i, 50, 35, hWnd, (HMENU)BIALY, hInst, NULL));

		SetWindowText(lp_static[i], tmpLPWSTR);

		date_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 100, 265 + 35 * i, 100, 35, hWnd, (HMENU)BIALY, hInst, NULL));

		tmpstr = dokument.get_data();
		SetWindowText(date_static[i], (LPWSTR)tmpstr.c_str());

		symbol_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 200, 265 + 35 * i, 150, 35, hWnd, (HMENU)BIALY, hInst, NULL));
		std::wstring t1 = dokument.get_symbol();
		SetWindowText(symbol_static[i], (LPWSTR)t1.c_str());

		tresc_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 350, 265 + 35 * i, 130, 35, hWnd, (HMENU)BIALY, hInst, NULL));

		std::wstring t2 = dokument.get_tresc();
		SetWindowText(tresc_static[i], (LPWSTR)t2.c_str());

		kwota_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 480, 265 + 35 * i, 70, 35, hWnd, (HMENU)BIALY, hInst, NULL));

		tmpstr = dokument.get_kwota();
		int dot_position = 0;
		for (int i = 0; i < tmpstr.size(); i++)
		{
			if (tmpstr[i] == '.')
			{
				dot_position = i;
			}
			if (tmpstr[i] == ',')
			{
				dot_position = i;
				tmpstr[i] = '.';
			}
		}
		std::wstring tmpstr2 = L"";
		if (dot_position != 0)
		{
			for (int i = 0; i < dot_position; i++)
			{
				tmpstr2 += tmpstr[i];
			}
		}
		tmpstr2 += L".";
		if (dot_position == 0)
		{
			tmpstr2 += L"0";
			tmpstr2 += L"0";
		}
		else
		{
			tmpstr2 += tmpstr[dot_position + 1];
			tmpstr2 += tmpstr[dot_position + 2];
		}
		SetWindowText(kwota_static[i], (LPWSTR)tmpstr2.c_str());

		rodzaj_static.push_back(CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER |
			SS_LEFT, 550, 265 + 35 * i, 100, 35, hWnd, (HMENU)BIALY, hInst, NULL));

 
		std::wstring t3 = dokument.get_rodzaj();
		int fontsize = 10;
		int stringsize = t3.size();
		if (stringsize < 15) fontsize = 13;
		else if (stringsize >= 15 && stringsize < 30) fontsize = 12;
		
		
		HFONT hFont = CreateFont(fontsize, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE, TEXT("Tahoma"));
		SetWindowText(rodzaj_static[i], (LPWSTR)t3.c_str());
		SendMessage(rodzaj_static[i], WM_SETFONT, (WPARAM)hFont, TRUE);

		edit_button.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"E", WS_CHILD | WS_VISIBLE |
			WS_BORDER, 650, 265 + 35 * i, 25, 35, hWnd, (HMENU)(10001 + i), hInst, NULL));

		delete_button.push_back(CreateWindowEx(WS_EX_CLIENTEDGE, L"BUTTON", L"D", WS_CHILD | WS_VISIBLE |
			WS_BORDER, 675, 265 + 35 * i, 25, 35, hWnd, (HMENU)(10101 + i), hInst, NULL));
	}


}

int line::what_size()
{
	return dokumenty.size();
}


void line::del()
{
	for (int i = 0; i < dokumenty.size(); i++)
	{
		DestroyWindow(lp_static[i]);
		DestroyWindow(date_static[i]);
		DestroyWindow(symbol_static[i]);
		DestroyWindow(tresc_static[i]);
		DestroyWindow(kwota_static[i]);
		DestroyWindow(rodzaj_static[i]);
		DestroyWindow(edit_button[i]);
		DestroyWindow(delete_button[i]);
	}
}
line::~line()
{

}
