#pragma once
#define VALID_POS(row , col, len)(col < len && col >= 0 && row < len && row >= 0) 

int **form , len;
int col, row;


void initial(); // ��������� �������������
void step();
void print();
void mixplayer(); // ������ ���������� ����
bool iswin(int **a);


// �-��� ���� ������������

bool taskpos();  // �������� �� ������������ �������
void automix(); // ���� ���������� ����


/* // ��� ��� ���� ������
struct State //������ ������� ���������
{
	int** board; // ��������� �����
	int parrent_index; // ��� ������ �� ���������� ���������,
	// ������� ��������� ������������ ���� ������� ����� ��� ����������
}; */

int empty_row;
int empty_col;
int len_lever; // ���������� ����� � ������  
bool found; // ������ �� ���������� ��������� ���� 
int*** lever; 
int k; // ������� ���-�� ����� �����
int uzel; // ���������� ��� ���� ��� �� ����������� �� ������ �����
int*** temp_lever; // ����� lever ����� �� ���������� � ����� ����� ���������� ���� 
void comp_play(); // ����� ����� ����������� �� ����� ������
void add_uzel(); // ��������� ����� ���� � temp_lever
void auto_step(); // ��� (�������� �����)
void uzel_step(); // ������ �� ����� ����(�����, ������, �����)





