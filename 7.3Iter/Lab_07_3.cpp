// Lab_07_3(Iter).cpp
// Вольвенко Іван
// Лабораторна робота № 7.3
// Опрацювання динамічних багатовимірних масивів ітераційними способами.
// Варіант 13

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
#include <windows.h>

using namespace std;

void Create(int** mas, const int k, const int n, const int Low, const int High);
void Print(int** mas, const int k, const int n);
void MovingRight(int** mas, const int k, const int n, int x);
void MovingDown(int** mas, const int k, const int n, int x);
int FindRow(int** mas, const int k, const int n);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = 0;
	int High = 1;

	int k, n, x;
	bool TrueFalse;

	cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Print(a, k, n);

	cout << "Введіть 1, якщо бажаєте здійснити переміщення елементів вправо" << endl
		<< "Введіть 0, якщо бажаєте здійснити переміщення елементів вниз" << endl;
	cin >> TrueFalse;
	cout << "x = "; cin >> x;

	if(TrueFalse)
		MovingRight(a, k, n, x);
	else
		MovingDown(a, k, n, x);

	Print(a, k, n);

	cout << "номер рядка = " << FindRow(a, k, n) << endl;

	delete[] a;

	return 0;
}

void Create(int** mas, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			mas[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** mas, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << mas[i][j];
		cout << endl;
	}
	cout << endl;
}

void MovingRight(int** mas, const int k, const int n, int x)
{
	int tmp;

	if (x > n)
		x = (x % n);

	for (int p = 0; p < x; p++)
	{
		for (int i = 0; i < k; i++)
		{
			tmp = mas[i][n - 1];
			for (int j = n - 1; j > 0; j--)
			{
				mas[i][j] = mas[i][j - 1];
			}
			mas[i][0] = tmp;
		}
	}
}

void MovingDown(int** mas, const int k, const int n, int x)
{
	int tmp;

	if (x > k)
		x = (x % k);

	for (int p = 0; p < x; p++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp = mas[k - 1][j];
			for (int i = k - 1; i > 0; i--)
				mas[i][j] = mas[i - 1][j];
			mas[0][j] = tmp;
		}
	}
}

int FindRow(int** mas, const int k, const int n)
{
	int m = 0, q = -1, t = 0;
	for (int i = 0; i < k; i++)
	{
		m = 0;
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] == 0)
				m++;
			if (m > q)
			{
				q = m;
				t = i;
			}
		}
	}
	return t+1;
}