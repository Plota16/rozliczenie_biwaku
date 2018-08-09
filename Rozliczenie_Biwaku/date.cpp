#include "stdafx.h"
#include "date.h"

date::date()
{

}
date::date(std::wstring text)
{
	if (text[2] == '.' || text[2] == '-')
	{
		std::wstring tmpday = L"";
		tmpday += text.at(0);
		tmpday += text.at(1);
		day = std::stoi(tmpday);

		std::wstring tmpmonth = L"";
		tmpmonth += text[3];
		tmpmonth += text[4];
		month = std::stoi(tmpmonth);

		std::wstring tmpyear = L"20";
		if (text.size() == 8)
		{
			tmpyear += text[6];
			tmpyear += text[7];
		}
		else if (text.size() == 10)
		{
			tmpyear = L"";
			tmpyear += text[6];
			tmpyear += text[7];
			tmpyear += text[8];
			tmpyear += text[9];
		}
		year = std::stoi(tmpyear);
	}
	else
	{
			std::wstring tmpyear = L"";
			tmpyear += text[0];
			tmpyear += text[1];
			tmpyear += text[2];
			tmpyear += text[3];
			year = std::stoi(tmpyear);


			std::wstring tmpmonth = L"";
			tmpmonth += text[5];
			tmpmonth += text[6];
			month = std::stoi(tmpmonth);

			std::wstring tmpday = L"";
			tmpday += text.at(8);
			tmpday += text.at(9);
			day = std::stoi(tmpday);

	}
}


date::~date()
{
}

int date::get_day()
{
	return day;
}

int date::get_month()
{
	return month;
}

int date::get_year()
{
	return year;
}

std::wstring date::print_date()
{
	std::wstring tmp = L"";
	tmp += std::to_wstring(year);
	if(month<10) tmp += L"-0";
	else tmp += L"-";
	tmp += std::to_wstring(month);
	if (day < 10) tmp += L"-0";
	else tmp += L"-";
	tmp += std::to_wstring(day);
	return tmp;
}
