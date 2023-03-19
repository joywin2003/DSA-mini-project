#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    int ch;
    do {

        printf("Continue (1/0)?: ")
        scanf("%d", &ch);
    } while(ch);
}