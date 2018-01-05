#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdlib.h>
#include <time.h>

const int minute = 55;
const char * sourceFile = "print_minute.c";
const char * tempSourceFile = "temp";
const char * command = "make -s build";

void read_file_line_by_line(int newMinute) {
    FILE * fp;
    FILE * writeFp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(sourceFile, "r");
    writeFp = fopen(tempSourceFile, "w");
    if (fp == NULL)
        exit(2);

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
    if (line)
        free(line);
    fclose(fp);
    fclose(writeFp);
    rename(tempSourceFile, sourceFile);
}

int main(int argc, char * argv[]) {
    time_t foo = time(NULL);
    struct tm *tm_struct = localtime(&foo);
    int newMinute = tm_struct->tm_min;
    if (minute != newMinute) {
        read_file_line_by_line(newMinute);
        system(command);
        return 1;
    }
    printf("%d\n", minute);
    return 0;
}
