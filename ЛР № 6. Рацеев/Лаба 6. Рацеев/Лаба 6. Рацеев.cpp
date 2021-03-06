// Лаба 6. Рацеев.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cmath>
#include "CnslWindow.cpp"

#define N 10
#define A -5500
#define B 5500

//----------------------------------------------
// прототипы функций
void Init(int *a, int n); // функция инициализации массива случайными числами
void Print(int *a, int n); // функция вывода массива на экран
void MinElem(int *a, int n); // функция поиска минимального элемента массива
void MaxElem(int *a, int n); // функция поиска максимального элемента массива
void ExmplA11(int *a, int n); // функция для замены всех нечетных отрицательных элементов массива на наименьший элемент
void ExmplB11(int *a, int n); // функция для вычисления всех составных чисел (элементов) массива и определения самого наименьшего среди них (составных)
int iRevers(int k); // функция возвращающая реверс (перевернутое число). Числа выбираются согласно задания В11 (свойство Т)
void sort(int *a, int n); // функция сортировки массива по возрастанию

int main()
{
	FullConsoleWindow FullCnslWindow; // реализация полноэкранного режима консоли
	FullCnslWindow.ConsoleWindowProc();
	
	using namespace std;

	cout.width(50);
	cout << "МОДИФИКАЦИЯ ОДНОМЕРНЫХ МАССИВОВ" << endl;

	char chQuit; // переменная для обработки введеного пользователем символа (для перезапуска программы)
	
	do
	{
		int iArrPrimodial[N], i;
		int iArrTwo[N]; // второй массив. для создания копии, чтобы не менять изначальный массив
		int iReplacementNumber; // переменная для сохраненния реверсивного (первернутого) числа (из задания В11)
		srand(time(NULL)); // генерация случайных чисел (какждый раз разные числа)
		int first; // переменная для сохранения первой цифры элемента (числа) из массива а (изначального)

		Init(iArrPrimodial, N);
		Print(iArrPrimodial, N);

		MinElem(iArrPrimodial, N); // вызов функции для отображения минимального элемента массива
		MaxElem(iArrPrimodial, N); // вызов функции для отображения максимального элемента массива

		ExmplA11(iArrPrimodial, N); // передаем массив а и количество элементов N. При вызове получаем вывод на экран массива со всеми замененными нечетными отрицательными числами (элементами) массива а на самый минимальный элемент массива а.

		ExmplB11(iArrPrimodial, N); // передаем массив а и количество элементов N. При вызове получаем вывод на экран массива составных чисел и самого минимального составного числа (элемента)

		for (i = 0; i < N; i++) // создание копии массива. Скопированный массив подвергается замене элементов на реверсивные (перевернутые)
		{
			iArrTwo[i] = iArrPrimodial[i]; // присваиваем новому массиву iArrTwo элементы изначального массива iArrPrimordial
		}

		int counter = 0; // переменная-счетчик.
		for (i = 0; i < N; i++)
		{
			int m = iArrPrimodial[i]; // переменная для обработки в цикле. Данной переменной присваивается число (элемент) массива iArrPrimodial.
			
			while (abs(m)>0) // разбиение чисел (элементов) массива iArrPrimodial на цифры, для определения первой цифры числа (элемента)
			{
				first = m % 10;
				m = m / 10;
			}

			if (abs(first) == 2) // если первая цифра числа (элемента) массива iArrPrimodial равна двум, то принимается к исполнению нижеследюущий код в блоке if
			{
				int numb = iArrPrimodial[i]; // в переменную numb сохраняем число (элемент) удовлетворяющее условию if (число (элемент) массива начинается с двойки). Чтобы происходила замена чисел (если их в массиве iArrPrimodial больше чем одно) инициализацию производим в цикле.
				std::cout.width(10);
				cout << "Реверсивное число" << " (элемент № " << i << "): " << iRevers(numb) << endl; // Здесь передаем в функцию iRevers число (элемент) массива удовлетворяющее условию if. Функция iRevers возвращает реверсивное (перевернутое) число (элемент) массива
				iReplacementNumber = iRevers(numb); // сохраняем в переменную iReplacementNumber реверсивное (перевернутое) число (элемент) массива
				iArrTwo[i] = iReplacementNumber; // присваиваем элементу массива iArrTwo (копии изначального) новое реверсивное число (перевернутое)
				counter++; // подсчет количества 
			}
				
		}
		
		if (counter > 0) // реализация вывода на экран массива iArrTwo в случае, если только есть числа удовлетворяющие условию Т (начинаются с 2). Если таких чисел (элементов) массива а нету, то массив iArrTwo на экран не выводится
		{
			cout << endl;
			cout << "Массив с замененными элементами на реверсивные" << endl;
			for (i = 0; i < N; i++)
			{
				std::cout.width(10);
				cout << "[" << i << "]: " << iArrTwo[i] << endl;
			}
			cout << endl;
		}
		else
		{
			cout << "Чисел начинающихся на 2 нет." << endl;
			cout << endl;
		}

		sort(iArrPrimodial, N); // вызов функции сортировки изначального массива iArrPrimodial

	} while (cout << "Хотите повторить? y/д - да, любой другой символ - нет:  " && cin >> chQuit && chQuit == 'y' || chQuit == 'д' && cout << endl << endl);

	cin.get();
    return 0;
}

