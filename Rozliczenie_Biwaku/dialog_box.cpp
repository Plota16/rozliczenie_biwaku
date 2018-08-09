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
	return tmp;
}

std::wstring dialog_box::get_b(HWND hDlg)
{
	std::wstring tmp = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetDlgItemTextW(hDlg, 1002, Ltmp, 20);
	tmp = Ltmp;
	return tmp;

}

std::wstring dialog_box::get_c(HWND hDlg)
{
	std::wstring tmp = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetDlgItemTextW(hDlg, 1003, Ltmp, 20);
	tmp = Ltmp;
	return tmp;
}

double dialog_box::get_d(HWND hDlg)
{
	std::wstring tmpstr = L"0123456789";
	LPWSTR Ltmp = (LPWSTR)tmpstr.c_str();
	GetDlgItemTextW(hDlg, 1004, Ltmp, 20);
	tmpstr = Ltmp;
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
	return std::stod(tmpstr);
}

std::wstring dialog_box::get_e(HWND hCombo)
{
	std::wstring tmp = L"0123456789000000000000000000000000000000000000";
	LPWSTR Ltmp = (LPWSTR)tmp.c_str();
	GetWindowText(hCombo, Ltmp, 200);
	tmp = Ltmp;
	return tmp;
}