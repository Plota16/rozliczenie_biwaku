#include "stdafx.h"
#include "date.h"

date::date()
{

}
date::date(std::wstring text)
{
	if (text.size() != 8 && text.size() != 10) 
	{
		std::wstring wyjatek = L"Podan¹ b³êdn¹ datê";
		throw wyjatek;
	}
	else
	{
		if (text[2] == '.' || text[2] == '-')
		{
			std::wstring tmpday = L"";
			for (int i = 0; i < 2; i++)
			{
				char x = text.at(i);
				int a = (char)x;
				if (a > 57 || a < 48)
				{
					std::wstring wyjatek = L"Podano b³êdny dzien";
					throw wyjatek;
				}
			}
			tmpday += text.at(0);
			tmpday += text.at(1);
			if (std::stoi(tmpday) > 31)
			{
				std::wstring wyjatek = L"Podano b³êdny dzieñ";
				throw wyjatek;
			}
			else day = std::stoi(tmpday);

			std::wstring tmpmonth = L"";
			for (int i = 3; i < 5; i++)
			{
				char x = text.at(i);
				int a = (char)x;
				if (a > 57 || a < 48)
				{
					std::wstring wyjatek = L"Podano b³êdny miesi¹c";
					throw wyjatek;
				}
			}
			tmpmonth += text[3];
			tmpmonth += text[4];
			if (std::stoi(tmpmonth) > 12)
			{
				std::wstring wyjatek = L"Podano b³êdny miesi¹c";
				throw wyjatek;
			}
			else month = std::stoi(tmpmonth);

			std::wstring tmpyear = L"20";
			if (text.size() == 8)
			{
				for (int i = 6; i < 8; i++)
				{
					char x = text.at(i);
					int a = (char)x;
					if (a > 57 || a < 48)
					{
						std::wstring wyjatek = L"Podano b³êdny rok";
						throw wyjatek;
					}

				}
				tmpyear += text[6];
				tmpyear += text[7];
			}
			else if (text.size() == 10)
			{
				tmpyear = L"";
				for (int i = 6; i < 10; i++)
				{
					char x = text.at(i);
					int a = (char)x;
					if (a > 57 || a < 48)
					{
						std::wstring wyjatek = L"Podano b³êdny rok";
						throw wyjatek;
					}
				}
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
			for (int i = 0; i < 4; i++)
			{
				char x = text.at(i);
				int a = (char)x;
				if (a > 57 || a < 48)
				{
					std::wstring wyjatek = L"Podano b³êdny rok";
					throw wyjatek;
				}

			}
			tmpyear += text[0];
			tmpyear += text[1];
			tmpyear += text[2];
			tmpyear += text[3];
			year = std::stoi(tmpyear);


			std::wstring tmpmonth = L"";
			for (int i = 5; i < 7; i++)
			{
				char x = text.at(i);
				int a = (char)x;
				if (a > 57 || a < 48)
				{
					std::wstring wyjatek = L"Podano b³êdny miesi¹c";
					throw wyjatek;
				}

			}
			tmpmonth += text[5];
			tmpmonth += text[6];
			if (std::stoi(tmpmonth) > 12)
			{
				std::wstring wyjatek = L"Podano b³êdny miesi¹c";
				throw wyjatek;
			}
			else month = std::stoi(tmpmonth);

			std::wstring tmpday = L"";
			for (int i = 8; i < 10; i++)
			{
				char x = text.at(i);
				int a = (char)x;
				if (a > 57 || a < 48)
				{
					std::wstring wyjatek = L"Podano b³êdny dzien";
					throw wyjatek;
				}

			}
			tmpday += text.at(8);
			tmpday += text.at(9);
			if (std::stoi(tmpday) > 31)
			{
				std::wstring wyjatek = L"Podano b³êdny dzieñ";
				throw wyjatek;
			}
			else day = std::stoi(tmpday);

		}
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
