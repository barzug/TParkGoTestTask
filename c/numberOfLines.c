#include <stdio.h>
#include "numberOfLines.h"

const int search_number_of_lines(const char *file_name) {
    int number_of_lines = 0;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        return -1;
    }

    while (!feof(file)) {
        if (fgetc(file) == '\n') {
            number_of_lines++;
        }
    }

    fclose(file);
    return number_of_lines;
}
