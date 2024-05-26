#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define   tab  "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);// ��������� ������ � ����� �������
int* push_front(int arr[], int& n, const int value); //��������� ������ � ������ �������
int* insert(int arr[], int& n, const int value, const int index); //��������� �������� �� ���������� �������

int* pop_back(int arr[], int& n);//������� ��������� ������� �������
int* pop_front(int arr[], int& n);//������� ������� ������� �������
int* erase(int arr[], int& n, const int index);//������� ������� ������� �� ���������� �������

int** Allocate(const int rows, const int cols); //�������� ������ ��� ���������� ������������� ������
void Clear(int** arr, const int rows); //������� ��������� ������������ ������ �� ������

int** push_row_back(int** arr, int& rows, const int cols);	//��������� ������ � ����� ���������� ������������� �������
int** push_row_front(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, int& index);	//��������� ������ � ��������� ������������ ������ �� ��������� �������
int** pop_row_back(int** arr, int& rows);	//������� ��������� ������
int** pop_row_front(int** arr, int& rows);//������� ������� ������
int** erase_row(int** arr, int& rows, int& index);//������� ������ �� ��������� �������
void push_col_back(int** arr, const int rows, int& cols);	//��������� ������� � ����� ���������� ������������� �������



//#define DYNAMIC_MEMORY_1
//#define SYNTAX

#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	// new
	int n = 5;
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;	//Enter a value to be added
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;	//Enter a value to be added
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ ���������� ��������: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
	//Memory leaks

#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "������� ���������� �����:"; cin >> rows;
	cout << "������� ���������� ��������� ������:"; cin >> cols;

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
	///////    ���������� ���������� ������������� �������

// 1) ������� ������ ����������:

	int** arr = new int* [rows];

	// 2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	///////////   ��������� � ��������� ���������� ������������� �������

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	///////////    �������� ���������� ������������� �������
	// 1)  ������� ������:

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}

	//  2)������� ������ ����������:

	delete[] arr;
#endif // SYNTAX

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//��������� � ��������� ������� ����� ���������� ���������� � �������� �������������
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
		//��������� � ��������� ������� ����� �������� �������������� []
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
	// 1) ������� �������� ������ ������� �������:

	int* buffer = new int[n + 1];

	// 2) �������� �������� ��������� ��������� ������� � ��������:

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ������� �������� ������ �� ������:

	delete[] arr;

	// 4) ��������� ����� � ��������� 'arr'  ������� ������ �������:

	arr = buffer;

	// 5) ������ ����� ����� ����� �������� �������� � ����� �������:

	arr[n] = value;

	// 6) ����� ���������� �������� � ����� �������,���������� ��� ��������� ���������� �� 1

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
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}






//#define DYNAMIC_MEMORY_1
//#define SYNTAX

#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	// new
	int n = 5;
	cout << "������� ������ �������:"; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������:"; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "������� ����������� ��������: "; cin >> value;	//Enter a value to be added
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� ����������� ��������: "; cin >> value;	//Enter a value to be added
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "������� ������ ���������� ��������: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
	//Memory leaks

#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "������� ���������� �����:"; cin >> rows;
	cout << "������� ���������� ��������� ������:"; cin >> cols;
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
	///////    ���������� ���������� ������������� �������

// 1) ������� ������ ����������:

	int** arr = new int* [rows];

	// 2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	///////////   ��������� � ��������� ���������� ������������� �������

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	///////////    �������� ���������� ������������� �������
	// 1)  ������� ������:

	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}

	//  2)������� ������ ����������:

	delete[] arr;
#endif // SYNTAX

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//��������� � ��������� ������� ����� ���������� ���������� � �������� �������������
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
		//��������� � ��������� ������� ����� �������� �������������� []
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
	// 1) ������� �������� ������ ������� �������:

	int* buffer = new int[n + 1];

	// 2) �������� �������� ��������� ��������� ������� � ��������:

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// 3) ������� �������� ������ �� ������:

	delete[] arr;

	// 4) ��������� ����� � ��������� 'arr'  ������� ������ �������:

	arr = buffer;

	// 5) ������ ����� ����� ����� �������� �������� � ����� �������:

	arr[n] = value;

	// 6) ����� ���������� �������� � ����� �������,���������� ��� ��������� ���������� �� 1

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