#include <iostream>
#include <time.h>
#include "Patnashki.h" 
#include <conio.h>
using namespace std;

BFS alfa;
void main()
{
	setlocale(LC_ALL, "Russian");
	int sp;
	srand(time(NULL));
	init();
	stir();
	print();
	cout << "Каким способом хотите решить?\n 1 - вручную\n 2 - автоматический\n";
	cin >> sp;
	system("cls");
	print();
	switch (sp)
	{
	case 1:
		handmove();
		break;
	case 2:
		// Запустить авто хотьбу и паттерн BFS
		break;
	}
	cout << "Игра закончена";
}

void add(int **cadr)
{
	if (len == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				alfa.frames[0][i][j] = cadr[i][j];
			}
		}
		len++;
	}
	else
	{
		frame* temp = new frame[len];
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					temp[i][j][k] = alfa.frames[i][j][k];
				}
			}
		}
		delete[] alfa.frames;
		alfa.frames = new frame[len+1];
		for (int i = 0; i < len+1; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (i == len)
					{
						alfa.frames[i][j][k] = cadr[j][k];
					}
					else
					{
						alfa.frames[i][j][k] = temp[i][j][k];
					}
				}
			}
		}
	}
	len++;
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
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (card[i][j] == 0)
			{
				continue;
			}
			for (int k = i; k < 3; k++)
			{
				for (int y = j; y < 3; y++)
				{
					if (card[k][y] == 0)
					{
						continue;
					}
					if (card[i][j] > card[k][y])
					{
						count++;
					}
				}
			}
		}
	}
	if (count % 2 != 0)
	{
		stir();
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
		cout << "Если хотите выйти нажмите клавишу 'e'\n";
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
	int count = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (card[i][j] == 0)
			{
				continue;
			}
			if (card[i][j] != count)
			{
				return false;
			}
			count++;
		}
	}
	return true;
}