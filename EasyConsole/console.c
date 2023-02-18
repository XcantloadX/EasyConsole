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

//标准输出
void console_printf()
{

}

//可设置格式的标准输出
void console_printf_rich()
{

}

//清空屏幕内容。
void console_clear()
{
	//https://codehs.com/tutorial/andy/clearing-the-console
	printf("\033[H\033[2J");
}

//将光标移动到第 x 行第 y 列。
void console_to(int x, int y)
{
	printf("\x1b[%d;%dH", x, y);
}

//设置控制台窗口大小
void console_set_size(int lines, int columns)
{

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

// 设置线条样式
void console_set_line_style(LINE_STYLE style) 
{
	switch (style) 
	{
		// \x1B(0：进入 VT100 图形模式
		// \x1B(B：退出 VT100 图形模式
		// \q    ：
		// \x74  ：
		// \x78  ：
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

// 设置文本颜色
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

// 设置背景颜色
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

// 绘制矩形框
void console_box(int line1, int column1, int line2, int column2)
{
	int i, j;
	// 画上边框
	printf("\x1B(0"); // 进入 VT100 图形模式
	printf("\x6C"); // 左上角
	for (i = 1; i < column2 - column1; i++) 
	{
		printf("\x71"); // 横线
	}
	printf("\x6B"); // 右上角

	printf("\n");
	// 画中间部分
	for (i = line1 + 1; i < line2; i++) 
	{
		printf("\x1B(0"); // 进入 VT100 图形模式
		printf("\x78"); // 竖线
		for (j = 1; j < column2 - column1; j++) 
		{
			printf(" "); // 空白
		}
		printf("\x78"); // 竖线

		printf("\n");
	}
	// 画下边框
	printf("\x6D"); // 左下角
	for (i = 1; i < column2 - column1; i++) 
	{
		printf("\x71"); // 横线
	}
	printf("\x6A"); // 右下角
	printf("\x1B(B"); // 退出 VT100 图形模式
	printf("\n");
}

void console_line_vertical(int line1, int line2) 
{
	int i;
	for (i = line1; i <= line2; i++) 
	{
		printf("\x1B[%d;0H", i); // 光标移到指定行开头
		printf("\x78"); // 画竖线
	}
}



int main()
{
	console_init();
	console_clear();
	//wprintf(L"♬");
	console_box(1, 1, 10, 20);
	console_to(2, 2);
	//console_line_vertical(0, 5);
	for (int i = 0; i < 5; i++)
	{
		console_to(2 + i, 6);
		printf("Item%d", i);
	}

	int choice = 0;
	while (1)
	{
		if (console_key_begin())
		{
			if (console_key_down(KEY_UP))
				choice--;
			if (console_key_down(KEY_DOWN))
				choice++;
			if (choice < 0)
				choice = 4;
			if (choice > 4)
				choice = 0;

			for (int i = 0; i < 5; i++)
			{
				console_to(2 + i, 3);
				if (choice == i)
					printf("→");
				else
					printf("　");
			}
		}
		console_key_end();
	}
	return 0;
}