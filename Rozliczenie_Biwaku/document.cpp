#include "stdafx.h"
#include "document.h"




document::document(date Xdata, std::wstring Xsymbol, std::wstring Xtresc, double Xkwota, std::wstring Xrodzaj)
{
	data = Xdata;
	symbol = Xsymbol;
	tresc = Xtresc;
	kwota = Xkwota;
	rodzaj = Xrodzaj;
}

document::~document()
{
}

std::wstring document::get_symbol()
{
	return symbol;
}

std::wstring document::get_data()
{
	return data.print_date();

}

std::wstring document::get_kwota()
{
	return std::to_wstring(kwota);
}

std::wstring document::get_rodzaj()
{
	return rodzaj;
}

std::wstring document::get_tresc()
{
	return tresc;
}