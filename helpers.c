#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "types.h"

student *table[26] = {NULL};
char line[1024];

int hash(string name) {
    return isalpha(name[0]) ? toupper(name[0]) - 'A' : 0;
}

student *makeNode(student *n, string name) {
    student *tmp = malloc(sizeof(student));
    if (!tmp) return NULL;
    strncpy(tmp->name, name, sizeof(tmp->name));
    printf("Enter student USN: ");
    fgets(tmp->usn, 15, stdin);
    printf("Enter student Phone: ");
    fgets(tmp->phone, 15, stdin);
    printf("Enter student GPA (xx/10): ");
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

void getRow(string line) {
    int position = hash(line);
    student *cursor = table[position];
    while(cursor) {
        printf("%s", cursor->name);
        cursor = cursor->next;
    }
}
void printRow(string name){
    int position = hash(name);
    student *cursor = table[position];
    printf("======================================\n");
    printf("==        STUDENT DETAILS           ==\n");
    printf("======================================\n");
    printf("==  STUDENT NAME:   %s  ==\n",cursor->name);
    printf("==  STUDENT USN :   %s  ==\n",cursor->usn);
    printf("==  STUDENT PHNO:   %s  ==\n",cursor->phone);
    printf("======================================\n");
    
}