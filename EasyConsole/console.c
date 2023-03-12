#include <stdio.h>
#include <stdbool.h>
#include <consoleapi.h>
#include <conio.h>
#include "console.h"

int keycode1 = 0;
int keycode2 = 0;

//初始化 console_ 系列函数。在调用任何 console_ 系列函数之前必须先调用此函数。
void console_init()
{
	HANDLE stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(stdout_handle, &mode);
	mode |= 0x0004;
	SetConsoleMode(stdout_handle, mode);
}

//清空屏幕内容。
void console_clear()
{
	//https://codehs.com/tutorial/andy/clearing-the-console
	printf("\033[H\033[2J");
}

//将光标移动到第 row 行第 column 列。
void console_goto(int row, int column)
{
	printf("\x1b[%d;%dH", row, column);
}

//设置控制台窗口大小
void console_set_size(int lines, int columns)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rectWindow = { 0, 0, columns - 1, lines - 1 };
	COORD coordScreen = { columns, lines };
	SetConsoleWindowInfo(console, TRUE, &rectWindow);
	SetConsoleScreenBufferSize(console, coordScreen);
}

//取得当前控制台窗口的大小
void console_get_size(int *rows, int *columns)
{
	//https://stackoverflow.com/questions/23369503/get-size-of-terminal-window-rows-columns
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	*rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

//开始检测按键
bool console_key_begin()
{
	if (_kbhit())
	{
		keycode1 = _getch();
		//对于方向键、功能键，需要调用两次 _getch()，第一次是 0 或 0xE0，第二次是实际键代码
		//https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/getch-getwch?view=msvc-170
		if (keycode1 == 0 || keycode1 == 0xE0)
			keycode2 = _getch();
		return true;
	}
	return false;
}

//指定按键是否按下
bool console_key_down(int key)
{
	if (keycode1 == 0 || keycode1 == 0xE0)
		return keycode2 == key;
	else
		return key == keycode1;
}

//结束检测按键
void console_key_end()
{
	keycode1 = 0;
	keycode2 = 0;
}

//设置是否显示光标
void console_set_cursor(bool show)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

//设置线条样式
void console_set_line_style(LINE_STYLE style) 
{
	switch (style) 
	{
		//\x1B(0：进入 VT100 图形模式
		//\x1B(B：退出 VT100 图形模式
		//\q    ：
		//\x74  ：
		//\x78  ：
	case LINE_SINGLE:
		printf("\x1b(0\x6a\x1b(B");
		break;
	case LINE_DOUBLE:
		printf("\x1b(0\x6b\x1b(B");
		break;
	case LINE_NONE:
		printf("\x1b(0\x6c\x1b(B");
		break;
	default:
		break;
	}
}

//设置文本颜色
void console_set_text_color(COLOR color) 
{
	switch (color) 
	{
	case COLOR_BLACK:
		printf("\x1b[30m");
		break;
	case COLOR_RED:
		printf("\x1b[31m");
		break;
	case COLOR_GREEN:
		printf("\x1b[32m");
		break;
	case COLOR_YELLOW:
		printf("\x1b[33m");
		break;
	case COLOR_BLUE:
		printf("\x1b[34m");
		break;
	case COLOR_MAGENTA:
		printf("\x1b[35m");
		break;
	case COLOR_CYAN:
		printf("\x1b[36m");
		break;
	case COLOR_WHITE:
		printf("\x1b[37m");
		break;
	default:
		break;
	}
}

//设置背景颜色
void console_set_background_color(COLOR color)
{
	switch (color) 
	{
	case COLOR_BLACK:
		printf("\x1b[40m");
		break;
	case COLOR_RED:
		printf("\x1b[41m");
		break;
	case COLOR_GREEN:
		printf("\x1b[42m");
		break;
	case COLOR_YELLOW:
		printf("\x1b[43m");
		break;
	case COLOR_BLUE:
		printf("\x1b[44m");
		break;
	case COLOR_MAGENTA:
		printf("\x1b[45m");
		break;
	case COLOR_CYAN:
		printf("\x1b[46m");
		break;
	case COLOR_WHITE:
		printf("\x1b[47m");
		break;
	default:
		break;
	}
}

void console_text_center(char *text, int row, int column_from, int column_to)
{
	console_goto(row, 1);

	if (text == NULL)
		return;
	int text_len = strlen(text);
	int center = (column_from + column_to) / 2;
	int text_start = center - text_len / 2;

	//如果文本起始列小于输出区域的起始列，则将文本起始列设为输出区域的起始列
	if (text_start < column_from)
		text_start = column_from;

	//如果文本结束列大于输出区域的结束列，则将文本结束列设为输出区域的结束列
	if (text_start + text_len > column_to)
		text_start = column_to - text_len;

	//文本
	console_goto(row, text_start);
	printf("%s", text);
}

//绘制矩形框
void console_box(int row1, int column1, int row2, int column2)
{
	int i, j;
	//画上边框
	printf("\x1B(0"); //进入 VT100 图形模式
	printf("\x6C"); //左上角
	for (i = 1; i < column2 - column1; i++) 
	{
		printf("\x71"); //横线
	}
	printf("\x6B"); //右上角

	printf("\n");
	//画中间部分
	for (i = row1 + 1; i < row2; i++) 
	{
		printf("\x1B(0"); //进入 VT100 图形模式
		printf("\x78"); //竖线
		for (j = 1; j < column2 - column1; j++) 
		{
			printf(" "); //空白
		}
		printf("\x78"); //竖线

		printf("\n");
	}
	//画下边框
	printf("\x6D"); //左下角
	for (i = 1; i < column2 - column1; i++) 
	{
		printf("\x71"); //横线
	}
	printf("\x6A"); //右下角
	printf("\x1B(B"); //退出 VT100 图形模式
	printf("\n");
}

//画竖线
void console_line_vertical(int row1, int row2, int column)
{
	int i;
	for (i = row1; i <= row2; i++) 
	{
		printf("\x1B[%d;%dH", i, column); //光标移到指定行开头
		printf("\x78"); //画竖线
	}
}

//画横线
void console_line_horizontal(int col1, int col2, int row)
{
	int i;
	printf("\x1B[%d;%dH", row, col1); //将光标移动到指定行列
	for (i = col1; i <= col2; i++)
	{
		printf("\x2D"); //画横线
	}
}