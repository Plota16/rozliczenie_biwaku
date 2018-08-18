#include "stdafx.h"
#include "render_csv.h"


render_csv::render_csv()
{

}

void render_csv::update(std::vector<document> Xdokument, date Xdata, std::wstring number)
{
	dokumenty = Xdokument;
	int miesiac = Xdata.get_month();
	int rok = Xdata.get_year();
	int dzien;
	if (miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 11 || miesiac == 12) dzien = 31;
	else if (miesiac == 2) dzien = 28;
	else dzien = 30;
	data = std::to_wstring(rok) + L"-" + std::to_wstring(miesiac) + L"-" + std::to_wstring(dzien);
	if (number.size() == 8 || number.size() == 9) kontachent = number;
	else kontachent = number + L"/51/2018";
}
std::wstring render_csv::prepare_text()
{
	std::wstring tmp;
	std::wstring coma = L";";
	std::wstring enter = L"\n";
	
	for (int i=0; i < dokumenty.size(); i++)
	{
		document tmpdoc = dokumenty[i];
		std::wstring x = tmpdoc.get_kwota();
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == '.') x[i] = ',';
		}
		tmp += std::to_wstring(i + 1) + coma + data + coma + kontachent + coma + tmpdoc.get_symbol() + coma + tmpdoc.get_tresc() + coma + x + coma;
		if (i != dokumenty.size() - 1) tmp += enter;
	}
	return tmp;
}

std::string render_csv::to_utf8(const wchar_t* buffer, int len)
{
	int nChars = ::WideCharToMultiByte(
		CP_UTF8,
		0,
		buffer,
		len,
		NULL,
		0,
		NULL,
		NULL);
	if (nChars == 0) return "";

	std::string newbuffer;
	newbuffer.resize(nChars);
	::WideCharToMultiByte(
		CP_UTF8,
		0,
		buffer,
		len,
		const_cast< char* >(newbuffer.c_str()),
		nChars,
		NULL,
		NULL);

	return newbuffer;
}

std::string render_csv::to_utf8(const std::wstring& str)
{
	return to_utf8(str.c_str(), (int)str.size());
}

void render_csv::save()
{
	LPWSTR sNazwaPliku = (LPWSTR)GlobalAlloc(GPTR, 260);
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = L"Plik CSV (*.csv)\0*.csv\0Wszystkie pliki\0*.*\0";
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFile = sNazwaPliku;
	ofn.lpstrDefExt = L"csv";
	ofn.Flags = OFN_CREATEPROMPT | OFN_HIDEREADONLY;
	if (GetSaveFileName(&ofn))
	{
		DWORD dwRozmiar, dwZapisane;
		HANDLE hPlik;
		

		hPlik = CreateFile(sNazwaPliku, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
		if (hPlik == INVALID_HANDLE_VALUE) {
			MessageBox(NULL, L"Nie mo¿na otworzyæ pliku.", L"A to pech!", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakoñcz program
		}


		std::wstring wynik = prepare_text();
		std::string tmp = to_utf8(wynik);
		if (!WriteFile(hPlik,tmp.c_str(), tmp.size(), &dwZapisane, NULL)) {
			MessageBox(NULL, L"Błąd zapisu do pliku", L"Dupa blada!", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakoñcz program
		}
		tmp.clear();
		wynik.clear();
		
		CloseHandle(hPlik); // Zamknij plik
	}

}


render_csv::~render_csv()
{
}
