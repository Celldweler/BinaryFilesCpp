#include <sys/types.h>             /* включение необходимых заголовочных файлов */ 
#include <fcntl.h> 
#include <stdlib.h> 
#include<stdio.h>
#include <sys\stat.h>
#include <io.h>
#pragma warning(disable : 4996)
#define BUF_SIZE 4096              /* используется буфер размером  4096 байт */ 
#define OUTPUT_MODE 0700  /* биты защиты для выходного файла */ 

int main(int argc, char *argv[]) 
{
      argc = 3;
    


    int in_fd, out_fd, rd_count, wt_count;  
    char buffer[BUF_SIZE];
       /* если argc не равен 3, возникает  синтаксическая ошибка */

/* Открытие входного и создание выходного файла */    
in_fd = open("first.txt", O_RDONLY| O_CREAT | O_WRONLY | O_TEXT );  
write(in_fd, "sup 2ch", 8);
/* открытие исходного файла */
if (in_fd < 0) 
   // exit(2);                 /* если он не открывается, выйти */ 
out_fd = creat("second.txt", OUTPUT_MODE);   /* создание файла-приемника */
if (out_fd < 0)
    exit(3);                /* если он не создается, выйти */   
/* Цикл копирования */  
while (true) {
    rd_count = read(in_fd, buffer, BUF_SIZE); /* чтение блока данных */  
    if (rd_count <= 0) 
        break;      /* в конце файла или при ошибке – выйти из цикла */   
    wt_count = write(out_fd, buffer, rd_count); /* запись данных */
        if (wt_count <= 0)
            exit(4); /* при wt_count <= 0 возникает ошибка */
}
/* Закрытие файлов */   
close(in_fd);    
close(out_fd);
if (rd_count == 0) /* при последнем чтении ошибки не возникло */  
   exit(0);   
else
    exit(5);                  /* ошибка при последнем чтении */
}