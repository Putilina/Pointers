#include<iostream>
using namespace std;
using std:: cout;
using std:: cin;
using std::endl;

#define   tab  "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);// добавляет строку в конец массива
int* push_front(int arr[], int& n, const int value); //добавляет строку в начало массива
int* insert(int arr[], int& n, const int value, const int index); //добавляет значение по указанному индексу

int* pop_back(int arr[], int& n);//удаляет последний элемент массива
int* pop_front(int arr[], int& n);//удаляет нулевой элемент массива
int* erase(int arr[], int& n, const int index);//удаляет элемент массива по указанному индексу

int** Allocate(const int rows, const int cols); //Выделяет память для двумерного динамического массив
void Clear(int** arr, const int rows); //Удаляет двумерный динамический массив из памяти

int** push_row_back(int** arr, int& rows, const int cols);	//добавляет строку в конец двумерного динамического массива
int** insert_row(int** arr, int& rows, const int cols, int& index);	//вставляет строку в двумерный динамический массив по заданному индексу
int** pop_row_back(int** arr, int& rows);	//удаляет последнюю строку
int** pop_row_front(int** arr, int& rows);//удаляет нулевую строку
int** erase_row(int** arr, int& rows, int& index);//удаляет строку по заданному индексу
void push_col_back(int** arr, const int rows, int& cols);	//добавляет столбец в конец двумерного динамического массива







//#define DYNAMIC_MEMORY_1
//#define SYNTAX

#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	// new
	int n = 5;
	cout << "Введите размер массива:"; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;	//Enter a value to be added
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;	//Enter a value to be added
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
	//Memory leaks

#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "Введите количество строк:"; cin >> rows;
	cout << "Введите количество элементов строки:"; cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;


#ifdef SYNTAX
	int rows = 3;
	int cols = 4;
	///////    Объявление двумерного динамического массива

// 1) Создаем массив указателей:

	int** arr = new int* [rows];

	// 2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	///////////   Обращение к элементам двумерного динамического массива

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	///////////    Удаление двумерного динамического массива
	// 1)  Удаляем строки:

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}

	//  2)Удаляем массив указателей:

	delete[] arr;
#endif // SYNTAX

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
	
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}


int* push_back(int arr[], int& n, const int value)
{
	// 1) Создаем буферный массив нужного размера:

	int* buffer = new int[n + 1];

	// 2) Копируем значение элементов исходного массива в буферный:

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) Удаляем исходный массив из памяти:

	delete[] arr;

	// 4) Подменяем адрес в указателе 'arr'  адресом нового массива:

	arr = buffer;

	// 5) Только после этого можно добавить значение в конец массива:

	arr[n] = value;

	// 6) После добавления элемента в конец массива,количество его элементов увеличится на 1

	n++;
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)
	{
		/*if (i < index)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];*/
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;
}
int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	 return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols];
	rows++;
	return buffer;
}
int** pop_row_back(int** arr, int& rows)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
	int** pop_row_front(int** arr, int& rows)
	{
	    int** buffer = new int* [--rows];
	    for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	    delete[] arr[0];
	    delete[] arr;
	    return buffer;
}
	int** erase_row(int** arr, int& rows, int& index)
	{
		rows--;
		int** buffer = new int* [rows];
		for (int i = rows; i > index; --i)
		{
			buffer[i - 1] = arr[i];
		}
		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr;
		return buffer;
	}
	int** insert_row(int** arr, int& rows, const int cols, int& index)
	{
		int** buffer = new int* [rows + 1];
		for (int i = rows; i >= index; i--)
		{
			buffer[i + 1] = arr[i];
		}
		for (int i = 0; i < index; i++)
		{
			buffer[i] = arr[i];
		}
		delete[] arr;
		buffer[index] = new int[cols] {};
		rows++;
		return buffer;
	}