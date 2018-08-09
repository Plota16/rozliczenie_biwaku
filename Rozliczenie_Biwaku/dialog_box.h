#pragma once
class dialog_box
{
public:
	dialog_box(HWND hDlg);
	~dialog_box();
	std::wstring get_a(HWND hDlg);
	std::wstring get_b(HWND hDlg);
	std::wstring get_c(HWND hDlg);
	double get_d(HWND hDlg);
	std::wstring get_e(HWND hCombo);

};

