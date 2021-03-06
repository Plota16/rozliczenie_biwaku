// Rozliczenie_Biwaku.cpp : definiuje punkt wejścia dla aplikacji
//

#include "stdafx.h"
#include "Rozliczenie_Biwaku.h"

#define MAX_LOADSTRING 100

// Zmienne globalne:
HWND hDlg,hDlg2,hDlg3,hDlg4, hCombo;
HWND hWnd;
HINSTANCE hInst;                                // bieżące wystąpienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytułu
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna głównego
HFONT hFont = CreateFont(12, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
	OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
	DEFAULT_PITCH | FF_DONTCARE, TEXT("Tahoma"));
// Przekaż dalej deklaracje funkcji dołączonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About2(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About3(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About4(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieść kod.

    // Zainicjuj ciągi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ROZLICZENIEBIWAKU, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ROZLICZENIEBIWAKU));

    MSG msg;

    // Główna pętla wiadomości:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klasę okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ROZLICZENIEBIWAKU));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_ROZLICZENIEBIWAKU);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje dojście wystąpienia i tworzy okno główne
//
//   KOMENTARZE:
//
//        W tej funkcji dojście wystąpienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyświetlane okno główne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojście wystąpienia w zmiennej globalnej

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      300, 10, 760, 800, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomości dla okna głównego.
//
//  WM_COMMAND — przetwarzaj menu aplikacji
//  WM_PAINT — pomaluj okno główne
//  WM_DESTROY — opublikuj komunikat o rezygnacji i wróć
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
			if (wmId > 10000)
			{
				int x = wmId % 10000;
				if (x > 100)
				{
					x = x / 100;
					dokument.erase(dokument.begin()+x-1);
					linia.del();
					linia.set(dokument, hWnd, hInst);
					linia.draw();
				}
				else
				{
					parameter = x;
					DialogBox(hInst, MAKEINTRESOURCE(129), hWnd, About2);
				}
			}
			else
			{
				switch (wmId)
				{
				case ID_DODAJ_DOKUMENT:
					DialogBox(hInst, MAKEINTRESOURCE(129), hWnd, About);
					break;
				case IDM_SAVE:
					try
					{
						plik.update(okno.get_start_date(), okno.get_date(), okno.get_number(), dokument);
						plik.save();
					}
					catch (std::wstring wyjatek)
					{
						LPWSTR x = (LPWSTR)wyjatek.c_str();
						MessageBox(hWnd, x, L"Błąd", NULL);
					}
					break;
				case IDM_LOAD:
					try
					{
						dokument = plik.load();
					}
					catch (std::wstring wyjatek)
					{
						LPWSTR x = (LPWSTR)wyjatek.c_str();
						MessageBox(hWnd, x, L"Błąd", NULL);
					}
					
					linia.del();
					linia.set(dokument, hWnd, hInst);
					if (linia.what_size() != 0)
					{
						linia.draw();
					}
					break;
				case ID_GENERUJ_CSV:
					try
					{
						generuj.update(dokument, okno.get_date(), okno.get_number());
						generuj.save();
					}
					catch (std::wstring wyjatek)
					{
						LPWSTR x = (LPWSTR)wyjatek.c_str();
						MessageBox(hWnd, x, L"Błąd", NULL);
					}
				case ID_PRELIMINARZ:
					DialogBox(hInst, MAKEINTRESOURCE(131), hWnd, About3);
					break;
				case ID_ZALICZKI:
					DialogBox(hInst, MAKEINTRESOURCE(132), hWnd, About4);
					break;
				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
				}
			}
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

			HBRUSH PedzelZiel, Pudelko;
			HPEN OlowekCzerw, Piornik;
			PedzelZiel = CreateSolidBrush(0x3CA821);
			OlowekCzerw = CreatePen(PS_DOT, 1, 0xFFFFFF);
			Pudelko = (HBRUSH)SelectObject(hdc, PedzelZiel);
			Piornik = (HPEN)SelectObject(hdc, OlowekCzerw);
			Rectangle(hdc, 0, 0, 750, 2000);
			SelectObject(hdc, Pudelko);
			SelectObject(hdc, Piornik);
			DeleteObject(OlowekCzerw);
			DeleteObject(PedzelZiel);

			okno.paint(hdc);
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_CREATE:
		{
		okno.render(hWnd, hInst);
		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_CTLCOLORSTATIC:
	{
		if (GetDlgCtrlID((HWND)lParam) == BIALY) // Target the specific component
		{
			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkColor(hdcStatic, RGB(255, 255, 255));
			return (INT_PTR)CreateSolidBrush(RGB(255, 255, 255));
		}
	}
	break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obsługi wiadomości dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH testBrush;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{
		hCombo = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN | CBS_AUTOHSCROLL,
			154, 170, 188, 330, hDlg, NULL, hInst, NULL);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"materialy");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"trasport");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wyzywienie");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zakup sprzetu do 9999,99");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zakup sprzetu od 10000");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"oplaty komunalne");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"uslugi obce w tym pocztowo-komunikacyjne");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wywoz odpadow stalych");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"woda i scieki");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wynagrodzenie z umowy zlecenia netto");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"skladka z tytulu ubezpieczen spolecznych");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"podatek od umowy zlecenia");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zuzycie paliw");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"podroze slozbowe");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"koszty zakwaterowania");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wydatki programowe (wstepy)");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"pozostale koszty");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"koszty posrednie");


		SendMessage(hCombo, WM_SETFONT, (WPARAM)hFont, TRUE);

		return (INT_PTR)TRUE;
	}
	break;
	//case WM_CTLCOLORDLG:
	//return (INT_PTR)(testBrush);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == 1007)
		{
			dialog_box dialog(hDlg);
			std::wstring tmp, tmp2, tmp3, tmp4;
			int state = 0;
			try
			{
				tmp = dialog.get_a(hDlg), tmp2 = dialog.get_b(hDlg), tmp3 = dialog.get_c(hDlg), tmp4 = dialog.get_e(hCombo);
				date datatmp(tmp);
				document dokumenttmp(datatmp, tmp2, tmp3, dialog.get_d(hDlg), tmp4);
				dokument.push_back(dokumenttmp);
			}

			catch (std::wstring wyjatek)
			{
				state = 1;
				LPWSTR x = (LPWSTR)wyjatek.c_str();
				MessageBox(hWnd, x, L"Błąd", NULL);
			}


			linia.del();
			linia.set(dokument, hWnd, hInst);
			linia.sort();
			dokument = linia.get_dokumenty();
			if (linia.what_size() != 0)
			{
				linia.draw();
			}
			//else MessageBox(hWnd, L"Błąd size 0", L"Błąd size 0", NULL);


			if (state == 0)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK About2(HWND hDlg2, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH testBrush;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{
		std::wstring tmp1 = dokument[parameter - 1].get_data();
		std::wstring tmp2 = dokument[parameter - 1].get_symbol();
		std::wstring tmp3 = dokument[parameter - 1].get_tresc();
		std::wstring tmp4 = dokument[parameter - 1].get_kwota();
		std::wstring tmp5 = dokument[parameter - 1].get_rodzaj();
		SetDlgItemText(hDlg2, 1001, (LPWSTR)tmp1.c_str());
		SetDlgItemText(hDlg2, 1002, (LPWSTR)tmp2.c_str());
		SetDlgItemText(hDlg2, 1003, (LPWSTR)tmp3.c_str());
		SetDlgItemText(hDlg2, 1004, (LPWSTR)tmp4.c_str());
		hCombo = CreateWindowEx(WS_EX_CLIENTEDGE, L"COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN | CBS_AUTOHSCROLL,
			154, 170, 188, 330, hDlg2, NULL, hInst, NULL);

		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"materialy");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"trasport");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wyzywienie");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zakup sprzetu do 9999,99");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zakup sprzetu od 10000");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"oplaty komunalne");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"uslugi obce w tym pocztowo-komunikacyjne");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wywoz odpadow stalych");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"woda i scieki");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wynagrodzenie z umowy zlecenia netto");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"skladka z tytulu ubezpieczen spolecznych");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"podatek od umowy zlecenia");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"zuzycie paliw");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"podroze slozbowe");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"koszty zakwaterowania");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"wydatki programowe (wstepy)");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"pozostale koszty");
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"koszty posrednie");

		SendMessage(hCombo, WM_SETFONT, (WPARAM)hFont, TRUE);
		SetWindowText(hCombo, (LPWSTR)tmp5.c_str());
		return (INT_PTR)TRUE;
	}
	break;
	//case WM_CTLCOLORDLG:
	//return (INT_PTR)(testBrush);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg2, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == 1007)
		{

			dialog_box dialog(hDlg2);
			std::wstring tmp, tmp2, tmp3, tmp4;
			int state = 0;
			try
			{
				tmp = dialog.get_a(hDlg2), tmp2 = dialog.get_b(hDlg2), tmp3 = dialog.get_c(hDlg2), tmp4 = dialog.get_e(hCombo);
				date datatmp(tmp);
				document dokumenttmp(datatmp, tmp2, tmp3, dialog.get_d(hDlg2), tmp4);
				dokument[parameter - 1] = dokumenttmp;
			}

			catch (std::wstring wyjatek)
			{
				state = 1;
				LPWSTR x = (LPWSTR)wyjatek.c_str();
				MessageBox(hWnd, x, L"Błąd", NULL);
			}


			linia.del();
			linia.set(dokument, hWnd, hInst);
			linia.sort();
			dokument = linia.get_dokumenty();
			if (linia.what_size() != 0)
			{
				linia.draw();
			}
			//else MessageBox(hWnd, L"Błąd size 0", L"Błąd size 0", NULL);


			if (state == 0)
			{
				EndDialog(hDlg2, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK About3(HWND hDlg3, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH testBrush;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{
			std::wstring tmp = std::to_wstring(preliminarz.materialy);
			SetDlgItemText(hDlg3, 1014,(LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.transport);
			SetDlgItemText(hDlg3, 1015, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.wyzywienie);
			SetDlgItemText(hDlg3, 1016, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.zakup_sprzetu_do_9999);
			SetDlgItemText(hDlg3, 1017, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.zakup_sprzetu_od_10000);
			SetDlgItemText(hDlg3, 1018, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.oplaty_komunalne);
			SetDlgItemText(hDlg3, 1019, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.uslugi_obce);
			SetDlgItemText(hDlg3, 1020, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.wywoz_odpadow_stalych);
			SetDlgItemText(hDlg3, 1021, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.woda_i_scieki);
			SetDlgItemText(hDlg3, 1022, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.wynagrodzenia_z_umowy_zlecenia_netto);
			SetDlgItemText(hDlg3, 1023, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.skladka_z_tytulu_ubezpieczen_spoleczych);
			SetDlgItemText(hDlg3, 1024, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.podatek_od_umowy_zlecenia);
			SetDlgItemText(hDlg3, 1025, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.zuzycie_paliw);
			SetDlgItemText(hDlg3, 1026, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.podroze_sluzbowe);
			SetDlgItemText(hDlg3, 1027, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.koszty_zakwaterowania);
			SetDlgItemText(hDlg3, 1028, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.wydatki_progarmowe);
			SetDlgItemText(hDlg3, 1029, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.pozostale_koszy);
			SetDlgItemText(hDlg3, 1030, (LPWSTR)tmp.c_str());
			tmp = std::to_wstring(preliminarz.koszty_posrednie);
			SetDlgItemText(hDlg3, 1031, (LPWSTR)tmp.c_str());
	}
	break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
				EndDialog(hDlg3, LOWORD(wParam));
				return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == 1032)
		{
			try
			{
				preliminarz.set(hDlg3);
			}
			catch (std::wstring wyjatek)
			{
				preliminarz.state = 1;
				LPWSTR x = (LPWSTR)wyjatek.c_str();
				MessageBox(hWnd, x, L"Błąd", NULL);
			}
			if (preliminarz.state == 0)
			{
				EndDialog(hDlg3, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK About4(HWND hDlg4, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBRUSH testBrush;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{		
		if (zaliczki.size() > 0)
		{
			std::wstring wynik;
			for (int i = 0; i < zaliczki.size(); i++)
			{
				wynik += zaliczki[i].get_date().print_date() + L"\t|\t" + std::to_wstring(zaliczki[i].get_amount()) + L"\r\n";
			}
			SetDlgItemText(hDlg4, 1034, (LPWSTR)wynik.c_str());
		}
	}
	break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg4, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == 1033)
		{
			advance_dialog zaliczka_dialog(hDlg4);
			try
			{
			zaliczka.set(zaliczka_dialog.get_date(), zaliczka_dialog.get_amount());
			}
			catch(std::wstring wyjatek)
			{
				zaliczka_dialog.set_state(1);
				LPWSTR xd = (LPWSTR)wyjatek.c_str();
				MessageBox(hWnd, xd, L"Błąd", NULL);
			}
			if(zaliczka_dialog.get_state() == 0) zaliczki.push_back(zaliczka);
			std::wstring wynik;
			for (int i = 0; i < zaliczki.size(); i++)
			{
				wynik += zaliczki[i].get_date().print_date() + L"\t|\t" + std::to_wstring(zaliczki[i].get_amount()) + L"\r\n";
			}
			SetDlgItemText(hDlg4, 1034, (LPWSTR)wynik.c_str());
		}
		break;
	}
	return (INT_PTR)FALSE;
}