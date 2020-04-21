#include <sys/types.h>      /* включение необходимых заголовочных файлов */ 
#include <fcntl.h> 
#include <stdlib.h> 
#include<stdio.h>
#include <sys\stat.h>
#include <io.h>
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;
#pragma warning(disable : 4996)
#define BUF_SIZE 4096               
void Base();
void Midle();
void Hard();

int main(int argc, char *argv[]) 
{
    srand(time(0));
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "");

    Base();
   // Midle();
    //Hard();
}

void Base()
{
    cout << "\nBase task level\n";
/*
Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:  
 - Наименование товара; 
 - Стоимость единицы товара; 
 - Количество каждого товара. 
Определить общую стоимость товара, предложенного для реализации, и его среднюю цену
*/

}

void Midle()
{
    /*
Ввести в Memo или в StringGrid некоторое количество вещественных чисел и записать их в бинарный файл.
Переписать бинарный файл так, чтобы каждое значение, записанное в файле,  было увеличено в 1,5 раза. 
Распечатать числа до и после изменения данных в файле.
    */
    cout << "\Midle task level\n";
    int countelem = 2 + rand() % 20;
    const char* file_name = "doubledigitfile";
    FILE* f_out = fopen(file_name, "wb");
    double* buffer = new double[countelem] ;
    for (size_t i = 0; i < countelem; i++)
    {
        buffer[i] = - 10 - ( (rand() % 100) / 100.0);
    }
    
    fwrite(buffer, sizeof(double), countelem, f_out);
    fclose(f_out);
    cout << "\nData reading in file <<doubledigitfile.bin>>: \n";
    f_out = fopen(file_name, "rb");
    fread(buffer, sizeof(double), countelem, f_out);
    for (size_t i = 0; i < countelem; i++)
    {
        cout << buffer[i]<<" ";
         buffer[i] *= 1.5;
    }
    
    fclose(f_out);
     f_out = fopen(file_name, "w+b");
    fwrite(buffer, sizeof(double), countelem, f_out);
    fclose(f_out);
    f_out = fopen(file_name, "rb");
    fread(buffer, sizeof(double), countelem, f_out);
    cout << "\nData reading in file before manipulation <<doubledigitfile.bin>>: \n";

    for (size_t i = 0; i < countelem; i++)
    {
        cout << buffer[i] << " ";
    }

}


struct Student
{
     string fio;
    int marks[3];
    double grants;//stependia
    void ShowInfo();
};
void Hard()
{
    /*
Создать бинарный файл, компонентами которого является структура, содержащая следующие поля:
    - фамилия и инициалы студентов;
    - номер группы; 
    - успеваемость (массив из трех дисциплин); 
    - размер стипендии. 
Переписать бинарный файл так, чтобы для студентов, у которых есть хотя бы одна двойка,  размер стипендии
должен быть уменьшен на 20%
    */
    cout << "\Hard task level\n";
    
    Student* masstuds = new Student[3];
    masstuds[0].fio = "Михайл Сергеевич Грибков";
    masstuds[1].fio = "Даниил Вениаминович Чабан";
    masstuds[2].fio = "Ахмед Расим Оглу";
    for (size_t i = 0; i < 3; i++)
    {
        masstuds[i].grants = 1300 + rand() % 601;
        for (size_t q = 0; q < 3; q++)
        {
            masstuds[i].marks[q] = 1 + rand() % 5;
        }
    }

    FILE *f_out, *f_in;
    f_out = fopen("DateBaseStudents", "wb");
    fwrite(masstuds, sizeof(Student), 3, f_out);
    fclose(f_out);
    f_out = fopen("DateBaseStudents", "rb");
    fread(masstuds, sizeof(Student), 3, f_out);
    cout << "\nИнформация о студентах считаная с файла <<DateBaseStudents.bin>> \n";
    for (size_t i = 0; i < 3; i++)
    {
        cout << i + 1 << " " << masstuds[i].fio << " " << masstuds[i].grants << " ";
        for (size_t q = 0; q < 3; q++)
        {
            
            cout << masstuds[i].marks[q]<<" ";
            if (masstuds[i].marks[q] <= 2)
                masstuds[i].grants -= masstuds[i].grants * 0.20;
        }
        cout << endl;
    }
    fclose(f_out);
    f_out = fopen("DateBaseStudents", "w+b");
    cout << "\nВнесенеия изменений в базу данных(студентам имеющим хоть одну 2йку размер степендий уменшить на 20%)\n";
    fwrite(masstuds, sizeof(Student), 3, f_out);
    for (size_t i = 0; i < 3; i++)
    {
        cout << i + 1 << " " << masstuds[i].fio << " " << masstuds[i].grants << " ";
        for (size_t q = 0; q < 3; q++)
        {

            cout << masstuds[i].marks[q] << " ";
            if (masstuds[i].marks[q] == 2)
                masstuds[i].marks[q] -= masstuds[i].marks[q] * 0.20;
        }
        cout << endl;
    }
}
