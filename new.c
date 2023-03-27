#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef char *string ;

typedef struct student {
    char name[30], usn[15], phone[15];
    double gpa, attendance;
    struct student *next;
}student;


student *table[26] = {NULL};

int hash(string name) {
    return isupper(name[0]) ? name[0] - 'A' : 0;
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

void printStudent(string name) {
    int position = hash(name);
    student *cursor = table[position];
    while (cursor != NULL) {
        if (strncasecmp(name, cursor->name, 5) == 0) break;
        cursor = cursor->next;
    }
    if (cursor == NULL) {
        puts("Student not found.");
        return;
    }
    printf("======================================\n");
    printf("==        STUDENT DETAILS           ==\n");
    printf("======================================\n");
    printf("==  STUDENT NAME:  %s", cursor->name);
    printf("==  STUDENT USN :  %s", cursor->usn);
    printf("==  STUDENT PHNO:  %s", cursor->phone);
    printf("==  STUDENT GPA :  %f\n", cursor->gpa);
    printf("==  STUDENT ATTN:  %f\n", cursor->attendance);
    printf("======================================\n");
}

int main() {
    char name[30];
    int choice;
    printf("1.Insert Student\n2.View Students\n3.Find Student\nPress 4 to quit.\n");
    do {
        printf("Enter the option");
        scanf("%c",&choice);
        switch (choice) {
        case 1:
            printf("Enter student name: ");
            fgets(name, 30, stdin);
            insertRow(name) ? puts("Success") : puts("Failure");
            break;
        case 2:
            printf("Enter letter (A - Z): ");
            fgets(choice, 1024, stdin);
            getRow(choice);
            break;
        case 3:
            printf("Enter student name: ");
            fgets(choice, 30, stdin);
            printStudent(choice);
            break;
        }
    } while(choice != 4);
}