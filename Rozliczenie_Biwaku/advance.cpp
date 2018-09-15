#include "stdafx.h"
#include "advance.h"

advance::advance()
{

}
void advance::set(date Xdata, double Xamount)
{
	data = Xdata;
	amount = Xamount;
}


advance::~advance()
{
}

date advance::get_date()
{
	return data;
}

double advance::get_amount()
{
	return amount;
}