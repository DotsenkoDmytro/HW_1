#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char surname[20];
    int age;
} Student;

int main() {
    int n = 0;
    Student *students = NULL;
    char choice;

    do {
        printf("Do you want to add a student? \n"
               "Please press Y for yes, N for no\n");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            students = realloc(students, (n + 1) * sizeof(Student));

            printf("Enter name: ");
            scanf("%s", students[n].name);

            printf("Enter surname: ");
            scanf("%s", students[n].surname);

            printf("Enter age: ");
            scanf("%d", &students[n].age);
            printf("\n");

            n++;
        }

        if (choice == 'n' || choice == 'N') {
            printf("List of students:\n");
            for (int i = 0; i < n; i++) {
                printf("Student #%d\n", i + 1);
                printf("Name: %s\n", students[i].name);
                printf("Surname: %s\n", students[i].surname);
                printf("Age: %d\n\n", students[i].age);
            }
        }
    } while (choice != 'n' && choice != 'N');

    free(students);
    return 0;
}
