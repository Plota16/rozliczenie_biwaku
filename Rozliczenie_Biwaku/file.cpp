#include "stdafx.h"
#include "file.h"

file::file()
{

}

void file::update(date Xdata_startu, date Xdata_konca, std::wstring Xnumber, std::vector<document> Xdokumenty)
{
	data_startu = Xdata_startu;
	data_konca = Xdata_konca;
	number = Xnumber;
	dokumenty = Xdokumenty;
}


file::~file()
{
}


std::string file::to_utf8(const wchar_t* buffer, int len)
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

std::string file::to_utf8(const std::wstring& str)
{
	return to_utf8(str.c_str(), (int)str.size());
}

void file::save()
{

		LPWSTR sNazwaPliku = (LPWSTR)GlobalAlloc(GPTR, 260);;
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.lpstrFilter = L"Plik txt (*.txt)\0*.txt\0Wszystkie pliki\0*.*\0";
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrFile = sNazwaPliku;
		ofn.lpstrDefExt = L"txt";
		ofn.Flags = OFN_CREATEPROMPT | OFN_HIDEREADONLY;
		if (GetSaveFileName(&ofn))
		{
			DWORD dwRozmiar, dwZapisane;
			HANDLE hPlik;


			hPlik = CreateFile(sNazwaPliku, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
			if (hPlik == INVALID_HANDLE_VALUE)
			{
				MessageBox(NULL, L"Nie mo¿na otworzyæ pliku.", L"A to pech!", MB_ICONEXCLAMATION);
				PostQuitMessage(0); // Zakoñcz program
			}

			std::wstring hash = L"@";
			std::wstring enter = L"";
			std::wstring wynik = hash;

			wynik += number + enter;
			wynik += hash + data_startu.print_date() + enter;
			wynik += hash + data_konca.print_date() + enter;
			for (int i = 0; i < dokumenty.size(); i++)
			{
				document doc = dokumenty[i];
				wynik += hash + doc.get_data() + hash + doc.get_kwota() + hash + doc.get_rodzaj() + hash + doc.get_symbol() + hash + doc.get_tresc() + enter;
			}
			wynik += L"@";




			std::string tmp = to_utf8(wynik);
			if (!WriteFile(hPlik, tmp.c_str(), tmp.size(), &dwZapisane, NULL)) {
				MessageBox(NULL, L"Błąd zapisu do pliku", L"Dupa blada!", MB_ICONEXCLAMATION);
				PostQuitMessage(0); // Zakoñcz program
			}
			tmp.clear();
			wynik.clear();

			CloseHandle(hPlik); // Zamknij plik
		}
	}

std::vector<document> file::load()
{
	LPWSTR sNazwaPliku = (LPWSTR)GlobalAlloc(GPTR, 260);;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFilter = L"Pliki tekstowe (*.txt)\0*.txt\0Wszystkie pliki\0*.*\0";
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFile = sNazwaPliku;
	ofn.lpstrDefExt = L"txt";
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	if (GetOpenFileName(&ofn))
	{
		LPSTR Bufor;
		DWORD dwRozmiar, dwPrzeczyt;
		HANDLE hPlik;
		hPlik = CreateFile(sNazwaPliku, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (hPlik == INVALID_HANDLE_VALUE) {
			MessageBox(NULL, L"Nie można otworzyć pliku.", L"A to pech!", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakończ program
		}

		dwRozmiar = GetFileSize(hPlik, NULL);
		if (dwRozmiar == 0xFFFFFFFF) {
			MessageBox(NULL, L"Nieprawidłowy rozmiar pliku!", L"Niedobrze...", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakończ program
		}

		Bufor = (LPSTR) (GlobalAlloc(GPTR, dwRozmiar + 1));
		if (Bufor == NULL) {
			MessageBox(NULL, L"Za mało pamięci!", L"Ale wiocha...", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakończ program
		}

		if (!ReadFile(hPlik, Bufor, dwRozmiar, &dwPrzeczyt, NULL)) {
			MessageBox(NULL, L"Błąd czytania z pliku", L"Dupa blada!", MB_ICONEXCLAMATION);
			PostQuitMessage(0); // Zakończ program
		}
		std::vector<document> x;
		//Bufor[dwRozmiar] = 0; // dodaj zero na końcu stringa
		std::string wynik = Bufor;
		std::wstring Wwynik;
		int counter = 0;
		std::vector<int>counts;
		for (int i = 0; i < wynik.size(); i++)
		{
			if (wynik[i] == '@') 
			{
				counter++;
				counts.push_back(i);
			}
		}
		std::wstring number = L"";
		std::wstring date1 = L"";
		std::wstring date2 = L"";
		for (int i = counts[0]+1; i < counts[1]; i++)
		{
			number += wynik[i];
		}
		for (int i = counts[1]+1; i < counts[2]; i++)
		{
			date1 += wynik[i];
		}
		for (int i = counts[2] + 1; i < counts[3]; i++)
		{
			date2 += wynik[i];
		}
		int how_many = (counter - 4) / 5;
		counter = 3;
		int tmpc = 0;
		std::wstring data = L"";
		std::wstring symbol = L"";
		std::wstring tresc = L"";
		std::wstring kwota = L"";
		std::wstring rodzaj = L"";
		for (int i = counts[3] +1 ; i <wynik.size(); i++)
		{
			if (i == counts[counter + 1])
			{
				counter++;
				tmpc++;
			}
			if (counter % 5 == 3 && tmpc != 5)
			{
				data += wynik[i];
			}
			if (counter % 5 == 1)
			{
				symbol += wynik[i];
			}
			if (counter % 5 == 2)
			{
				tresc += wynik[i];
			}
			if (counter % 5 == 4)
			{
				kwota += wynik[i];
			}
			if (counter % 5 == 0)
			{
				rodzaj += wynik[i];
			}
			if (tmpc == 5)
			{
				date tmp(data);
				symbol = symbol.substr(1, symbol.size() - 1);
				tresc = tresc.substr(1, tresc.size() - 1);
				kwota = kwota.substr(1, kwota.size() - 1);
				rodzaj = rodzaj.substr(1, rodzaj.size() - 1);

				document doc(tmp, symbol, tresc, stod(kwota), rodzaj);
				x.push_back(doc);
				tmpc = 0;
				data.clear();
				symbol.clear();
				tresc.clear();
				kwota.clear();
				rodzaj.clear();
			}
		}
		
		GlobalFree(Bufor); // Zwolnij bufor
		CloseHandle(hPlik); // Zamknij plik
		return x;
	}
}