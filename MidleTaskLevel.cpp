#include"FunctionsUsed.h"

using namespace std;
/*
��� ���� f, ���������� �������� �������� ������ �������. ������� �� ��������� ����� �� ����� ����. ���� f �������� ������� �� 
������������� �����, ������� � �������������. ��������� ��������������� ���� h, ���������� ���������� ����� f � ���� g ���, ����� � �����
g ������� ��� �������������, ����� ������������� �����.
*/
void MidleTaskLevel()
{//C:\\Users\\$Raime\\source\\repos\\Temp
	cout << "\Midle task level\n";
	FILE* f_out, f_in,
		    h_out, h_in,//temp_file
		    g_out, g_in ;//���� � ������� ���� �������� ������� ����-�� ����� ����� �����-��
	int handle;
	handle = open("BaseFile", O_CREAT | O_WRONLY | O_TEXT, S_IREAD | S_IWRITE);

	f_out = fopen("C:\\Users\\$Raime\\source\\repos\\Temp\\BaseFile.bin",  "wb");
	int var;
	for (size_t i = 0; i < 10; i++)
	{
		fwrite(&(var = (1 + rand() % 10)), sizeof(int), 1, f_out);
		fwrite(&(var = (-1 - rand() % 10)), sizeof(int), 1, f_out);
		 
	}
	fclose(f_out);
}