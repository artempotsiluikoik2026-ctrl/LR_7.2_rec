// Lab_7_2_2.cpp
// Поцілуйко Артем
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 11
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

void MinCol(int** a, const int k, const int colNo, int rowNo, int& min)
{
    if (a[rowNo][colNo] < min)
        min = a[rowNo][colNo];
    if (rowNo < k - 1)
        MinCol(a, k, colNo, rowNo + 1, min);
}

void SumMinEvenCols(int** a, const int k, const int n, int colNo, int& S)
{
    if ((colNo + 1) % 2 == 0)
    {
        int min = a[0][colNo];
        MinCol(a, k, colNo, 0, min);
        S += min;
    }
    if (colNo < n - 1)
        SumMinEvenCols(a, k, n, colNo + 1, S);
}

int main()
{
    srand((unsigned)time(NULL));

    int Low = 7;
    int High = 65;
    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;
    cout << endl;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, k, n, Low, High, 0);
    PrintRows(a, k, n, 0);

    int S = 0;
    SumMinEvenCols(a, k, n, 0, S);
    cout << "S = " << S << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}