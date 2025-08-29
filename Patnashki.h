#pragma once
int len = -1;
int card[3][3];
void init();
void stir();
void print();
void handmove();
bool is_win();

class frame
{
	int cadr[3][3];
	int id;
public:
	frame()
	{
		len++;
		id = len+1;
	}
	~frame()
	{
		for (int i = 0; i < 3; i++)
		{
			delete[] cadr[i];
		}
		delete[] cadr;
	}
	int* operator[](int i)
	{
		return cadr[i];
	}
};

class BFS
{
	frame *frames;
public:
	BFS()
	{
		frames = new frame[len+1];
	}
	~BFS()
	{
		delete[] frames;
	}
	friend void add(int **cadr);

	frame& operator[](int a)
	{
		return frames[a];
	}
};