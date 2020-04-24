#include <sys/types.h>      /* включение необходимых заголовочных файлов */ 
#include <fcntl.h> 
#include <sys\stat.h>
#include <io.h>
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

void Base();
void Midle();
void Hard();

int main(int argc, char* argv[])
{
    srand(time(0));
    setlocale(0, "");
     SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
      Base();
    // Midle();
     //Hard();
}
struct Item
{
    string       name_of_product;
     int count_items;
     int unit_price;
};
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
    string mas_name_of_product[] = { "Laptops", "BP", "Kylers", "Procesors", 
                    "Matherboard", "RAM", "HDD","SSD" };
    int count_item = 8;//mas_name_of_product.length();
    Item* item = new Item[count_item];

    char path[] = "itembase";
    cout << "\nDate loat to file <<itembase.bin>>: \n";
    for (size_t i = 0; i < count_item; i++)
    {
        cout << "\t" << (item[i].name_of_product = mas_name_of_product[i]) << "\t";
        cout << (item[i].count_items = 10 + rand() % 100) << "\t";
        cout<<( item[i].unit_price = ( (2000 + rand() % 1000) * item[i].count_items) ) <<endl;
    }
    FILE* f_out, * f_in;
    f_out = fopen(path, "wb");
    fwrite(item, sizeof(Item), count_item, f_out);
    fclose(f_out);
    
    delete[] item;
    item = nullptr;
    Item* buffer = new Item[count_item];
    
    int   unit_cost = 0,  //Oбщая стоимость товара
          unit_count_item = 0;
    float average_price = 0.0;// средняя цена

    f_in = fopen(path, "rb");
    fread(buffer, sizeof(Item), count_item, f_in);
    fclose(f_in);
    for (size_t i = 0; i < count_item; i++)
    {
        unit_cost += buffer[i].unit_price;
        unit_count_item += buffer[i].count_items;
    }
    f_out = fopen("newworkfile", "wb");
    average_price = (float)unit_cost / (float)unit_count_item;
    fwrite(&unit_cost, sizeof(int), 1, f_out);
    fwrite(&average_price, sizeof(float), 1, f_out);
    fclose(f_out);
    cout << "\nUnit cost all items "<< unit_cost<<
        "\naverage price: " << average_price;
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
    double* buffer = new double[countelem];
    for (size_t i = 0; i < countelem; i++)
    {
        buffer[i] = -10 - ((rand() % 100) / 100.0);
    }

    fwrite(buffer, sizeof(double), countelem, f_out);
    fclose(f_out);
    cout << "\nData reading in file <<doubledigitfile.bin>>: \n";
    f_out = fopen(file_name, "rb");
    fread(buffer, sizeof(double), countelem, f_out);
    for (size_t i = 0; i < countelem; i++)
    {
        cout << buffer[i] << " ";
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

    FILE* f_out, * f_in;
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

            cout << masstuds[i].marks[q] << " ";
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
