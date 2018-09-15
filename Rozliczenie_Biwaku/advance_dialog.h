#pragma once
class advance_dialog
{
public:
	advance_dialog(HWND hDlg);
	date get_date();
	double get_amount();
	~advance_dialog();
	int get_state();
	void set_state(int i);

private:
	HWND hDlg;
	int state;
};

