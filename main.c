#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu();

void displayCourses();

void displayStudents();

void addNewCourse();

void addNewStudent();

int option = 0;

int main() {
    while (option != 5) {

        menu();
        printf("Please enter one of the following options: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayStudents();
                break;
            case 2:
                displayCourses();
                break;
            case 3:
                addNewStudent();
                break;
            case 4:
                addNewCourse();
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                break;
        }

    }
    return 0;
}

void menu() {
    printf("1) Display current students\n");
    printf("2) Display current courses\n");
    printf("3) Add a new student\n");
    printf("4) Add a new course\n");
    printf("5) Exit\n");
}


void displayStudents() {

    FILE *file;
    int c;
    file = fopen("Students.txt", "r");

    if (NULL == file) {//check if the file open
        printf("ERROR could not open the file");
        exit(EXIT_FAILURE);
    } else {
        while (1) {
            c = fgetc(file);
            if (feof(file)) {
                break;
            }
            printf("%c", c);
        }
        printf("\n");
    }
    fclose(file);

}

void displayCourses() {

    FILE *file;
    int c;
    file = fopen("Courses.txt", "r");

    if (NULL == file) {//check if the file open
        printf("ERROR could not open the file");
        exit(EXIT_FAILURE);
    } else {
        while (1) {
            c = fgetc(file);
            if (feof(file)) {
                break;
            }
            printf("%c", c);
        }
        printf("\n\n");
    }
    fclose(file);

}

void addNewCourse() {

    char courseName[255];
    char courseCode[255];

    printf("Enter a Course Code: ");
    scanf("%s", courseCode);

    while((getchar()) != '\n');

    printf("Enter a Course Name: ");
    scanf("%[^\n]s", courseName);

    FILE *outputFile;
    outputFile = fopen("Courses.txt", "a");

    if (NULL == outputFile) {//check if the file open
        printf("ERROR could not create output file");
        exit(EXIT_FAILURE);
    } else {
        fprintf(outputFile, "\n%s %s", courseCode, courseName);
    }
    fclose(outputFile);

}

void addNewStudent() {

    char studentFirstName[255];
    char studentLastName[255];
    int studentNumber;

    printf("Enter a Student FirstName: ");
    scanf("%s", studentFirstName);

    printf("Enter a Student LastName: ");
    scanf("%s", studentLastName);

    printf("Enter a Student Number: ");
    scanf("%d", &studentNumber);

    FILE *outputFile;
    outputFile = fopen("Students.txt", "a");

    if (NULL == outputFile) {//check if the file open
        printf("ERROR could not create output file");
        exit(EXIT_FAILURE);
    } else {
        fprintf(outputFile, "\n%s %s %d", studentFirstName,studentLastName, studentNumber);
    }
    fclose(outputFile);

}
