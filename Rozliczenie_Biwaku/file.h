#pragma once
class file
{
public:
	file();
	void update(date Xdata_startu,date Xdata_konca,std::wstring Xnumber,std::vector<document> Xdokumenty);
	void save();
	std::vector<document> load();
	std::string to_utf8(const wchar_t* buffer, int len);
	std::string to_utf8(const std::wstring& str);
	~file();

private:
	OPENFILENAME ofn;
	date data_startu;
	date data_konca;
	std::wstring number;
	std::vector<document> dokumenty;
};

