#include<stdio.h>
char *subject_code[10] = {"NULL","21MAC301","21CSE302","21CSE303","21CSE304","21CSE305","21BFE306",
                            "21KSK207","21AEC308","21IOT309"};
int marks[10];
float percent[10],avg;

void marks_entry(){
    int total=0;
    printf("*******MARKS ENTRY*********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||MAKRS:",subject_code[i]);
        scanf("%d",&marks[i]);
        total +=marks[i];
    }
    avg = total/9;
}

void attendance_entry(){
    int x,y;
    printf("*******ATTENDANCE ENTRY********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||ATTENDANCE(X/Y):",subject_code[i]);
        scanf("%d%d",&x,&y);
        percent[i] = (x/y)*100;
    }
}

void display_marks(){
    printf("*******MARKS CARD*********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||MAKRS:%d||",subject_code[i],marks[i]);
    }
    printf("||TOTAL PERCENTAGE=%f",avg);
}

void display_attendance(){
    int x,y;
    printf("*******ATTENDANCE CARD********\n");
    for(int i=1;i<10;i++){
        printf("||SUBJECT CODE:%s||ATTENDANCE(X/Y):%f",subject_code[i],percent[i]);
    }
}


