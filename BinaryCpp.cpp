#include "FunctionsUsed.h"

//                  Variant - 2 

/*
Hard level
В первом файле хранится k матриц размерности m x n, во втором l матриц размерности m x n. Убрать из файла, в котором больше матриц, лишние матрицы
в третий файл. Вывести на экран содержимое первого файла; второго файла; третьего файла.
*/
/*
FillNewFileUnwantedMatrix(FileName1, FileName2, , n, m)
*/

int main(void)
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
 //    BaseLevelTask();
  //   MidleTaskLevel();

    printf("\nHard task level\n");

    unsigned k, l, n, m;
    char FileName[20],
         FileNameSecond[20],
         FileNameThird[20];

    while (TRUE) 
    { 
        printf("\nEnter k and l number of matrixs in first and second file $ "); 
        scanf("%u %u", &k, &l);

        printf("\nEnter n x m dimentions of matrixs:\n"); 
        scanf("%u%u", &n, &m);
        if ((k > 0) && (n > 0) && (m > 0) && ( l > 0 ))
            break;
        printf("\nNumber is incorrect!!! Try ” “again!!!\n");
    }

    printf("\nEnter the name of first file: "); 
        scanf("%s", FileName);
        
        printf("\nEnter the name of second file: ");
        scanf("%s", FileNameSecond);

        printf("\nEnter the name of third file: ");
        scanf("%s", FileNameThird);


    system("cls");

   int count_matrix_in_file1 =  BlockWriteFile(FileName, "wb", k, n, m);

   int count_matrix_in_file2 = BlockWriteFile(FileNameSecond, "wb",l, n, m);

   int max_count_mat = count_matrix_in_file1 > count_matrix_in_file2 ? count_matrix_in_file1 : count_matrix_in_file2;

   std:: cout << "\nMax count matrix " << max_count_mat << std::endl;
   std::cout << "\nСостояние файлов до внесенных изменений\n";

    printf("\nThe contents of first file <<%s>>:\n", FileName);
    DisplayFile(FileName, "rb", n, m);

    printf("\nThe contents of second file <<%s>>:\n", FileNameSecond);
    DisplayFile(FileNameSecond, "rb", n, m);
    printf("\nThe  third file <<%s>>: is empty\n", FileNameThird);

    FillNewFileUnwantedMatrix(FileNameSecond, FileNameThird, k, count_matrix_in_file2- count_matrix_in_file1, n, m);

   std::cout << "\nСостояние файлов после внесенных изменений\n";
    printf("\nФайл <<%s>>: остался без изменений\n", FileName);
    DisplayFile(FileName, "rb", n, m);
    
    DeleteUnwantedMatrixOfFile(FileNameSecond, k, n, m);
    printf("\nThe contents of second file <<%s>>:\n", FileNameSecond);
    DisplayFile(FileNameSecond, "rb", n, m);
    
    printf("\nThe new contents of third file <<%s>>:\n", FileNameThird);
    DisplayFile(FileNameThird, "rb", n, m);
    printf("\n Press any key to exit...");  
        getchar(); 
        return 0; 
}

int* InitMatrix(unsigned l, unsigned n, unsigned m)
{
    unsigned i;
    int* Pointer = (int*)malloc(n * m * sizeof(int));
    for (i = 0; i < n * m; i++) { Pointer[i] = l + 1; }  
    return Pointer;
}

int* FreeMemory(unsigned n, unsigned m)
{ 
    int* Pointer = (int*)malloc(n * m * sizeof(int));
    return Pointer;
}

int BlockWriteFile(char* FileName, const char* Mode, unsigned count_matrix, unsigned row, unsigned col)
{
    int BufSize = sizeof(int) * row * col,
        counter_matrix = 0;
    int* Pointer = (int*)malloc(BufSize);
    unsigned i; 
    FILE* FilePointer = fopen(FileName, Mode);
   if (FilePointer == NULL) 
    { 
        printf("Can't open file to write.");
        getchar();
        abort();
    }

    for (i = 0; i < count_matrix; i++) 
    {
        Pointer = InitMatrix(i, row, col);
        counter_matrix++;
        fwrite(Pointer, BufSize, 1, FilePointer); 
        
    }
    fclose(FilePointer);
    free(Pointer);
    return counter_matrix;
}
void DisplayFile(const char* String, const char* Mode, unsigned n, unsigned m)
{
    int BufSize = sizeof(int) * n * m, Sector = 0; 
    int* Pointer = FreeMemory(n, m);
    FILE* FilePointer = fopen(String, Mode);
    if (FilePointer == NULL) { printf("\nCan't open file to read."); getch(); abort(); }
       
        while (fread(Pointer, BufSize, 1, FilePointer) != 0)
        { 
            printf("\n %d's  matrix \n", (Sector + 1));
            DisplayMatrix(Pointer, n, m);
            Sector++; 
        }
    fclose(FilePointer); 
    free(Pointer);
}

void DisplayMatrix(int* Pointer, unsigned n, unsigned m)
{
    unsigned i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%4d", *(Pointer + i * m + j));
        }
        printf("\n");
    }
}

void DeleteUnwantedMatrixOfFile(char* String, unsigned count_wr_mat, unsigned n, unsigned m)
{
    int* Pointer = (int*)malloc(sizeof(int)*m*n* count_wr_mat);
    int  BufSize = sizeof(int) * n * m* count_wr_mat;
        long lastmatrixforw =  (long)(sizeof(int) * n * m * count_wr_mat);
    int* Simple = nullptr,
         Sum = 0;

    FILE* FilePointer = fopen(String, "rb");
    FILE* TempFile = fopen("TempFile","wb");
    if (FilePointer == NULL)
    {
        printf("Can't open file to read.");
        getchar();
        abort();
    }

    long set_possition = 0; 
       int count_rd_mat = 1;
  
        fread(Pointer, BufSize, 1, FilePointer);
          
            fwrite(Pointer, BufSize, 1, TempFile);
        
       rewind(FilePointer);

    fclose(FilePointer);
    fclose(TempFile);
  
   FilePointer = fopen(String, "w+b");
    
   TempFile = fopen("TempFile", "rb");
    
   fread(Pointer, BufSize, 1, TempFile);
   
        fwrite(Pointer, BufSize, 1, FilePointer);
    
    fclose(FilePointer);
    fclose(TempFile);

    free(Pointer);
    free(Simple);
}

void FillNewFileUnwantedMatrix(char* FileName1, char* FileName2, unsigned set_pos, unsigned count_matrix, unsigned row, unsigned col)
{
    int BufSize = sizeof(int) * row * col,
        counter_matrix = 0;
    int* Pointer = (int*)malloc(BufSize);
    unsigned i;
    FILE* FilePointer1 = fopen(FileName1, "rb");
    FILE* FilePointer2 = fopen(FileName2, "wb");

    if (FilePointer1 == NULL)
    {
        printf("Can't open file to write.");
        getchar();
        abort();
    }


    long set_possition = sizeof(int) * row * col * set_pos;

    for (i = 0; i < count_matrix; i++)
    {
        fseek(FilePointer1, set_possition, SEEK_SET);

        fread(Pointer, BufSize, 1, FilePointer1);
        counter_matrix++;
        fwrite(Pointer, BufSize, 1, FilePointer2);
        set_possition += static_cast<long>(sizeof(int) * row * col);
    }
    fclose(FilePointer1);
    fclose(FilePointer2);

    free(Pointer);
}

int CheckCountOfMatrix()
{
    return 1;
}







