#pragma once
class advance
{
public:
	advance();
	~advance();
	date get_date();
	double get_amount();
	void set(date data, double amount);


private:
	date data;
	double amount;
};

