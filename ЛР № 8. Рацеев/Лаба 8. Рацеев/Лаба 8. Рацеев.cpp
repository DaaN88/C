// Лаба 8. Рацеев.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	FullConsoleWindow FullCnslWindow;
	FullCnslWindow.ConsoleWindowProc();

	using namespace std;

	cout << "ЛАБА № 8. ОБРАБОТКА И МОДИФИКАЦИЯ ДВУМЕРНЫХ МАССИВОВ." << endl;

	char chQuit;

	do
	{

	} while (cout << "Хотите продолжить? y/д - да, любой другой символ - нет: " && cin >> chQuit && chQuit == 'y' && cout << endl || chQuit == 'д' && cout << endl);

    return 0;
}

