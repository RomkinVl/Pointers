#include <iostream>
using namespace std;

template <typename T>
void FillRand(T arr[], int n);

template <typename T>
void Print(T arr[], int n);

template <typename T>
void Amount(T arr[], int n, int& even, int& odd);

template <typename T>
void Sort(T arr[], int n, int* even, int* odd);

void main()
{
	setlocale(LC_ALL, "");

	int array[10];
	FillRand(array, 10);
	Print(array, 10);

	int even_amount, odd_amount;

	Amount(array, 10, even_amount, odd_amount);

	int* even = new int[even_amount];
	int* odd = new int[odd_amount];

	Sort(array, 10, even, odd);

	Print(even, even_amount);
	Print(odd, odd_amount);

	delete[] even;
	delete[] odd;
}

template <typename T>
void FillRand(T arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		arr[i] = -50 + rand() % 100;
	}

}

template <typename T>
void Print(T arr[], int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << endl;

}

template <typename T>
void Amount(T arr[], int n, int& even, int& odd)
{

	even = odd = 0;

	for (int i = 0; i < n; i++)
	{

		(arr[i] % 2 == 0) ? even++ : odd++;
	}
}

template <typename T>
void Sort(T arr[], int n, int* even, int* odd)
{

	int ec = 0;
	int oc = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			*(even + ec) = arr[i];
			ec++;
		}
		else
		{
			*(odd + oc) = arr[i];
			oc++;
		}
	}
}