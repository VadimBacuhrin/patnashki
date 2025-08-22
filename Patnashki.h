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
	friend void add(int **cadr);

	frame& operator[](int a)
	{
		return frames[a];
	}
};