#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], const int n, const int value);

void main()
{
	setlocale(LC_ALL, "");
	//		new
	int n = 5;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������:"; cin >> value;

	arr[n] = value;
	n++;

	Print(arr, n);

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

	Print(arr, n);

	delete[] arr;


}
	

