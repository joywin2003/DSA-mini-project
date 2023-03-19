#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <char.h>
#include "types.h"

student *table[26] = {NULL};

int hash(string name) {
    return toupper(name[i]) - 65;
}

student *makeNode(student *n, string name) {
    student *tmp = malloc(sizeof(student));
    if (!tmp) exit(1);
    strncpy(tmp->name, name, sizeof(tmp->name));
    printf("Enter student USN: ")
    fgets(tmp->usn, 10, stdin);
    printf("Enter student Phone: ")
    fgets(tmp->phone, 10, stdin);
    printf("Enter student GPA (10): ")
    scanf("%f", &(tmp->gpa));
    printf("Enter student attendance (%): ")
    scanf("%f", &(tmp->attendance));
    tmp->next = n;
    return tmp;
}

