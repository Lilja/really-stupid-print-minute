#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdlib.h>
#include <time.h>

const int minute = 5;
const char * sourceFile = "printMinute.c";
const char * tempSourceFile = "temp";

void read_file_line_by_line(int newMinute) {
    FILE * fp;
    FILE * writeFp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(sourceFile, "r");
    writeFp = fopen(tempSourceFile, "w");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int index = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (index == 6) {
            char buf[5];
            sprintf(buf, "%d", newMinute);
            fputs("const int minute = ", writeFp);
            fputs(buf, writeFp);
            fputs(";\n", writeFp);
        } else {
            fputs(line, writeFp);
        }
        index++;
    }
    fclose(fp);
    fclose(writeFp);
    //rename(tempSourceFile, sourceFile);
}

int main(char* argv) {
    time_t foo = time(NULL);
    struct tm *tm_struct = localtime(&foo);
    int newMinute = tm_struct->tm_min;
    if (minute != newMinute) {
        read_file_line_by_line(newMinute);
        system("gcc printMinute.c");
        exit(1);
    }
    printf("%d\n", minute);
    return 0;
}
