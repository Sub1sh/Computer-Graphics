#include <stdio.h>

struct Student {
    char name[50];
    int roll_number;
    float marks[5];   // Array to store marks for 5 subjects
    float total;
    float percentage;
};

int main() {
    int i, j;
    struct Student students[5];
    int num_students = 5;   // Number of students

    // Input student details
    for (i = 0; i < num_students; i++) {
        printf("Enter details for student %d:\n", i + 1);

        printf("Enter name: ");
        scanf(" %[^\n]s", students[i].name);  // Input for name

        printf("Enter roll number: ");
        scanf("%d", &students[i].roll_number);

        students[i].total = 0;  // Initialize total to 0

        // Input marks for 5 subjects
        for (j = 0; j < 5; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];  // Add marks to total
        }

        // Calculate percentage
        students[i].percentage = students[i].total / 5;
        printf("\n");
    }

    // Display student details in tabular form
    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "Roll No", "Total", "Percentage");
    printf("-------------------------------------------------------------\n");

    for (i = 0; i < num_students; i++) {
        printf("%-20s %-10d %-10.2f %-10.2f\n", students[i].name, students[i].roll_number, students[i].total, students[i].percentage);
    }

    return 0;
}
