// Lab_7_2_2.cpp
// < Kolmykova Kateryna >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 12
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int i, const int n, const int Low, const int High, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		CreateRow(a, i, n, Low, High, j + 1);
}
void CreateRows(int** a, const int n, const int Low, const int High, int i)
{
	CreateRow(a, i, n, Low, High, 0);
	if (i < n - 1)
		CreateRows(a, n, Low, High, i + 1);
}
void PrintRow(int** a, const int i, const int n)
{
	for (int j = 0; j < n; j++)
		cout << setw(4) << a[i][j];
	cout << endl;
}
void PrintRows(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
		PrintRow(a, i, n);
	cout << endl;
}
void MinRow(int** a, const int i, const int n, int j, int& min)
{
		if (a[i][j] < min)
			min = a[i][j];
		if (j < n - 1)
			MinRow(a, i, n, j + 1, min);
}
void MaxMinRows(int** a, const int k, const int n, int i, int& max)
{
	int min = a[i][0];
	MinRow(a, i, n, 1, min);
	if (i == 0)
		max = min;
	if (min > max)
		max = min;
	if (i < k - 1)
		MaxMinRows(a, k, n, i + 1, max);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -20;
	int High = 20;
	int k;
	cout << "k="; cin >> k;
	int n;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	CreateRows(a, n, Low, High, 0);
	PrintRows(a, k, n);
	int max;
	MaxMinRows(a, k, n, 0, max);
	cout << "MaxMin=" << max;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}