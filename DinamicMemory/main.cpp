#include<iostream>
using namespace std;

#define   tab  "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int& n, const int value);

void main()
{
	setlocale(LC_ALL, "");
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

	delete[] arr;
	//Memory leaks


}
void FillRand(int arr[], const int n)
{
	
       for (int i = 0; i < n; i++)
	   {
		*(arr + i) = rand() % 100;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
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
