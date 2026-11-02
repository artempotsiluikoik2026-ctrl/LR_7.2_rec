#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 7.2 рек/ЛР 7.2 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest7_2_2
{
	TEST_CLASS(UnitTest7_2_2)
	{
	public:

		TEST_METHOD(TestMinCol)
		{
			const int k = 3;
			const int n = 4;
			int data[k][n] = {
				{ 10, 20, 30, 40 },
				{  5,  8, 25,  3 },
				{  7, 12,  9, 15 } };

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
			{
				a[i] = new int[n];
				for (int j = 0; j < n; j++)
					a[i][j] = data[i][j];
			}

			int min = a[0][1];
			MinCol(a, k, 1, 0, min);
			Assert::AreEqual(8, min);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSumMinEvenCols)
		{
			const int k = 3;
			const int n = 4;
			int data[k][n] = {
				{ 10, 20, 30, 40 },
				{  5,  8, 25,  3 },
				{  7, 12,  9, 15 } };

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
			{
				a[i] = new int[n];
				for (int j = 0; j < n; j++)
					a[i][j] = data[i][j];
			}

			int S = 0;
			SumMinEvenCols(a, k, n, 0, S);
			Assert::AreEqual(11, S);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSumMinEvenColsOneRow)
		{
			const int k = 1;
			const int n = 4;
			int data[k][n] = { { 5, 6, 7, 8 } };

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
			{
				a[i] = new int[n];
				for (int j = 0; j < n; j++)
					a[i][j] = data[i][j];
			}

			int S = 0;
			SumMinEvenCols(a, k, n, 0, S);
			Assert::AreEqual(14, S);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSumMinEvenColsOneColumn)
		{
			const int k = 3;
			const int n = 1;
			int data[k][n] = { { 9 }, { 4 }, { 6 } };

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
			{
				a[i] = new int[n];
				for (int j = 0; j < n; j++)
					a[i][j] = data[i][j];
			}

			int S = 0;
			SumMinEvenCols(a, k, n, 0, S);
			Assert::AreEqual(0, S);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}