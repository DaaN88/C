// Лаба 7. Рацеев.cpp: определяет точку входа для консольного приложения.
// Требуется выделить в строке-предложении s все слова, разделенные символами - разделителями «_., ; :\n\t!? », и обработать выделенные слова в соответствии с вариантом задания.
// A11. Напечатать все слова, не содержащие ни одной цифры.

#include "stdafx.h"

#define delim " _/.,:;?!\n\t"
#define delims "йцукенгшщзхъфывапролджэячсмитьбю.ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮqwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM _/.,:;?!\n\t"

void FuncString(std::string *stringOutMain, std::vector<std::string> *vectorParam);										// прототип функции вывода слов разделенных разделителями объявленных в delim
void FuncReturnNumbOnStr(std::string *stringOutMain_two, std::vector<std::string> *vectorParam_two);					// прототип функции вывода слов состоящих только из цифр
void FuncOfFind_TheSameNumbers(std::vector<std::string> *vectorParam_three, int *ValueForCounter);						// прототип функции поиска и подсчета количества слов состоящих только из одинаковых цифр
void FuncOfFind_TheSameLetters(std::vector<std::string> *vectorParam_four, int *ValueForCounter_two);					// прототип функции поиска и подсчета количества слов состоящих только из одинаковых букв
void FuncForIterator(std::string *stringOutMain_three);																	// прототип функции для реализации примера работы итераторов
void FuncFindLettersOnString(std::string *stringOutMain_four);															// прототип функции поиска определенного символа в строке
void FuncCharString(std::string *stringOutMain_five, std::vector<std::string> *VecFor_FuncCharString, char *(temp[]));	// прототип функции вывода слов с новой строки разделенных разделителями объявленных в delim методами языка С
void FuncWork_substr(std::string *stringOutMain_six);
void FuncASCII(std::string *stringOutMain_seven);
void FuncReplaceLetters(std::vector<std::string> *TempVec);


