#ifndef STRUCTUERS_H
#define STRUCTUERS_H

typedef struct student {
    char name[30], usn[11], phone[11];
    double gpa, attendance;
    struct student *next;
}student;

student *makeNode(student *n);

#endif