#include <iostream>
#include <time.h>
#include "Patnashki.h" 

using namespace std;


void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int v, w;
	cout << "Какую платформу хочешь создать\n1- 3x3\n2- 5x5\n";
	cin >> v;
	switch (v)
	{
	case 1:
		len = 3;
		break;
	case 2:
		len = 5;
		break;
	}
	form = new int* [len];
	for (int i = 0; i < len; i++)
	{
		form[i] = new int[len];
	}
	initial();
	system("cls");
	cout << "Перемешать:\n1- вручную\n2-атоматически\n";
	cin >> w;
	system("cls");
	switch (w)
	{
	case 1:
		mixplayer();
		system("cls");
		break;
	case 2:
		automix();
		break;
	}
	cout << "Перемешанное поле:\n";
	print();
	// добавить выбор хода
	int mode;
	cout << "Какой режим выберешь:\n";
	cout << "1 - ручная ходьба\n2 - авто хотьба\n";
	cin >> mode;
	int d_time2;
	int d_time1;
	int timer;
	int step_count = 0; // Кол-во шагов
	switch (mode)
	{
	case 1:
		d_time1 = time(NULL);
		while (!iswin(form))
		{
			// Ручная хотьба
			cout << "Введите ряд:\n";
			cin >> row;
			cout << "Введите столбик:\n";
			cin >> col;
			step();
			system("cls");
			print();
			step_count++;
		}
		cout << "Статистика:\n";
		d_time2 = time(NULL);
		timer = d_time2 - d_time1;
		cout << "Потрачено времени: " << timer << " сек.\n";
		cout << "Кол-во шагов проделано: " << step_count << '\n';
		break;
	case 2:
		int len_state = 100;
	/*	State* states = new State[len_state];
		states[0] = {form , -1}; */
		bool found = false;
		len_lever = 1;
		k = 0;
		lever = new int** [len_lever];
		lever[0] = new int* [len];
		for (int i = 0; i < len; i++)
		{
			lever[0][i] = new int[len];
		}
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				lever[0][i][j] = form[i][j];
			}
		}
		while (!iswin(form))
		{
			temp_lever = new int** [k];
			uzel = 0;
			comp_play();
			if (found)
			{
				cout << "Выйгрышный узел\n";
				break;
			}
		}
	}
}

void initial()
{
	int num = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			form[i][j] = num;
			num++;
		}
	}
	form[len - 1][len - 1] = 0;
}
void step()
{
	if (!VALID_POS(row, col, len))
	{
		cout << "Ошибка, выход за пределы\n";
		return;
	}
	int empty_row = -1, empty_col = -1;
	for (int i = 0; i < len; i++)  // находим координаты 
	{
		for (int j = 0; j < len; j++)
		{
			if (form[i][j] == 0)
			{
				empty_row = i;
				empty_col = j;
			}
		}
	}
	bool isNeighbor = false;
	if (VALID_POS(row + 1, col, len) && form[row + 1][col] == 0)
	{
		isNeighbor = true;
	}
	else if (VALID_POS(row - 1, col, len) && form[row - 1][col] == 0)
	{
		isNeighbor = true;
	}
	else if (VALID_POS(row, col + 1, len) && form[row][col + 1] == 0)
	{
		isNeighbor = true;
	}
	else if (VALID_POS(row, col - 1, len) && form[row][col - 1] == 0)
	{
		isNeighbor = true;
	}
	if (isNeighbor)
	{
		int temp = form[row][col];
		form[row][col] = 0;
		form[empty_row][empty_col] = temp;
	}
	else
	{
		cout << "Ошибка, вы ввели неверные координаты\n";
	}
}

bool taskpos()
{
	int invers = 0;
	int ind = 0;
	int* new_form = new int[len * len];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			new_form[ind] = form[i][j];
			ind++;
		}
	}
	ind = 0;
	while (ind != len * len)
	{
		for (int i = ind; i < len * len; i++)
		{
			if (new_form[i] == 0)
			{
				continue;
			}
			if (new_form[ind] > new_form[i])
			{
				invers++;
			}
		}
		ind++;
	}
	delete[] new_form;
	if (invers % 2 == 0) // если количество инверсий кратно 2 то позиция решаема
	{
		return true;
	}
	return false;
}

void automix()
{
	int r = 0;
	int c = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = len - 1; j >= 0; j--)
		{
			if (i == len - 1 && j == len - 1)
			{
				continue;
			}
			r = rand() % len;
			c = rand() % len;
			if (r == len - 1 && c == len - 1)
			{
				continue;
			}
			int temp = form[i][j];
			form[i][j] = form[r][c];
			form[r][c] = temp;
		}
	}
	if (!taskpos())
	{
		automix();
	}
}

