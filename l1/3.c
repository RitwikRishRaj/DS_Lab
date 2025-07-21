#include <stdio.h>
#include <stdlib.h>

struct employee {
    int ID;
    char name[50];
    char designation[50];
    float basicsalary;
    float HRA;
    float DA;
};

int main() {
    int n;
    printf("Number of employees: ");
    scanf("%d", &n);

    struct employee *emp = (struct employee *)malloc(n * sizeof(struct employee));
    if (emp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].ID);

        printf("Enter name (First name): ");
        scanf("%s", emp[i].name);

        printf("Enter designation: ");
        scanf("%s", emp[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basicsalary);

        printf("HRA: ");
        scanf("%f", &emp[i].HRA);

        printf("DA: ");
        scanf("%f", &emp[i].DA);
    }

    
    for (int i = 0; i < n; i++) {
        float gross_salary = emp[i].basicsalary + emp[i].HRA * 0.2 + emp[i].DA * 0.5;

        printf("\nEmployee %d:\n", i + 1);
        printf("ID: %d\n", emp[i].ID);
        printf("First Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Basic Salary: %.2f\n", emp[i].basicsalary);
        printf("HRA: %.2f\n", emp[i].HRA);
        printf("DA: %.2f\n", emp[i].DA);
        printf("Gross Salary: %.2f\n", gross_salary);
    }

    free(emp);

    return 0;
}