#ifndef TYPES_H
#define TYPES_H

typedef char *string ;

typedef struct student {
    char name[30], usn[15], phone[15];
    double gpa, attendance;
    struct student *next;
}student;

#endif