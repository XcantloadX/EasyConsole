#pragma once

//-----------头文件-----------
#include <stdio.h>
#include <stdbool.h>
#include <consoleapi.h>
#include <conio.h>

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
//标准输出
void console_printf();
//可设置格式的标准输出
void console_printf_rich();
//清空屏幕内容。
void console_clear();
//将光标移动到第 x 行第 y 列。
void console_to(int x, int y);
//开始检测按键
bool console_key_begin();
//指定按键是否按下
bool console_key_down(int key);
//结束检测按键
void console_key_end();
//取得当前控制台窗口的大小
void console_get_size(int *rows, int *columns);

void console_set_line_style(LINE_STYLE style);
void console_set_text_color(COLOR color);
void console_set_backgroud_color(COLOR color);

void console_box(int line1, int column1, int line2, int column2);

void console_line_vertical(int line1, int line2);