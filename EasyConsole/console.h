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

#define KEY_UP 0x48
#define KEY_DOWN 0x50
#define KEY_ENTER 0x1C
//��ĸ��
#define KEY_A (int)'a'
#define KEY_B (int)'b'
#define KEY_C (int)'c'
#define KEY_D (int)'d'
#define KEY_E (int)'e'
#define KEY_F (int)'f'
#define KEY_G (int)'g'
#define KEY_H (int)'h'
#define KEY_I (int)'i'
#define KEY_J (int)'j'
#define KEY_K (int)'k'
#define KEY_L (int)'l'
#define KEY_M (int)'m'
#define KEY_N (int)'n'
#define KEY_O (int)'o'
#define KEY_P (int)'p'
#define KEY_Q (int)'q'
#define KEY_R (int)'r'
#define KEY_S (int)'s'
#define KEY_T (int)'t'
#define KEY_U (int)'u'
#define KEY_V (int)'v'
#define KEY_W (int)'w'
#define KEY_X (int)'x'
#define KEY_Y (int)'y'
#define KEY_Z (int)'z'
// ���ܼ�
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x57
#define KEY_F12 0x58

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