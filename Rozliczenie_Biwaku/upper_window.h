#pragma once
class upper_window
{
public:
	upper_window(int left,int top,int right,int bottom);
	~upper_window();
	void render(HWND XhWnd, HINSTANCE XhInst);
	void paint(HDC hdc);

private:
	int left;
	int top;
	int right;
	int bottom;
	HWND add_document;
	HWND date1_static;
	HWND date2_static;
	HWND date1_edit;
	HWND date2_edit;
	HWND number_static;
	HWND number_edit;
};

