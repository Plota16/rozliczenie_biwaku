#pragma once
class line
{
public:
	line();
	void set(std::vector<document> Xdokument, HWND hWnd, HINSTANCE hInst);
	void del();
	void draw();
	int what_size();
	std::vector<document> get_dokumenty();
	void sort();
	~line();

private:
	std::vector<document> dokumenty;
	int size;
	HWND hWnd;
	HINSTANCE hInst;
	std::vector<HWND> lp_static;
	std::vector<HWND> date_static;
	std::vector<HWND> symbol_static;
	std::vector<HWND> tresc_static;
	std::vector<HWND> kwota_static;
	std::vector<HWND> rodzaj_static;
	std::vector<HWND> edit_button;
	std::vector<HWND> delete_button;
};

