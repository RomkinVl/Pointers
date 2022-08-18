#include<iostream>
using namespace std;
using std::cin;
using std::cout;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);



void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n]; //Объявление динамического массива
	/*
	Оператор new выделяет непрерывный блок памяти для n элементов заданного типа,
	в данном случае - int, и возвращает адрес выделенной памяти. Этот адрес мы оператором
	присваивания записываем в указатель.
	*/

	//Обращение к элементам динамического массива.
	/*
	Обращаться к элементам динам. массива можно точно точно также как и к элементам
	стат.массива: через арифметику указателей и оператор разымен., либо ч/з оператор
	индексирования
	*/
	FillRand(arr, n);
	cout << "Исходный массив: \n";
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr[n] = value;
	n++;

	Print(arr, n);


	// 1) считаем количество четных и нечетных значений в исходном массиве
	int even_size = 0; //Количество четных значений в массиве
	int odd_size = 0; //Количество нечетных значений в массиве

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_size++;
		else odd_size++;
	}

	cout << "Количество четных элементов: " << even_size << endl;
	cout << "Количество нечетных элементов: " << odd_size << endl;

	// 2) Выделяем память для четных и нечетных элементов
	int* even_arr = new int[even_size];
	int* odd_arr = new int[odd_size];

	// 3) Копируем четные и нечетные элементы в соответствующие массивы
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0)
			even_arr[j++] = arr[i];
		else
			odd_arr[k++] = arr[i];*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}

	// 4) Выводим массивы на экран
	cout << "Массив с четными элементами: \n"; Print(even_arr, even_size);
	cout << "Массив с нечетными элементами: \n"; Print(odd_arr, odd_size);

	delete[] odd_arr;
	delete[] even_arr;

	/*
	После того как дин.массив уже не нужен его нужно удалить - оператор delete
	Он освобождает память, занимаемую дин.массивом.
	*/
#endif EVEN_ODD_DISTRIBUTION

	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Ч/з арифметику указателей и оператор разыменования
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//[] - Оператор индексирования (subscript operator)
		cout << arr[i] << "\t";
	}
	cout << endl;
}