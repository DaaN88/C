// ��� ��������� ������ � ����������� .��� � ���� � ����������� ��������� ���� (�� ���� � �������� main() ) ���������� �������� ��������� (������ - �������� ������� - �/�++ - 
// - �������������� ����������������� ��������� - �� ������������ �������������� ���������������� ���������). ����� ������� ConsoleWindowProc() ����������� �� ���������� ��������� ����.

#include <windows.h>
#include <conio.h>

class FullConsoleWindow
{
public:
	void ConsoleWindowProc()
	{
		SetConsoleCP(1251); // ����� �� ����� ������� ����
		SetConsoleOutputCP(1251); // ���������� ����� �������� ������� � ������ cin
		HWND window_header = GetConsoleWindow(); // ������� GetConsoleWindow ��������� ���������� ����, ������������ ��������, ��������� � ���������� ���������.
		HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE); // STD_OUTPUT_HANDLE - ���������� ���������� ������������ ������. �������, ��� - ���������� ��������� ��������� ������ �������. ������� GetStdHandle ��������� ���������� ��� ������������ ����� ������, ������������ ������ ��� ����������� ������ ����������.
		COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // ������ ������ �������� ���������� ����������� ����
		SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 }; // ��������� SMALL_RECT ���������� ���������� �������� ������ � ������� ������� ����� ��������������.
		// Left: � - ���������� �������� ������ ���� �������������� (����� - 0); ���: Y - ���������� �������� ������ ���� �������������� (����� - 0). Right: X-���������� ������� ������� ���� �������������� (����� maxWindow.X-1); Bottom: Y-���������� ������� ������� ���� �������������� (����� maxWindow.Y-1)
		SMALL_RECT minWindow = { 0, 0, 0, 0 };
		SetWindowPos(window_header, HWND_TOP, NULL, NULL, NULL, NULL, NULL); // ��������� ���������� ���� ������� ������������ ������ �������� ����
		SetConsoleWindowInfo(out_handle, true, &minWindow); // ������� SetConsoleWindowInfo ������������� ������� ������ � ������� ���� ��������� ������ �������
		SetConsoleScreenBufferSize(out_handle, maxWindow); // ������� SetConsoleScreenBufferSize �������� ������ ��������� ��������� ������ �������.
		SetConsoleWindowInfo(out_handle, true, &srctWindow);
		SetConsoleTextAttribute(out_handle, FOREGROUND_GREEN); // ��������� ����� ���� �� �������
	}
};
