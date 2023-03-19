#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    int ch, op;
    char name[30], line[1024];
    do {
        fgets(line, 1024, stdin);
        op = strtol(line, NULL, 10);
        switch (op) {
        case 2:
            printf("Enter student name: ");
            fgets(name, 30, stdin);
            insertRow(name) ? puts("Success") : puts("Failure");
        }
        printf("Continue (1/0)?: ");
        scanf("%d", &ch);
    } while(ch);
}