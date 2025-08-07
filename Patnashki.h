#pragma once
#define VALID_POS(row , col, len)(col < len && col >= 0 && row < len && row >= 0) 

int **form , len;
int col, row;


void initial(); // начальная инициализация
void step();
void print();
void mixplayer(); // ручное заполнение поля
bool iswin(int **a);


// ф-ции авто размешивания

bool taskpos();  // проверка на нерешаемость позиции
void automix(); // авто заполнение поля


/* // Все для авто хотьбы
struct State //хранит текущее состояние
{
	int** board; // состояние доски
	int parrent_index; // это ссылка на предыдущее состояние,
	// которая позволяет восстановить путь решения после его нахождения
}; */

int empty_row;
int empty_col;
int len_lever; // количество узлов в уровне  
bool found; // флажок на нахождение кароткого пути 
int*** lever; 
int k; // счетчик кол-ва новых узлов
int uzel; // переменная для того что бы проходиться по старым узлам
int*** temp_lever; // когда lever занят то информацию о узлах будем записывать сюда 
void comp_play(); // сдесь нужно проходиться по всему уровню
void add_uzel(); // добавляет новый узел в temp_lever
void auto_step(); // шаг (например вверх)
void uzel_step(); // проход по всему узлу(влево, вправо, вверх)





