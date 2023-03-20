#ifndef TYPES_H
#define TYPES_H
#define MAX_NAME_LEN 20
#define MAX_USN_LEN 15
#define MAX_PHONE_LEN 15

typedef char *string ;

typedef struct student {
    char name[MAX_NAME_LEN], usn[MAX_USN_LEN], phone[MAX_PHONE_LEN];
    double gpa, attendance;
    struct student *next;
}student;

#endif