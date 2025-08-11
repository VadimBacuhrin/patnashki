#include <iostream>
#include <time.h>
#include "Patnashki.h" 

using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	init();
	stir();
	print();
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