void print()
{
	cout << "  ";
	for (int j = 0; j < len; j++)
	{
		cout << " " << j << " ";
	}
	cout << endl;
	for (int i = 0; i < len; i++)
	{
		cout << i << " ";
		for (int j = 0; j < len; j++)
		{
			if (form[i][j] == 0)
			{
				cout << "  _";
				continue;
			}
			if (form[i][j] > 9)
			{
				cout << " " << form[i][j];
			}
			else
			{
				cout << "  " << form[i][j];
			}
		}
		cout << endl;
	}
}

void mixplayer() // ручное заполнение поля
{

	while (true)
	{
		print();
		cout << "Введите (-1 ; -1) что бы выйти\n";
		cout << "Введите ряд:\n";
		cin >> row;
		cout << "Введите столбик:\n";
		cin >> col;
		if (col == -1 && row == -1)
		{
			break;
		}
		system("cls");
		step();
	}
}

bool iswin(int** uzel)
{
	int num = 1;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == len - 1 && j == len - 1)
			{
				return true;
			}
			if (uzel[i][j] != num)
			{
				return false;
			}
			num++;
		}
	}
}




void comp_play()
{
	k = 0;
	int plen_lever = len_lever;
	len_lever = 0;
	for (uzel = 0; uzel < plen_lever; uzel++)
	{
		uzel_step();
		if (iswin(lever[uzel]))
		{
			found = true;
			return;
		}
	}
	// В старый уровень записать новый
	for (int i = 0; i < len_lever; i++)
	{
		for (int j = 0; j < len; j++)
		{
			delete[] lever[i][j];
		}
		delete[] lever[i];
	}
	delete[] lever;
	lever = new int** [k];
	for (int i = 0; i < k; i++)
	{
		lever[i] = new int* [len];
		for (int j = 0; j < len; j++)
		{
			lever[i][j] = new int[len];
			for (int l = 0; l < len; l++)
			{
				lever[i][j][l] = temp_lever[i][j][l];
			}
		}
	}
	len_lever = k;
	for (int i = 0; i < len_lever; i++)
	{
		for (int j = 0; j < len; j++)
		{
			delete[] temp_lever[i][j];
		}
		delete[] temp_lever[i];
	}
	delete[] temp_lever;
	found = false;
}

void add_uzel()
{
	int*** a = new int** [k + 1];
	for (int i = 0; i < k + 1; i++)
	{
		a[i] = new int* [len];
		for (int j = 0; j < len; j++)
		{
			a[i][j] = new int[len];
		}
	}
	for (int i = 0; i < k + 1; i++)
	{
		if (i == k)
		{
			break;
		}
		for (int j = 0; j < len; j++)
		{
			for (int l = 0; l < len; l++)
			{
				a[i][j][l] = temp_lever[i][j][l];
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < len; j++)
		{
			delete[] temp_lever[i][j];
		}
		delete[] temp_lever[i];
	}
	delete[] temp_lever;
	temp_lever = new int** [k + 1];
	for (int i = 0; i < k + 1; i++)
	{
		temp_lever[i] = new int* [len];
		for (int j = 0; j < len; j++)
		{
			temp_lever[i][j] = new int[len];
		}
	}
	for (int i = 0; i < k + 1; i++)
	{
		for (int j = 0; j < len; j++)
		{
			for (int l = 0; l < len; l++)
			{
				if (i == k)
				{
					return;
				}
				temp_lever[i][j][l] = a[i][j][l];
			}
		}
	}
}
void uzel_step()
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (lever[uzel][i][j] == 0)
			{
				empty_row = i;
				empty_col = j;
			}
		}
	}
	row = empty_row;
	col = empty_col;
	row -= 1;
	auto_step();
	row = empty_row;
	row += 1;
	auto_step();
	row = empty_row;
	col += 1;
	auto_step();
	col = empty_col;
	col -= 1;
	auto_step();
	col = empty_col;
}

void auto_step()
{
	if (VALID_POS(row, col, len))
	{
		int temp = form[row][col];
		form[row][col] = form[empty_row][empty_col];
		form[empty_row][empty_col] = temp;

		add_uzel();
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				temp_lever[k][i][j] = form[i][j];
			}
		}
		k += 1;
		for (int i = 0; i < len; i++)
		{
			delete[] form[i];
		}
		delete[] form;
		form = new int* [len];
		for (int i = 0; i < len; i++)
		{
			form[i] = new int[len];
		}
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				form[i][j] = lever[uzel][i][j];
			}
		}
	}
}  