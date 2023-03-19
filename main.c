#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "helpers.h"

int main(int argc, char *argv[]) {
    int op;
    char name[30], line[1024];
    do {
        fgets(line, 1024, stdin);
        op = strtol(line, NULL, 10);
        switch (op) {
        case 1:
            printf("Enter letter (A - Z): ");
            fgets(line, 1024, stdin);
            getRow(line);
            break;
        case 2:
            printf("Enter student name: ");
            fgets(name, 30, stdin);
            insertRow(name) ? puts("Success") : puts("Failure");
            break;
        case 3:
            printf("Enter student name: ");
            fgets(line, 30, stdin);
            // TO DO: Search for the given student in the hash table.
            // Hash the name entered and traverse the accompanying
            // Linked List until there is a perfect case insensitive match.
            // Print all about the student when done.
            break;
        case 4:
            // TO DO: Implement code that saves all the students to a file
            // preferable JSON, or CSV. Then provide options to read or 
            // write to students' details.
            break;
        }
    } while(op != 5);
}