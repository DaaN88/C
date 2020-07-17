// Для включения файлов с расширением .срр в файл с реализацией основного кода (то есть с функцией main() ) необходимо поменять настройки (Проект - Свойства проекта - С/С++ - 
// - Предварительно откомпилированные заголовки - Не использовать предварительно скомпилированные заголовки). Вызов функции ConsoleWindowProc() осуществить до реализации основного кода.

#include <windows.h>
#include <conio.h>

class FullConsoleWindow
{
public:
	void ConsoleWindowProc()
	{
		SetConsoleCP(1251); // вывод на экран русских букв
		SetConsoleOutputCP(1251); // реализация ввода русскими буквами в объект cin
		HWND window_header = GetConsoleWindow(); // Функция GetConsoleWindow извлекает дескриптор окна, используемый консолью, связанной с вызывающим процессом.
		HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE); // STD_OUTPUT_HANDLE - Дескриптор устройства стандартного вывода. Вначале, это - дескриптор активного экранного буфера консоли. Функция GetStdHandle извлекает дескриптор для стандартного ввода данных, стандартного вывода или стандартной ошибки устройства.
		COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // размер самого большого возможного консольного окна
		SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 }; // Структура SMALL_RECT определяет координаты верхнего левого и нижнего правого углов прямоугольника.
		// Left: Х - координата верхнего левого угла прямоугольника (здесь - 0); Тор: Y - координата верхнего левого угла прямоугольника (здесь - 0). Right: X-координата нижнего правого угла прямоугольника (здесь maxWindow.X-1); Bottom: Y-координата нижнего правого угла прямоугольника (здесь maxWindow.Y-1)
		SMALL_RECT minWindow = { 0, 0, 0, 0 };
		SetWindowPos(window_header, HWND_TOP, NULL, NULL, NULL, NULL, NULL); // позволяет выставлять окно консоли относительно левого верхнего угла
		SetConsoleWindowInfo(out_handle, true, &minWindow); // Функция SetConsoleWindowInfo устанавливает текущий размер и позицию окна экранного буфера консоли
		SetConsoleScreenBufferSize(out_handle, maxWindow); // Функция SetConsoleScreenBufferSize изменяет размер заданного экранного буфера консоли.
		SetConsoleWindowInfo(out_handle, true, &srctWindow);
		SetConsoleTextAttribute(out_handle, FOREGROUND_GREEN); // изменение цвета букв на зеленый
	}
};