// Заполенение массива случайными числами
// Массив а здесь это iArrPrimodial (изначальный массив)
//-----------------------------------------------------------

void Init(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		a[i] = A + rand() % (B - A + 1);
}

// Вывод массива на экран
// Массив а здесь это iArrPrimodial (изначальный массив)
//------------------------------------------------------------

void Print(int *a, int n)
{
	std::cout << "Массив чисел (изначальный массив)" << std::endl;
	int i;
	for (i = 0; i < n; i++)
	{
		std::cout.width(10);
		std::cout << "[" << i << "]: " << a[i] << std::endl;
	}
	std::cout << std::endl;
}

// Поиск минимального элемента массива
// Массив а здесь это iArrPrimodial (изначальный массив)
//------------------------------------------------------------

void MinElem(int *a, int n)
{
	int i;
	int min = a[0];
	for (i=0; i<n; i++)
		if (a[i] < min)
		{
			min = a[i];
		}
	std::cout.width(31);
	std::cout << "Минимальный элемент массива: " << min << std::endl;
}

// Поиск максимального элемента массива
// Массив а здесь это iArrPrimodial (изначальный массив)
//-------------------------------------------------------------

void MaxElem(int *a, int n)
{
	int i;
	int max = a[0];
	for (i = 0; i<n; i++)
		if (a[i] > max)
		{
			max = a[i];
		}
	std::cout.width(32);
	std::cout << "Максимальный элемент массива: " << max << std::endl;
	std::cout << std::endl;
}

// Задание А11: заменить отрицательные нечетные элементы массива на наименьший элемент массива
// Массив а здесь это iArrPrimodial (изначальный массив)
//--------------------------------------------------------------

void ExmplA11(int *a, int n)
{
	int i, p, k;
	int arr[N]; // новый массив для создания копии массива iArrPrimodial

	//создаем копию изначального массива iArrPrimodial
	for (i = 0; i < n; i++)
	{
		arr[i] = a[i];
	}

	int min = arr[0]; // предпологаем что самый минимальный элемент массива arr это первый элемент массива (arr[0])

	for (i = 0; i<n; i++)
		if (arr[i] < min) // сравниваем все элементы массива arr с предполагаемым минимальным. Если попадается элемент меньше нашего предполагаемого элемента, то
		{
			min = arr[i]; // запоминаем его в переменной min
		}

	for (k = 0; k < n; k++)
		if (arr[k] < 0 && arr[k]%2 != 0) // проверяем каждый элемент массива arr на отрицательность и нечетность
		{
			std::cout.width(10);
			std::cout << "Элемент № " << k << ": " << arr[k];
			arr[k] = min; // если элемент массива arr удовлетворяет условию блока if, то заменяем этот элемент самым минимальным элементом массива а (изначального массива)
			std::cout << " заменен на самый минимальный элемент: " << min << std::endl;
		}
	std::cout << std::endl;

	std::cout << "Массив после замены отрицательных нечетеных чисел (элементов) на самый минимальный элемент массива: " << std::endl;
	for (p = 0; p < n; p++)
	{
		std::cout.width(10);
		std::cout << "[" << p << "]: " << arr[p] << std::endl;
	}
	std::cout << std::endl;
}

// Задание В11: Найти минимальный элемент массива из всех элементов являющихся составными. Все элементы массива а начинающиеся на два, заменить на их обратные отображения (например 123 заменить на 321).
// Отсортировать массив по возрастанию. После инициализации и преобразования выводить массив на экран.
// Составное число: число которое образуется умножением двух натуральных чисел отличных от единицы (Exmpl: 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, …)
// Массив а здесь это iArrPrimodial (изначальный массив)
//------------------------------------------------------------------------------

