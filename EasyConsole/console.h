#pragma once

//-----------ͷ�ļ�-----------
#include <stdio.h>
#include <stdbool.h>
#include <consoleapi.h>
#include <conio.h>

//-----------ö��-----------
//������ʽ
typedef enum {
	LINE_SINGLE,
	LINE_DOUBLE,
	LINE_NONE
} LINE_STYLE;

//��ɫ
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

//-----------����-----------
//�����붨��
#define KEY_Q (int)'q'
#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_ENTER 0x1C

//�ַ�����
#define BOX_DBL_0

//-----------��������-----------

//��ʼ�� console_ ϵ�к������ڵ����κ� console_ ϵ�к���֮ǰ�����ȵ��ô˺�����
void console_init();
//��׼���
void console_printf();
//�����ø�ʽ�ı�׼���
void console_printf_rich();
//�����Ļ���ݡ�
void console_clear();
//������ƶ����� x �е� y �С�
void console_to(int x, int y);
//��ʼ��ⰴ��
bool console_key_begin();
//ָ�������Ƿ���
bool console_key_down(int key);
//������ⰴ��
void console_key_end();
//ȡ�õ�ǰ����̨���ڵĴ�С
void console_get_size(int *rows, int *columns);

void console_set_line_style(LINE_STYLE style);
void console_set_text_color(COLOR color);
void console_set_backgroud_color(COLOR color);

void console_box(int line1, int column1, int line2, int column2);

void console_line_vertical(int line1, int line2);