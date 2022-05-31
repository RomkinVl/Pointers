#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Push_Back(int arr[], const int n, int add);
void Push_Front(int arr[], const int n, int add);
void Insert(int arr[], const int n, int add, int index);
void Pop_Back(int arr[], const int n);
void Pop_Front(int arr[], const int n);
void Erase(int arr[], const int n, int index);

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int add;
	cout << "Введите значение последнего элемента: "; cin >> add;
	Push_Back(arr, n, add);
	Print(arr, n);

	cout << "Введите значение первого элемента: "; cin >> add;
	Push_Front(arr, n, add);
	Print(arr, n);

	int index;
	cout << "Введите индекс и значение его переменной: "; cin >> index >> add;
	Insert(arr, n, add, index);
	Print(arr, n);

	cout << endl;

	Pop_Back(arr, n);
	Print(arr, n);

	cout << endl;

	Pop_Front(arr, n);
	Print(arr, n);

	cout << "Введите индекс элемента для удаления: "; cin >> index;
	Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subnscript operator)
		cout << arr[i] << "\t";
	}

	cout << endl;
}

void Push_Back(int arr[], const int n, int add)
{
	*(arr + (n - 1)) = add;
}

void Push_Front(int arr[], const int n, int add)
{
	*arr = add;
}

void Insert(int arr[], const int n, int add, int index)
{
	*(arr + index) = add;
}

void Pop_Back(int arr[], const int n)
{
	*(arr + (n - 1)) = 0;
}

void Pop_Front(int arr[], const int n)
{
	*arr = 0;
}

void Erase(int arr[], const int n, int index)
{

	*(arr + index) = 0;
}