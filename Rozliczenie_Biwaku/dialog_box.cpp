#include "stdafx.h"
#include "dialog_box.h"


dialog_box::dialog_box(HWND hDlg)
{

}


dialog_box::~dialog_box()
{
}


std::wstring dialog_box::get_a(HWND hDlg)
{
	std::wstring tmp = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetDlgItemTextW(hDlg, 1001, Ltmp, 20);
	tmp = Ltmp;
	if (tmp.empty())
	{
		std::wstring wyjatek = L"Nie wypełniono pola: Data";
		throw wyjatek;
	}
	return tmp;
}

std::wstring dialog_box::get_b(HWND hDlg)
{
	std::wstring tmp = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetDlgItemTextW(hDlg, 1002, Ltmp, 20);
	tmp = Ltmp;
	if (tmp.empty())
	{
		std::wstring wyjatek = L"Nie wypelniono pola: Symbol";
		throw wyjatek;
	}
	return tmp;

}

std::wstring dialog_box::get_c(HWND hDlg)
{
	std::wstring tmp = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetDlgItemTextW(hDlg, 1003, Ltmp, 20);
	tmp = Ltmp;
	if (tmp.empty())
	{
		std::wstring wyjatek = L"Nie wypelniono pola: Treść";
		throw wyjatek;
	}
	return tmp;
}

double dialog_box::get_d(HWND hDlg)
{
	std::wstring tmpstr = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmpstr.c_str();
	GetDlgItemTextW(hDlg, 1004, Ltmp, 20);
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
	for (int i = 0; i < tmpstr2.size(); i++)
	{
		char x = tmpstr2[i];
		int a = (int)x;
		if (i == 0)
		{
			if (a > 57 || a < 48)
			{
				std::wstring wyjatek = L"Podano błędną kwotę";
				throw wyjatek;
			}
		}
		if (i != dot_position && i != 0)
			if (a > 57 || a < 48)
			{
				std::wstring wyjatek = L"Podano błędną kwotę";
				throw wyjatek;
			}
	}
	return std::stod(tmpstr2);
}

std::wstring dialog_box::get_e(HWND hCombo)
{
	std::wstring tmp = L"0123456789000000000000000000000000000000000000";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetWindowText(hCombo, Ltmp, 200);
	tmp = Ltmp;
	if (tmp.empty())
	{
		std::wstring wyjatek = L"Nie wypelniono pola: Rodzaj";
		throw wyjatek;
	}
	return tmp;
}