int main()
{
	FullConsoleWindow FullCnslWindow;
	FullCnslWindow.ConsoleWindowProc();

	using namespace std;

	cout << "ОБРАБОТКА ТЕКСТОВЫХ СТРОК" << endl;
	
	char chQuit;

	do
	{
		string sUser_Entered_String;	// строка вводимая пользователем
		int countForSwitch;				// переменная для выбора пункта меню switch 

		cout << "Введите строку: ";
		getline(cin, sUser_Entered_String);

		cout << "Выберите пункт: " << endl;
		cout << "1. Посмотреть пример работы string::begin (с использованием итераторов);" << endl;
		cout << "2. Обработка строки методами Си (вывод только слов, разделенных разделителями);" << endl;
		cout << "3. Пример поиска символа в подстроке;" << endl;
		cout << "4. Пример использования функции substr(pos,length) (возврат подстроки из строки, начина с номера pos длиной length символов);" << endl;
		cout << "5. Пример работы с ASCII кодами;" << endl;
		cout << "6. Пример работы со строками через контейнер vector<string>. Вывод только слов, разделенных разделителями;" << endl;
		cout << "7. Пример работы со строками через контейнер vector<string>. Вывод только слов состоящих только из цифр" << endl;
		cout << "8. Вывод количества слов, состоящих из одинаковых букв;" << endl;
		cout << "9. Вывод количества слов, состоящих из одинаковых цифр;" << endl;
		cout << "10. Пример переворота слова (если в слове есть хотя бы одна цифра)." << endl;
		cout << "Введите номер выбранного пункта: ";
		cin >> countForSwitch;

		switch (countForSwitch)
		{
		case 1:
		{
			cout << "Работа string::begin" << endl;
			FuncForIterator(&sUser_Entered_String);
			break;
		}
		case 2:
		{
			cout << "Работа со строками через методы языка С. Вывод только слов, разделенных разделителями" << endl;
			vector<string> emptyTempVec;
			char *TempChar;
			
			FuncCharString(&sUser_Entered_String, &emptyTempVec, &TempChar);
			
			cout << "Второй элемент введенной строки пользователем: " << TempChar[2] << endl;
			
			for (unsigned i = 0; i < emptyTempVec.size(); i++)
			{
				std::cout << "Слово № " << i << ": " << emptyTempVec[i] << std::endl;
			}
		}
			break;
		case 3:
		{
			cout << "Поиск символа в подстроке" << endl << endl;
			FuncFindLettersOnString(&sUser_Entered_String);
		}
			break;
		case 4:
		{
			cout << "Использование функции substr(pos,length) (возврат подстроки из строки, начина с номера pos длиной length символов)" << endl << endl;
			FuncWork_substr(&sUser_Entered_String);
		}
			break;
		case 5:
		{
			cout << "Работа с ASCII кодами" << endl << endl;
			FuncASCII(&sUser_Entered_String);
		}
			break;
		case 6:
		{
			cout << "Работа со строками через контейнер vector<string>. Вывод только слов, разделенных разделителями" << endl;
			vector<string> emptyVectorFor_FuncString;												// переменная для сохранения всего вектора из функции FuncString

			FuncString(&sUser_Entered_String, &emptyVectorFor_FuncString);
			for (unsigned int i = 0; i < emptyVectorFor_FuncString.size(); i++)						// Цикл вывода элементов (слов после разделителя какждый раз с новой строки) вектора на экран
			{
				cout << emptyVectorFor_FuncString[i] << endl;
			}
			if (emptyVectorFor_FuncString.size() == 0)
			{
				cout << "пусто" << endl;
			}
		}
		break;
		case 7:
		{
			cout << "Работа со строками через контейнер vector<string>. Вывод только слов состоящих только из цифр" << endl;
			vector<string> VectorFor_FuncReturnNumbOnStr;

			FuncReturnNumbOnStr(&sUser_Entered_String, &VectorFor_FuncReturnNumbOnStr);
			
			for (unsigned int i = 0; i < VectorFor_FuncReturnNumbOnStr.size(); i++)
			{	
				cout << VectorFor_FuncReturnNumbOnStr[i] << endl;
			}
			if (VectorFor_FuncReturnNumbOnStr.size() == 0)
			{
				cout << "пусто" << endl;
			}
		}
		break;
		case 8:
		{
			cout << "Количество слов, состоящих из одинаковых букв" << endl << endl;
			
			vector<string> emptyVectorFor_FuncString;
			int counterFor_FuncOfFind_TheSameLetter;															// переменная для сохранения результата подсчета количества слов состоящих из одинаковых цифр из функции FuncOfFind_TheSameNum
			
			FuncString(&sUser_Entered_String, &emptyVectorFor_FuncString);
			FuncOfFind_TheSameLetters(&emptyVectorFor_FuncString, &counterFor_FuncOfFind_TheSameLetter);		// вызов функции поиска и подсчета слов состоящих из одинковых цифр. Передача в эту функцию вектора со строками из цифр и переменной для сохранения количества найденных слов из одинаковых цифр
			
			cout << "Количество слов с одинаковыми буквами (все буквы одинаковы): " << counterFor_FuncOfFind_TheSameLetter << endl;
		}
			break;
		case 9:
		{
			cout << "Количество слов, состоящих из одинаковых цифр" << endl << endl;
			
			vector<string> VectorFor_FuncReturnNumbOnStr;
			int counterFor_FuncOfFind_TheSameNumber;															// переменная для сохранения результата подсчета количества слов состоящих из одинаковых цифр из функции FuncOfFind_TheSameNum
			
			FuncReturnNumbOnStr(&sUser_Entered_String, &VectorFor_FuncReturnNumbOnStr);
			FuncOfFind_TheSameNumbers(&VectorFor_FuncReturnNumbOnStr, &counterFor_FuncOfFind_TheSameNumber);	// вызов функции поиска и подсчета слов состоящих из одинковых цифр. Передача в эту функцию вектора со строками из цифр и переменной для сохранения количества найденных слов из одинаковых цифр
			
			cout << "Количество слов только из одинаковых цифр: " << counterFor_FuncOfFind_TheSameNumber << endl;
		}
			break;
		case 10:
		{
			vector<string> emptyTempVec;
			char * TempChar;
			
			FuncCharString(&sUser_Entered_String, &emptyTempVec, &TempChar);
			FuncReplaceLetters(&emptyTempVec);

		}
			break;
		}
	
// -----------------------------------------------------------------------------------------------------------------------
	} while (cout << "Хотите повторить? y/д - да, любой другой символ - нет:  " && cin >> chQuit && (chQuit == 'y' || chQuit == 'д') && cin.get() && cout << endl);
	
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------- ФУНКЦИИ ----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// --------------------------------------------- Функция вывода слов с новой строки разделенных разделителями объявленных в delim ---------------------------------------------

void FuncString(std::string *stringOutMain, std::vector<std::string> *vectorParam) // передаем в функцию строку введенную пользователем, вторым параметром передаем переменную для сохранения размера вектора (вектора с уже разделенными словами) полученного в функции, третьим параметром передаем пустой вектор (в функции он заполняется и передается в main уже со строками)
{
	std::string strToFuncString;
	std::vector<std::string> vVector_ForEnteredString; // создаем контейнер vector типа string для добавления в этот вектор обработанных строк (какждое слово после разделителя с новой строки)
	char delims2[] = "1234567890";
	size_t separator;

	strToFuncString = (*stringOutMain);

	while ((separator = strToFuncString.find_first_of(delim)) != std::string::npos)
	{
	vVector_ForEnteredString.push_back(strToFuncString.substr(0, separator));	// кусок строки до первого разделителя
	strToFuncString = strToFuncString.substr(separator + 1);					// вырезать вместе с разделителем
	}
	vVector_ForEnteredString.push_back(strToFuncString);						// дописать остаток строки

	for (unsigned int i = 0; i < vVector_ForEnteredString.size(); i++)																												// цикл для вывода элементов контейнера vector на экран. Элементы сформированы через цикл while (сверху, перед этим циклом)
	{
		for (unsigned int j= 0; j < strlen(delims2); ++j)																															// цикл проверки наличия цифры в слове. В случае наличия цифры в слове, цифра выкидывается, выводится слово без цифр
			{
				vVector_ForEnteredString[i].erase(remove(vVector_ForEnteredString[i].begin(), vVector_ForEnteredString[i].end(), delims2[j]), vVector_ForEnteredString[i].end());	// осуществляется поиск цифр среди элементов контейнера vector и происходит стирание цифр
			}
	}
	
	// реализация удаления пустых строк из вектора. В результате выполнения цикла вывода элементов вектора и стирания из этих элементов букв
	std::vector<std::string>::iterator it = std::remove_if
	(
		vVector_ForEnteredString.begin(),
		vVector_ForEnteredString.end(),
		[](const std::string &p)
	{
		return p.empty();
	}
	);

	vVector_ForEnteredString.erase(it, vVector_ForEnteredString.end());
	
	(*vectorParam) = vVector_ForEnteredString;								// возвращаем весь вектор в функцию main
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------- Функция поиска в веденных пользователем строках слов состоящих только из цифр и вывод только цифр на экран ---------------------------------
void FuncReturnNumbOnStr(std::string *stringOutMain_two, std::vector<std::string> *vectorParam_two)
{
	size_t sepr;
	std::vector<std::string> vVecOfNumbers; // создаем контейнер vector типа string для сохранения только строк из чисел (все буквы удаляются)
	char delims3[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮйцукенгшщзхъфывапролджэячсмитьбю";
	std::string strTo_FuncReturnNumbOnStr = (*stringOutMain_two);

	while ((sepr = strTo_FuncReturnNumbOnStr.find_first_of(delims)) != std::string::npos)
	{
		vVecOfNumbers.push_back(strTo_FuncReturnNumbOnStr.substr(0, sepr));		// кусок строки до первого разделителя
		strTo_FuncReturnNumbOnStr = strTo_FuncReturnNumbOnStr.substr(sepr + 1);	// вырезать вместе с разделителем
	}
	vVecOfNumbers.push_back(strTo_FuncReturnNumbOnStr);							// дописать остаток строки

	for (unsigned int i = 0; i < vVecOfNumbers.size(); i++)																					// цикл для вывода элементов контейнера vector на экран. Элементы сформированы через цикл while (сверху, перед этим циклом)
	{
		for (unsigned int j = 0; j < strlen(delims3); ++j)																					// цикл проверки наличия цифр в слове. В случае наличия цифры в слове, цифра выкидывается, выводится слово без цифры
		{
			vVecOfNumbers[i].erase(remove(vVecOfNumbers[i].begin(), vVecOfNumbers[i].end(), delims3[j]), vVecOfNumbers[i].end());			// осуществляется поиск букв среди элементов контейнера vector и стирает такие символы (буквы)
		}																									
	}
	
	/*
	Реализация удаления пустых строк из вектора. В результате выполнения цикла вывода элементов вектора и стирания из этих элементов букв.
	Создаем итератор и присваиваем ему алгоритм remove_if (находится в пространстве имен std). Начинаем поиск с начала вектора (vVecOfNumbers.begin()) (в нашем случае vVecOfnumbers) и до
	конца вектор (vVecOfNumbers.end()). Алгоритм remove_if как и remove "удаляет" все элементы (одного типа) которые найдет. Под "удаляет" понимается перемещение всех элементов (элементов удовлетворяющих
	условию поиска (третий параметр в алгоритме remove_ir(remove)), то есть элементов которые нужно удалить) вектора в конец, но не полное удаление из памяти данных элементов.
	Полное удаление осуществляется методом .erase() (vVecOfNumbers.erase()).
	После отработки алгоритма remove (remove_if), алгоритм возвращает результат с указанием на место (отметка) за последним нужным (не входящим в условие исключения) элементом. Грубо говоря, нужные элементы
	вектора помещаем в одно место, не нужные - в другое и между ними есть отметка (граница или итератор указывающий на первый не нужный элемент).
	В метод .erase() нужно передать два параметра. Первый - это ту самую границу (в нашем случае it) между нужными и не нужными элементами. А второй - конец вектора (vVecOfNumbers.end()). То есть это
	диапазон элементов который начинается с первого не нужного элемента и до конца вектора, а все не нужные элементы и так находятся в конце вектора.
	Разница между методами remove и remove_if.
	Третий параметр remove задается "жестко". И через операторы сравнения сравнивается с каждым элементом вектора.
	Метод (алгоритм) remove_if позволяет третьим параметром задать предикат, к примеру в виде лямбда функции, для более "гибкого" отбора элементов.
	Параметром этот предикат (лямбда функция) должен принимать константную ссылку на объект класса. В нашем случае объект типа string и возвращать какое-то логическое возвращение. В нашем случае
	возвращается пустая строка. В случае если строка пуста то предикат (лямбда функция) возвращает true и пустая строка помещаетя в конце вектора (vVecOfNumvers).
	*/
	std::vector<std::string>::iterator it = std::remove_if
	(
		vVecOfNumbers.begin(),
		vVecOfNumbers.end(),
		[](const std::string &p)
	{
		return p.empty();
	}
	);

	vVecOfNumbers.erase(it, vVecOfNumbers.end());
	
	(*vectorParam_two) = vVecOfNumbers;					// возвращаем вектор в функцию main (оператор switch case 7)
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------- Функция поиска слов состоящих только из одинковых букв и подсчет количества таких слов -------------------------------------------
void FuncOfFind_TheSameLetters(std::vector<std::string> *vectorParam_four, int *ValueForCounter_two)
{
	std::vector<std::string> vVecOf_TheSameLetters;			// создаем контейнер vector типа string для сохранения передаваемого вектора из функции main
	std::string strTemp;
	int iCounterTheSameLetters;								// в эту переменную сохраняется размер строки (тип string), для сравнения размера строки с размером элемента вектора (vector)
	int iCounterEnd = 0;									// пременная-счетчик количества слов состоящих из одинаковы букв
	int tempSizeVec;										// в эту переменную сохраняется размер элемента вектора (каждого элемента)

	vVecOf_TheSameLetters = (*vectorParam_four);

	setlocale(LC_ALL, "");																// иначе не работает функция tolower. Изначально функция tolower работает только с латинскими буквами

	for (unsigned int k = 0; k < vVecOf_TheSameLetters.size(); k++)						// цикл поиска слов состоящих из одинаковых букв
	{
		if (vVecOf_TheSameLetters[k].empty())											//если строка пустая (элемент вектора пустой) из-за удаления разделеителей delim в цикле выше
		{
			continue;																	// пропускаем элемент вектора
		}
		else if (!vVecOf_TheSameLetters[k].empty())										// в противном случае, принимаем элементы состоящие из буквы
		{
			strTemp = vVecOf_TheSameLetters[k];											// передача каждую итерацию (лишь одного) элемента контейнера вектора vVector_ForEnteredString в массив string strTemp

			tempSizeVec = vVecOf_TheSameLetters[k].size();								// сохраняем значение размера элемента вектора для возможности работы с каждым символов элемента вектора

			transform(strTemp.begin(), strTemp.end(), strTemp.begin(), tolower);		// приводим к одному регистру все буквы (для правильного сравнения)

			for (unsigned int p = 0; p < strTemp.size() - 1; p++)						// до тех пор пока p меньше размера массива (-1 для исключения терминирующего нуля из проверки)
			{
				if (strTemp[p] == strTemp[p + 1])										// проверяем предыдущий элемент со следующим (по порядку, с лево на право)
				{
					iCounterTheSameLetters = strTemp.size();							// если все элементы равны между собой, присваиваем новой (временной) переменной значение размера строки.
				}
				else if (strTemp[p] != strTemp[p + 1])									// если есть элементы не равные между собой, присваиваем этой же временной переменной значение ноль (0)
				{
					iCounterTheSameLetters = 0;
					break;																// в случае хотя бы одного несовпадения символов элемента строки, прекращаем цикл, т.к. это условие полное и достаточное чтобы считать всю строку не из одинаковых букв
				}
			}
		}
		if (iCounterTheSameLetters == tempSizeVec)										// сравниваем значение новой (временной) переменной с переменной со значением размера элемента вектора
		{
			iCounterEnd++;																// если переменные равны, то в элементы все буквы равны и увеличиваем счетчик на единицу
		}
		(*ValueForCounter_two) = iCounterEnd;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------- Функция поиска слов состоящих только из одинковых цифр и подсчет количества таких слов -------------------------------------------
void FuncOfFind_TheSameNumbers(std::vector<std::string> *vectorParam_three, int *ValueForCounter)
{
	std::string stringToNumbers;						// Перемення для сохранения элементов вектора как строки (для сравнения каждого символа в строке)
	std::vector<std::string> vVecOf_TheSameNumbers;		// создаем контейнер vector типа string для сохранения передаваемого вектора из функции main
	int NumbForSize;									// переменная для сохранения размера элемента вектора
	int TempVecSize;									// в эту переменную сохраняется размер строки (тип string), для сравнения размера строки с размером элемента вектора (vector)
	int counter = 0;

	vVecOf_TheSameNumbers = (*vectorParam_three);

	for (unsigned i = 0; i < vVecOf_TheSameNumbers.size(); i++) // подсчет количества слов состоящих из одинаковых чисел. Логика цикла аналогична циклу подсчета слов состоящих из одинаковых букв
	{
		if (vVecOf_TheSameNumbers[i].empty())
		{
			continue;
		}
		else if (!vVecOf_TheSameNumbers[i].empty())
		{
			stringToNumbers = vVecOf_TheSameNumbers[i];

			NumbForSize = vVecOf_TheSameNumbers[i].size();

			for (unsigned k = 0; k < stringToNumbers.size() - 1; k++)
			{
				if (stringToNumbers[k] == stringToNumbers[k + 1])
				{
					TempVecSize = stringToNumbers.size();
				}
				else if (stringToNumbers[k] != stringToNumbers[k + 1])
				{
					TempVecSize = 0;
					break;
				}
			}
		}
		if (TempVecSize == NumbForSize)
		{
			counter++;
		}
		(*ValueForCounter) = counter;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------- Функция реализации примера работы итераторов ---------------------------------------------------------------
void FuncForIterator(std::string *stringOutMain_three)
{
	for (std::string::iterator it = (*stringOutMain_three).begin(); it != (*stringOutMain_three).end(); ++it) // --it не делать. Цикл уходит в бесконечное выполнение
	{
		std::cout << *it << std::endl;
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------- Функция поиска символа в строке ----------------------------------------------------------------------
void FuncFindLettersOnString(std::string *stringOutMain_four) 
{
	bool flag = true;
	decltype((*stringOutMain_four).cbegin()) iter;
	size_t position = 0;

	iter = std::find((*stringOutMain_four).cbegin(), (*stringOutMain_four).cend(), 'т');
	for (unsigned int i = 0; i < (*stringOutMain_four).size(); i++) // цикл для реализации проверки каждой буквы (символа) строки sUser_Entered_String (введенной пользователем)
	{
		if ((*stringOutMain_four)[i] == 'т' && flag) // если символ равен 'т', то блок if выполняется, то есть позиция символа выводится на экран
		{
			position = std::distance((*stringOutMain_four).cbegin(), iter);
			std::cout << "Позиця первой 'т': " << position << "\n";
			assert(position == sUser_Entered_String.find('т'));
			std::cout << std::endl;
			flag = false;
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------- Функция вывода слов с новой строки разделенных разделителями объявленных в delim методами языка С -------------------------------------
void FuncCharString(std::string *stringOutMain_five, std::vector<std::string> *VecFor_FuncCharString, char *(temp[]))
{
	char *context = NULL;
	char *array = new char[(*stringOutMain_five).size() + 1];
	std::vector<std::string> VectorString;

	strcpy_s(array, ((*stringOutMain_five).size()) + 1, (*stringOutMain_five).c_str());

	(*temp) = array;
	//std::cout << "Второй элемент введенной строки пользователем: " << array[2] << std::endl;

	//puts(array); // выводит только строки, числа не может. Работает быстрее printf() и cout, занимает меньше места.

	char *leksem = strtok_s(array, delim, &context);

	int icntr = 1; // переменная счетчик для подсчета (и вывода) количества слов
	while (leksem != NULL)
	{
		VectorString.push_back(leksem);
		leksem = strtok_s(NULL, delim, &context);
		icntr++;
	}

	(*VecFor_FuncCharString) = VectorString;

	delete[] array;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------- s.substr(pos, length) — возвращает подстроку из строки s, начиная с номера pos длинной length символов -----------------------------------
void FuncWork_substr(std::string *stringOutMain_six)
{
	if ((*stringOutMain_six).size() > 3) // так как начинаем искать третий символ, то в случае длины вводимой строки меньше или равной трем символам, срабатывает блок else
	{
		std::string hy = (*stringOutMain_six).substr(3, (*stringOutMain_six).size()); // если строка больше чем три символа, то в данной строке ищем и выводим начиная с третьего символа оставшуюся строку (подстроку)

		std::cout << hy << std::endl;
	}
	else
	{
		std::cout << "ошибка" << std::endl;
	}
	std::cout << std::endl; // пропуск строки (для отделения одного блока программы от другого. для удобства восприятия)
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------- Функция работы с кодами ASCII ------------------------------------------------------------------------
void FuncASCII(std::string *stringOutMain_seven)
{
	int sum = 0;
	for (unsigned int i = 0; i < (*stringOutMain_seven).size(); i++)
	{
		sum += static_cast <unsigned int> (static_cast<unsigned char> ((*stringOutMain_seven)[i]) );																																			// суммирование ASCII кодов
		sum++;																																										// подсчет количества символов
		std::cout << "код буквы " << (*stringOutMain_seven)[i] << ": " << static_cast <unsigned int> (static_cast<unsigned char> ((*stringOutMain_seven)[i]) )<< std::endl;			// вывод ASCII кода каждой буквы
	}

	std::cout << "Сумма ASCII кодов букв: " << sum << std::endl;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------- Функция реверса числа в нем есть хотя бы одна цифра----------------------------------------------------------------
void FuncReplaceLetters(std::vector<std::string> *TempVec)
{
	std::string LocalStringTemp;
	bool flag;
	char temp;

	for (unsigned i = 0; i < (*TempVec).size(); i++)								//в цикл передается элемент вектора (каждый элемент прогоняется через цикл)
	{
		flag = true;
		LocalStringTemp = (*TempVec)[i];											//приводим к типу string элемент вектора
		for (unsigned k = 0; k < LocalStringTemp.size()-1; k++)
		{
			if (isdigit(LocalStringTemp[k]) && flag)								//проверка - является ли символ цифрой. Если является, то выполняется цикл for
			{
				for (int j = 0, p = LocalStringTemp.size() - 1; j < p; --p, ++j)	//в этом цикле реализуется реверс (переворот задо наперед) слова (если в слове есть хотя бы одна цифра)
				{
					temp = LocalStringTemp[p];
					LocalStringTemp[p] = LocalStringTemp[j];
					LocalStringTemp[j] = temp;
				}
			std::cout << LocalStringTemp << std::endl;
			
			std::cout << "Переворот слова еще раз" << std::endl;

			for (int k = LocalStringTemp.size() - 1; k >= 0; k--)					// второй вариант перевората числа (вовода слова задом наперед)
				{
				std::cout << LocalStringTemp[k];									// так как выше, в цикле, слово уже переворачивается, то в данном цикле оно переворачивается еще раз и получается изначальная строка переданная пользователем
				}
			std::cout << std::endl;
			std::cout << std::endl;
			flag = false;															//так как вывод реверсивного (уже перевернутого) слова осуществляется в цикле и чтобы слово не повторялось несколько раз (количество повторений равно количеству итераций первого цикла for), применяем булевскую переменную (сначала равна true чтобы вывод осуществился, дальше присваиваем false чтобы вывод не повторялся)
			}
		}
	}
}