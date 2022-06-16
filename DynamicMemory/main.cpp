#include <iostream>
using namespace std;

template <typename T> void FillRand(T arr[], const int n);
template <typename T> void Print(T arr[], const int n);
template <typename T> void Push_Back(T arr[], const int n, T add);
template <typename T> void Push_Front(T arr[], const int n, T add);
template <typename T> void Insert(T arr[], const int n, T add, int index);
template <typename T> void Pop_Back(T arr[], const int n);
template <typename T> void Pop_Front(T arr[], const int n);
template <typename T> void Erase(T arr[], const int n, int index);

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

template <typename T> void FillRand(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

template <typename T> void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - оператор индексирования (subnscript operator)
		cout << arr[i] << "\t";
	}

	cout << endl;
}

template <typename T> void Push_Back(T arr[], const int n, T add)
{
	*(arr + (n - 1)) = add;
}

template <typename T> void Push_Front(T arr[], const int n, T add)
{
	*arr = add;
}

template <typename T> void Insert(T arr[], const int n, T add, int index)
{
	*(arr + index) = add;
}

template <typename T> void Pop_Back(T arr[], const int n)
{
	*(arr + (n - 1)) = 0;
}

template <typename T> void Pop_Front(T arr[], const int n)
{
	*arr = 0;
}

template <typename T> void Erase(T arr[], const int n, int index)
{

	*(arr + index) = 0;
}