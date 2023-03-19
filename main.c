#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    int op;
    char name[30], line[1024];
    do {
        fgets(line, 1024, stdin);
        op = strtol(line, NULL, 10);
        switch (op) {
        case 1:
            printf("Enter letter (A - Z): ");
            fgets(line, 1024, stdin);
            getRow(line);
            break;
        case 2:
            printf("Enter student name: ");
            fgets(name, 30, stdin);
            insertRow(name) ? puts("Success") : puts("Failure");
            break;
        }
    } while(op != 5);
}