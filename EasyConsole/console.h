#pragma once
#include <stdbool.h>

//-----------头文件-----------

//-----------枚举-----------

//线条样式
typedef enum {
	LINE_SINGLE,
	LINE_DOUBLE,
	LINE_NONE
} LINE_STYLE;

//颜色
typedef enum {
	COLOR_BLACK,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_BLUE,
	COLOR_MAGENTA,
	COLOR_CYAN,
	COLOR_WHITE
} COLOR;

//-----------常量-----------
//键代码定义
#define KEY_Q (int)'q'
#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_ENTER 0x1C

//字符定义
#define BOX_DBL_0

//-----------函数声明-----------

//初始化 console_ 系列函数。在调用任何 console_ 系列函数之前必须先调用此函数。
void console_init();
//清空屏幕内容。
void console_clear();
//将光标移动到第 x 行第 y 列。注意，行和列从 1 开始。
void console_goto(int x, int y);
//开始检测按键
bool console_key_begin();
//指定按键是否按下，需要先调用 console_key_begin() 才能调用本函数。
bool console_key_down(int key);
//结束检测按键
void console_key_end();
//设置当前控制台窗口的大小
void console_get_size(int *rows, int *columns);
//取得当前控制台窗口的大小
void console_set_size(int rows, int columns);
//设置是否显示光标
void console_set_cursor(bool show);
//
void console_set_line_style(LINE_STYLE style);
//设置文本颜色
void console_set_text_color(COLOR color);
//设置背景颜色
void console_set_background_color(COLOR color);
//输出居中文本
//	参数：
//		text - 要输出的文本
//		row - 在哪一行输出
//		column_from - 从哪一列开始
//		column_to - 到哪一列结束
void console_text_center(char * text, int row, int column_from, int column_to);
//画矩形框。
//	参数：
//		line1 - 矩形左上角的行和列、矩形右上角的行和列
//		column1 - 
//		line2 - 
//		column2 - 
//		
void console_box(int line1, int column1, int line2, int column2);
//画横线
void console_line_horizontal(int col1, int col2, int row);
//画竖线
void console_line_vertical(int line1, int line2, int column);