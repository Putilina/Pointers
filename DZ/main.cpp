#include<iostream>
using namespace std;


void FillRand(int** arr[],const int rows,const int cols);

void Print(int** arr[], int rows, int cols);
void main()
{
	setlocale(LC_ALL, "");

	int rows = 3;
	int cols = 4;

	FillRand(rows, cols);
	Print(arr,rows,cols)

	int** arr = new int* [rows];

void FillRand(int** arr[],const int rows,const int cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
			cout << arr[i][j];
		}
		cout << endl;
		
	}
	


}