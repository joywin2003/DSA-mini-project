#ifndef TYPES_H
#define TYPES_H

typedef char *string ;

typedef struct student {
    string name[30], usn[11], phone[11];
    double gpa, attendance;
    struct student *next;
}student;

#endif