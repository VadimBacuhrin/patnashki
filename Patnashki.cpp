#include <iostream>
#include <time.h>
#include "Patnashki.h" 
#include <conio.h>
using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");
	int sp;
	srand(time(NULL));
	init();
	stir();
	print();
	cout << "����� �������� ������ ������?\n 1 - �������\n 2 - ��������������\n";
	cin >> sp;
	system("cls");
	print();
	switch (sp)
	{
	case 1:
		handmove();
		break;
	case 2:
		// ��������� ���� ������ � ������� BFS
		break;
	}
	cout << "\n���� ���������";
}

void init()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			card[i][j] = count;
			count++;
		}
	}
}

void stir()
{
	int empty_x = -1;
	int empty_y = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (card[i][j] == 0)
			{
				empty_x = i;
				empty_y = j;
			}
		}
	}
	int a = -1;
	int b = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a = rand()%4-1;
			b = rand() % 4 - 1;
			if (card[a][b] == 0 || card[i][j] == 0)
			{
				j - 1;
				continue;
			}
			int temp = card[a][b];
			card[a][b] = card[i][j];
			card[i][j] = temp;
		}
	}
}

void print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (card[i][j] == 0)
			{
				cout << '_' << ' ';
				continue;
			}
			cout << card[i][j] << ' ';
		}
		cout << endl;
	}
}

void handmove()
{
	
	int empty_x = -1;
	int empty_y = -1;
	while (!is_win())
	{
		cout << "���� ������ ����� ������� ������� 'e'\n";
		char ch = _getch();
		if (ch == 'e')
		{
			return;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (card[i][j] == 0)
				{
					empty_x = i;
					empty_y = j;
				}
			}
		}
		switch (ch)
		{
		case 'w':
			if (empty_x - 1 >= 0)
			{
				card[empty_x][empty_y] = card[empty_x - 1][empty_y];
				card[empty_x - 1][empty_y] = 0;
			}
			break;
		case 's':
			if (empty_x + 1 <= 2)
			{
				card[empty_x][empty_y] = card[empty_x + 1][empty_y];
				card[empty_x + 1][empty_y] = 0;
			}
			break;
		case 'a':
			if (empty_y - 1 >= 0)
			{
				card[empty_x][empty_y] = card[empty_x][empty_y - 1];
				card[empty_x][empty_y - 1] = 0;
			}
			break;
		case 'd':
			if (empty_y + 1 <= 2)
			{
				card[empty_x][empty_y] = card[empty_x][empty_y + 1];
				card[empty_x][empty_y + 1] = 0;
			}
		}
		system("cls");
		print();
	}
}

bool is_win()
{
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (card[i][j] != count)
			{
				return false;
			}
			count++;
		}
	}
	return true;
}