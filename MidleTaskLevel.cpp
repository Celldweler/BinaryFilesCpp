#include"FunctionsUsed.h"

using namespace std;
/*
Дан файл f, компоненты которого являются целыми числами. Никакая из компонент файла не равна нулю. Файл f содержит столько же 
отрицательных чисел, сколько и положительных. Используя вспомогательный файл h, переписать компоненты файла f в файл g так, чтобы в файле
g сначала шли положительные, потом отрицательные числа.
*/
void MidleTaskLevel()
{//C:\\Users\\$Raime\\source\\repos\\Temp
	cout << "\Midle task level\n";
	FILE* f_out, f_in,
		    h_out, h_in,//temp_file
		    g_out, g_in ;//файл в который надо записать сначала поло-ые числа затем отриц-ые
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