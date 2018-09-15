#pragma once

class document
{
public:
	document(date data, std::wstring symbol, std::wstring tresc, double kwota, std::wstring rodzaj);
	~document();
	std::wstring get_data();
	std::wstring get_symbol();
	std::wstring get_tresc();
	std::wstring get_kwota();
	std::wstring get_rodzaj();
	int get_state();
	void set_state(int i);

private:
	int state;
	date data;
	std::wstring symbol;
	std::wstring tresc;
	double kwota;
	std::wstring rodzaj;
};

