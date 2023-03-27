#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 20
#define MAX_USN_LEN 15
#define MAX_PHONE_LEN 15
#define SUBJECT_COUNT 10

typedef struct student{
    char name[MAX_NAME_LEN];
    char usn[MAX_USN_LEN];
    char phone[MAX_PHONE_LEN];
    double marks[SUBJECT_COUNT],avg;
    double attendance[SUBJECT_COUNT];
    struct student *next;
}student;

char *subject_code[10] = {"NULL","21MAC301","21CSE302","21CSE303","21CSE304","21CSE305","21BFE306",
                            "21KSK207","21AEC308","21IOT309"};
student *table[26] = {NULL};

student *createStudentNode(char *name);
int hash(const char *name);
int insertStudent(char *name);
student * getStudent(char *name);
void marksEntry(student *name);
void attendanceEntry(student *name);
void DisplayStudent(student *name);



int main(){
    int choice;
    student head;
    char  name[MAX_NAME_LEN];
    printf("==== ENTER YOUR CHOICE ====\n");
    printf("1. Insert student details\n");
    printf("2. Find student details\n");
    printf("3. Enter the student marks\n");
    printf("4. Enter the student attendance\n");
    printf("5. Display student performance card\n");
    printf("6. Exit\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        printf("Enter student name: ");
        scanf("%s",name);
        head = insertStudent(name);
        break;
    case 2:
        printf("Enter student name: ");
        scanf("%s",name);
        head = getStudent(name);
        break;
    case 3:
        printf("Enter student name: ");
        scanf("%s",name);
        head = getStudent(name);
        marksEntry(&head);
        break;
    case 4: 
        printf("Enter student name: ");
        scanf("%s",name);
        head = getStudent(name);
        attendanceEntry(&head);
        break;
    case 5: 
        printf("Enter student name: ");
        scanf("%s",name);
        head = getStudent(name);
        DisplayStudent(&head);
        break;
    case 6:
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}
    
int hash(const char *name) {
    return isalpha(name[0]) ? toupper(name[0]) - 'A' : 0;
}

student *createStudentNode(char *name) {
    student *node = malloc(sizeof(student));
    if (!node) return NULL;
    strncpy(node->name, name, MAX_NAME_LEN);
    printf("Enter student USN: ");
    fgets(node->usn, MAX_USN_LEN, stdin);
    printf("Enter student Phone: ");
    fgets(node->phone, MAX_PHONE_LEN, stdin);
    marksEntry(node);
    attendanceEntry(node);
    node->next = NULL;
    return node;
}

int insertStudent(char *name) {
    int position = hash(name);
    student *node = createStudentNode(name);
    if (!node){
        printf("Failed to insert the student details!!\n");
        return 0;
    }
    if (!table[position]) 
        table[position] = node;
    else {
        student *cursor = table[position];
        while (cursor->next) {
            cursor = cursor->next;
        }
        cursor->next = node;
    }
    printf("Student details inserted successfully!!\n");
    return 1;
}

student *getStudent(char *name) {
    int position = hash(name);
    student *cursor = table[position];
    int count = 0;
    while (cursor) {
        if (strncmp(cursor->name, name, MAX_NAME_LEN) == 0) {
            printf("Student found with name '%s' \n", name);
            return cursor;
            count++;
        }
        cursor = cursor->next;
    }
    if (count == 0) {
        printf("No student found with name '%s'\n", name);
    }
    return 0;
}

void marksEntry(student *name){
    int total=0;
    printf("*******MARKS ENTRY*********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||MAKRS:",subject_code[i]);
        scanf("%lf",&name->marks[i]);
        printf("\n");
        total +=name->marks[i];
    }
    name->avg = total/9.0;
}

void attendanceEntry(student *name){
    double x,y;
    printf("*******ATTENDANCE ENTRY********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||ATTENDANCE(X/Y):",subject_code[i]);
        scanf("%lf%lf",&x,&y);
        printf("\n");
        name->attendance[i] = (x/y)*100.0;
    }
}
void DisplayStudent(student *name){
    int position = hash(name->name);
  //  int position = hash(name);
    student *cursor = table[position];
    printf("======================================\n");
    printf("==        STUDENT DETAILS           ==\n");
    printf("======================================\n");
    printf("==  STUDENT NAME:   %-15s  ==\n",cursor->name);
    printf("==  STUDENT USN :   %-15s  ==\n",cursor->usn);
    printf("==  STUDENT PHNO:   %-15s  ==\n",cursor->phone);
    printf("======================================\n");
    printf("=====================================\n");
    printf("==       ATTENDANCE DETAILS        ==\n");
    printf("======================================\n");
    for(int i=1;i<SUBJECT_COUNT;i++){
        printf("SUBJECT CODE: %s||ATTENDANCE: %lf%%\n",subject_code[i],name->attendance[i]);
    }
    printf("======================================\n");
    printf("==         MARKS DETAILS            ==\n");
    printf("======================================\n");
    for(int i=1;i<SUBJECT_COUNT;i++){
        printf("||SUBJECT CODE:%s||MAKRS:%lf||\n",subject_code[i],name->marks[i]);
    }
    printf("==   TOTAL PERCENTAGE=%lf%%         ==\n",name->avg);
    
}



