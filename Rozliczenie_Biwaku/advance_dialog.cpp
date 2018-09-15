#include "stdafx.h"
#include "advance_dialog.h"


advance_dialog::advance_dialog(HWND XhDlg)
{
	hDlg = XhDlg;
}

int advance_dialog::get_state()
{
	return state;
}

void advance_dialog::set_state(int i)
{
	state = i;
}
double advance_dialog::get_amount()
{
	std::wstring tmp_wstr = L"sadasdasdasda";
	LPWSTR amount_wstr = (LPWSTR)tmp_wstr.c_str();
	GetDlgItemText(hDlg, 1036, amount_wstr, 20);
	std::wstring tmpstr = amount_wstr;
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

date advance_dialog::get_date()
{
	std::wstring tmp_wstr = L"sadasdasdasda";
	LPWSTR date_wstr = (LPWSTR)tmp_wstr.c_str();
	GetDlgItemText(hDlg, 1035, date_wstr, 20);
	std::wstring date_w = date_wstr;
	date tmp_date(date_w);
	return tmp_date;
}

advance_dialog::~advance_dialog()
{
}
