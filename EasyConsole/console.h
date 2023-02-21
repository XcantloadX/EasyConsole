#pragma once
#include <stdbool.h>

//-----------ͷ�ļ�-----------

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
//�����Ļ���ݡ�
void console_clear();
//������ƶ����� x �е� y �С�ע�⣬�к��д� 1 ��ʼ��
void console_goto(int x, int y);
//��ʼ��ⰴ��
bool console_key_begin();
//ָ�������Ƿ��£���Ҫ�ȵ��� console_key_begin() ���ܵ��ñ�������
bool console_key_down(int key);
//������ⰴ��
void console_key_end();
//���õ�ǰ����̨���ڵĴ�С
void console_get_size(int *rows, int *columns);
//ȡ�õ�ǰ����̨���ڵĴ�С
void console_set_size(int rows, int columns);
//�����Ƿ���ʾ���
void console_set_cursor(bool show);
//
void console_set_line_style(LINE_STYLE style);
//�����ı���ɫ
void console_set_text_color(COLOR color);
//���ñ�����ɫ
void console_set_background_color(COLOR color);
//��������ı�
//	������
//		text - Ҫ������ı�
//		row - ����һ�����
//		column_from - ����һ�п�ʼ
//		column_to - ����һ�н���
void console_text_center(char * text, int row, int column_from, int column_to);
//�����ο�
//	������
//		line1 - �������Ͻǵ��к��С��������Ͻǵ��к���
//		column1 - 
//		line2 - 
//		column2 - 
//		
void console_box(int line1, int column1, int line2, int column2);
//������
void console_line_horizontal(int col1, int col2, int row);
//������
void console_line_vertical(int line1, int line2, int column);