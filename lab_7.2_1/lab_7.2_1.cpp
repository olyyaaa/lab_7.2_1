// lab_7.2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			y[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** y, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << y[i][j];
		cout << endl;
	}
	cout << endl;
}



int iMax(int** y, int k, int n, int i)
{
	int max = y[i][0];
	int imax = 0;

	for (int j = 1; j < n; j++) {
		if (y[i][j] > max) {
			max = y[i][j];
			imax = j;
		}
	}

	return imax;
}


int iMin(int** y, int k, int n, int i)
{
	int min = y[i][0];
	int imin = 0;

	for (int j = 1; j < n; j++) {
		if (y[i][j] < min) {
			min = y[i][j];
			imin = j;
		}
	}

	return imin;
}

void Change(int** y, int k, int n)
{
	for (int i = 1; i < k; i += 2) {

		int IndexOfMax = iMax(y, k, n, i);
		int IndexOfMin = iMin(y, k, n, i - 1);

		int tmp = y[i][IndexOfMax];
		y[i][IndexOfMax] = y[i][IndexOfMin];
		y[i][IndexOfMin] = tmp;
	}
}
void SumRows(int** a, const int rowCount, const int colCount, int rowNo, int& S)
{
	if (rowNo < rowCount - 1)
		SumRows(a, rowCount, colCount, rowNo + 1, S);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = 8;
	int High = 73;
	const int N = 4;
	int k = 5;
	int n = 5;
	int i = 0;
	int a = 1;
	void SumRow(int** a, const int rowNo, const int colCount, int colNo, int& S);
	int** y = new int* [k];
	for (int i = 0; i < k; i++)
		y[i] = new int[n];
	Create(y, k, n, Low, High);
	Print(y, k, n);
	Change(y, k, n);
	Print(y, k, n);



}
	


// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
