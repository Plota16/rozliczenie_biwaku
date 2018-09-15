#include "stdafx.h"
#include "preliminary.h"


preliminary::preliminary()
{
	state = 0;
	materialy - 0;
	transport = 0;
	wyzywienie = 0;
	zakup_sprzetu_do_9999 = 0;
	zakup_sprzetu_od_10000 = 0;
	oplaty_komunalne = 0;
	uslugi_obce = 0;
	wywoz_odpadow_stalych = 0;
	woda_i_scieki = 0;
	wynagrodzenia_z_umowy_zlecenia_netto = 0;
	skladka_z_tytulu_ubezpieczen_spoleczych = 0;
	podatek_od_umowy_zlecenia = 0;
	zuzycie_paliw = 0;
	podroze_sluzbowe = 0;
	koszty_zakwaterowania = 0;
	wydatki_progarmowe = 0;
	pozostale_koszy = 0;
	koszty_posrednie = 0;

}

double preliminary::get(int i)
{
	std::wstring tmpstr = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmpstr.c_str();
	GetDlgItemTextW(hDlg, i, Ltmp, 20);
	tmpstr = Ltmp;
	if (tmpstr.empty())
	{
		std::wstring wyjatek = L"Nie wypelniono pola: Kwota";
		throw wyjatek;
	}
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
	else
	{
		for (int i = 0; i < tmpstr.size(); i++)
		{
			tmpstr2 += tmpstr[i];
		}
	}
	tmpstr2 += L".";
	if (dot_position == 0)
	{
		dot_position = tmpstr.size();
		tmpstr2 += L"0";
		tmpstr2 += L"0";
	}
	else
	{
		tmpstr2 += tmpstr[dot_position + 1];
		tmpstr2 += tmpstr[dot_position + 2];
	}
	for (int i = 0; i < tmpstr2.size()-1; i++)
	{
		char x = tmpstr2[i];
		int a = (int)x;
		if (i == 0)
		{
			if (a > 57 || a < 48)
			{
				std::wstring wyjatek = L"Podano b³êdn¹ kwotê";
				throw wyjatek;
			}
		}
		if (i != dot_position && i != 0)
			if (a > 57 || a < 48)
			{
				std::wstring wyjatek = L"Podano b³êdn¹ kwotê";
				throw wyjatek;
			}
	}

	return std::stod(tmpstr2);
}

void preliminary::set(HWND XhDlg)
{
		hDlg = XhDlg;
		materialy = get(1014);
		transport = get(1015);
		wyzywienie = get(1016);
		zakup_sprzetu_do_9999 = get(1017);
		zakup_sprzetu_od_10000 = get(1018);
		oplaty_komunalne = get(1019);
		uslugi_obce = get(1020);
		wywoz_odpadow_stalych = get(1021);
		woda_i_scieki = get(1022);
		wynagrodzenia_z_umowy_zlecenia_netto = get(1023);
		skladka_z_tytulu_ubezpieczen_spoleczych = get(1024);
		podatek_od_umowy_zlecenia = get(1025);
		zuzycie_paliw = get(1026);
		podroze_sluzbowe = get(1027);
		koszty_zakwaterowania = get(1028);
		wydatki_progarmowe = get(1029);
		pozostale_koszy = get(1030);
		koszty_posrednie = get(1031);

}

preliminary::~preliminary()
{
}
