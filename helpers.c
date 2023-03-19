#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"

student *table[26] = {NULL};

int hash(string name) {
    return isalpha(name[0]) ? toupper(name[0]) - 65 : 0;
}

student *makeNode(student *n, string name) {
    student *tmp = malloc(sizeof(student));
    if (!tmp) return NULL;
    strncpy(tmp->name, name, sizeof(tmp->name));
    printf("Enter student USN: ");
    fgets(tmp->usn, 11, stdin);
    printf("Enter student Phone: ");
    fgets(tmp->phone, 11, stdin);
    printf("Enter student GPA (10): ");
    scanf("%lf%*[^\n]", &(tmp->gpa));
    printf("Enter student attendance (%%): ");
    scanf("%lf%*[^\n]", &(tmp->attendance));
    tmp->next = n;
    return tmp;
}

int insertRow(string name) {
    int position = hash(name);
    student *node = makeNode(table[position], name);
    if (!node) return 0;
    table[position] = node;
    return 1;
}
