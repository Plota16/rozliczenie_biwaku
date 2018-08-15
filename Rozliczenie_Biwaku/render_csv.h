#pragma once
class render_csv
{
public:
	render_csv();
	void update(std::vector<document> Xdokumenty, date Xdata, std::wstring Xnumber);
	std::wstring prepare_text();
	std::string to_utf8(const wchar_t* buffer, int len);
	std::string to_utf8(const std::wstring& str);
	void save();
	~render_csv();

private:
	std::wstring data;
	std::wstring kontachent;
	OPENFILENAME ofn;
	std::vector<document> dokumenty;

};

