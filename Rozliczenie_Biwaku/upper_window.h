#pragma once
class upper_window
{
public:
	upper_window(int left,int top,int right,int bottom);
	~upper_window();
	void render(HWND XhWnd, HINSTANCE XhInst);
	void paint(HDC hdc);
	date get_start_date();
	date get_date();
	std::wstring get_number();

private:
	int left;
	int top;
	int right;
	int bottom;
	HWND add_document;
	HWND render_report;
	HWND render_report_static;
	HWND render_csv;
	HWND render_csv_static;
	HWND zaliczki;
	HWND zaliczki_static;
	HWND date1_static;
	HWND date2_static;
	HWND date3_static;
	HWND date1_edit;
	HWND date2_edit;
	HWND date3_edit;
	HWND number_static;
	HWND number_edit;
	HWND hufiec_static;
	HWND hufiec_edit;
	HWND komendant_static;
	HWND komendant_edit;
	HWND preliminarz_static;
	HWND preliminarz_button;
};

