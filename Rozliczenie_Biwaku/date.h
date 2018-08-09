#pragma once
class date
{
public:
	date(std::wstring text);
	date();
	~date();
	int get_year();
	int get_day();
	int get_month();
	std::wstring print_date();


private:
	int day;
	int month;
	int year;
};

