// Написать программу на любом языке, которая считает количество строк в заданном файле.
// Имя файла задается в командной строке. Считать, что строки разделяются `\n`.
// Кол-во строк вывести в stdout. Результирующая программа будет аналогична вызову `wc -l /path/to/file`.
// Исходный код выложить на github и прислать ссылку.

#include <stdio.h>
#include <stdlib.h>
#include "numberOfLines.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Enter the file path!\n");
        return EXIT_FAILURE;
    }

    const char *file_path = argv[1];

    int number_of_lines = search_number_of_lines(file_path);

    if (number_of_lines == -1) {
        printf("No such file or directory!\n");
        return EXIT_FAILURE;
    }

    printf("%d %s", number_of_lines, file_path);
    return EXIT_SUCCESS;
}


