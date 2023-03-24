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
char line[1024];
char *filename = "students.bin";

int hash(const char *name) {
    return isalpha(name[0]) ? toupper(name[0]) - 'A' : 0;
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

void marksDisplay(student *name){
    printf("*******MARKS CARD*********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||MAKRS:%lf||\n",subject_code[i],name->marks[i]);
    }
    printf("||TOTAL PERCENTAGE=%lf%%",name->avg);
}

void attendanceDisplay(student *name){ 
    printf("*******ATTENDANCE CARD********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||ATTENDANCE(X/Y):%lf%%\n",subject_code[i],name->attendance[i]);
    }
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
    student *node = makeNode(table[position], name);
    if (!node){
        printf("Failed to insert the student details\n");
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
    return 1;
}

void getStudent(char *name) {
    int position = hash(name);
    student *cursor = table[position];
    int count = 0;
    while (cursor) {
        if (strncmp(cursor->name, name, MAX_NAME_LEN) == 0) {
            printf("Student found with name '%s' \n", name);
            DisplayStudent(cursor);
            count++;
        }
        cursor = cursor->next;
    }
    if (count == 0) {
        printf("No student found with name '%s'\n", name);
    }
}
void DisplayStudent(student *name){
    int position = hash(name);
    student *cursor = table[position];
    printf("======================================\n");
    printf("==        STUDENT DETAILS           ==\n");
    printf("======================================\n");
    printf("==  STUDENT NAME:   %-15s  ==\n",cursor->name);
    printf("==  STUDENT USN :   %-15s  ==\n",cursor->usn);
    printf("==  STUDENT PHNO:   %-15s  ==\n",cursor->phone);
    printf("======================================\n");
    
}
void saveStudentsToFile() {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    for (int i = 0; i < 26; i++) {
        student *cursor = table[i];
        while (cursor) {
            fwrite(cursor, sizeof(student), 1, file);
            cursor = cursor->next;
        }
    }
    fclose(file);
}
void loadStudentsFromFile() {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    student tmp;
    while (fread(&tmp, sizeof(student), 1, file) == 1) {
        insertStudent(tmp.name);
        int position = hash(tmp.name);
        student *cursor = table[position];
        while (cursor->next) {
            cursor = cursor->next;
        }
        *cursor = tmp;
    }
    fclose(file);
}

void main(){
    int choice;
    char  name[MAX_NAME_LEN];
    printf("==== ENTER YOUR CHOICE ====\n");
    printf("1. Insert student details\n");
    printf("2. Find student details\n");
    printf("3. Display student marks card\n");
    printf("4. Display student attendance\n");
    printf("5. Save student details to file\n");
    printf("6. Load student details from file\n");
    printf("7. Exit\n");
    scanf("%d",&choice);
    switch (choice){
    case 1:
        printf("Enter student name: ");
        scanf("%20s",&name);
        createStudentNode(name);
        insertStudent(name);
        break;
    case 2:
        printf("Enter student name: ");
        scanf("%20s",&name);
        getStudent(name);
        break;
    case 3:
        printf("Enter student name: ");
        
        break;

    default:
        break;
    }
}
    