void ExmplB11(int *a, int n) // Функция реализует нахождение чисел (элементов) массива удовлетворяющих свойству Q: найти минимальный элемент массива из всех элементов являющихся составными. И выводит такой элемент на экран.
{
	std::cout.width(10);
	std::cout << "Массив составных чисел: " << std::endl;
	
	int i, min2; // переменные i - итератор в циклах for. Переменная min принимает значение нулевого (первого) элемента массива iArrCompound
	int j = 0; // переменная-счетчик.
	int arr2[N]; // новый массив для создания копии массива iArrPrimodial
	bool flag = true; // логическая переменная используемая в блоке if для установки первого минимального (предполагаемого) числа (элемента) массива iArrPrimodial из составных чисел (элементов) этого массива.

	for (i = 0; i < n; i++)//создаем копию изначального массива iArrPrimodial
	{
		arr2[i] = a[i];
	}
		
	for (i = 0; i < n; i++) // через цикл "пропускаем" все числа массива iArrPrimodial
	{
		if ((abs(arr2[i]) > 4 && abs(arr2[i]) != 5 && abs(arr2[i]) != 7) && (arr2[i] % 2 == 0 || arr2[i] % 3 == 0 || arr2[i] % 5 == 0 || arr2[i] % 7 == 0)) // если число удовлетворяет условию if то число записывается в массив iArrCompound. Здесь определем - является ли число составным
		{
			std::cout.width(10);
			std::cout << "[" << i << "]: " << arr2[i] << std::endl; // вывод всех элементов массива составных чисел (iArrCompound)
			if (arr2[i] < 0 && flag)
			{
				min2 = arr2[i]; // первый минимальный элемент среди составных
				flag = !flag; // метка (flag) в первую итерацию становится "ложью" и в последующие итерации этот блок будет проспукаться. Таким образом реализуется "установка" первого (предполагаемого) минимального элемента (числа) массива iArrPrimodial из составных чисел (элементов) этого массива
			}
			if (arr2[i] < min2)
			{
				min2 = arr2[i];
			}
		}
	}

	std::cout << "Минимальный элемент из составных: " << min2 << std::endl << std::endl;
}

// Возврат перевернутого (реверсивного) числа (элемента) массива обладающего свойством Т: все элементы массива начинающиеся на два, заменить на их обратные отображения (например 123 заменить на 321).
//-----------------------------------------------

int iRevers(int k) // функция реверса (переворота) числа
{
	int number; // переменная для сохранения последней цифры элемента (числа) из массива а (изначального).
	int u = k; // переменная принимающая значение (число) элемента массива (передается из функции main() ).
	int iTemp; // переменная для временного хранения результата "разделения" числа (элемента) массива на цифры. Хранит последнюю цифру (остаток от деления на 10).
	int r = 0;

			while (abs(u) != 0) // реализация реверса (переворота) числа поступающего из функции main
			{
				iTemp = u % 10;
				r = r * 10 + iTemp; // умножением на 10 посленей цифры числа добиваемся "переноса" этой цифры на первое место
				u = u / 10;
			}

			while (abs(k) != 0) // пока число (элемент) массива не равно нулю
			{
				number = k % 10; // находим остаток от деления (отбрасываем целую часть). Получаем последнюю цифру числа.
				if (number == 0) // если последняя цифра равна нулю
				{
					r = r * 10; // то умножаем перевернутое (ранее, в цикле while сверху) число на 10. Так как при реверсе числа происходит отбрасывание последнего нуля (240 => 42). Умножаем столько раз, сколько нулей встретим до первой цифры с конца числа (240 - один ноль. 2400 - два нуля. 2040 - один ноль).
				}
				else // как встречаем цифру отлчиную от нуля
				{
					break; // прерываем этот цикл
				}
				k = k / 10; // отбрасываем остаток (если нулей несколько с конца). Продолжаем работать с целой частью числа (было 120, станет 12. Было 2400, станет 240).
			}
			return r; // возвращаем в main() уже реверсивное (перевернутое) число
}

// Сортировка массива по возрастанию
// Массив а здесь это iArrPrimodial (изначальный массив)
//------------------------------------------------------------------

void sort(int *a, int n)
{
	std::cout.width(10);
	std::cout << "Отсортированный массив по возрастанию: " << std::endl;

	int tmp;
	for (int i = 0, j = 0; i<n; i++)
	{
		tmp = a[i]; // запоминаем во временной переменной число (элемент) массива а
		j = i - 1; // уменьшаем итератор j на 1 за каждую итерацию
		while ((j >= 0) && (a[j] > tmp)) // так как, за первую итерацию j будет равен -1, то цикл while не будет выполняться.
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = tmp; // в первую итерацию j+1 будет равен 0, то есть получается а[0] = tmp. А так как tmp = a[i], то a[0] = a[0], только правый а[0] это элемент из массива а, изначального массива.
	}
	for (int k = 0; k < n; k++) // выводим отсортированный массив
	{
		std::cout.width(10);
		std::cout << "[" << k << "]: " << a[k] << std::endl;
	}
}