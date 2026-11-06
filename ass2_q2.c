/*Problem Statement
A company maintains payroll records of its employees. Each employee record contains the following information:
•	Employee ID 
•	Employee Name 
•	Monthly Salary 
Develop a C program using Insertion Sort to perform the following operations:
1.	Read the details of N employees. 
2.	Allow the user to choose the sorting criterion: 
o	Employee ID (Ascending Order) 
o	Monthly Salary (Ascending Order) 
3.	Sort the employee records using the Insertion Sort algorithm. 
4.	Display the sorted list of employee records. 
5.	Count and display the total number of comparisons and shifting operations performed during the sorting process. 
6.	Display the employee with the highest salary and the employee with the lowest salary. 
7.	Analyze and display the best-case, average-case, and worst-case time complexity of Insertion Sort.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int id[100];
    char name[100][50];
    float salary[100];
    int n, i, j, choice;
    int keyId;
    char keyName[50];
    float keySalary;
    int comparisons = 0, shifts = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter ID, Name and Salary for employee %d: ", i + 1);
        scanf("%d %s %f", &id[i], name[i], &salary[i]);
    }

    printf("\nChoose sorting criterion:\n");
    printf("1. Employee ID (Ascending)\n");
    printf("2. Monthly Salary (Ascending)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 1; i < n; i++) {
        keyId = id[i];
        strcpy(keyName, name[i]);
        keySalary = salary[i];

        j = i - 1;
        while (j >= 0) {
            comparisons++;
            int shouldShift = 0;

            if (choice == 1) {
                if (id[j] > keyId)
                    shouldShift = 1;
            } else {
                if (salary[j] > keySalary)
                    shouldShift = 1;
            }

            if (!shouldShift)
                break;

            id[j + 1] = id[j];
            strcpy(name[j + 1], name[j]);
            salary[j + 1] = salary[j];
            shifts++;
            j--;
        }

        id[j + 1] = keyId;
        strcpy(name[j + 1], keyName);
        salary[j + 1] = keySalary;
    }

    printf("\nSorted Employee Records:\n");
    printf("ID\tName\t\tSalary\n");
    for (i = 0; i < n; i++)
        printf("%d\t%-10s\t%.2f\n", id[i], name[i], salary[i]);

    printf("\nTotal comparisons: %d", comparisons);
    printf("\nTotal shifts: %d\n", shifts);

    int maxIndex = 0, minIndex = 0;
    for (i = 1; i < n; i++) {
        if (salary[i] > salary[maxIndex])
            maxIndex = i;
        if (salary[i] < salary[minIndex])
            minIndex = i;
    }
    printf("\nHighest Salary ID: %d, Name: %s, Salary: %.2f\n",
           id[maxIndex], name[maxIndex], salary[maxIndex]);
    printf("Lowest Salary ID: %d, Name: %s, Salary: %.2f\n",
           id[minIndex], name[minIndex], salary[minIndex]);

    printf("\nTime Complexity of Insertion Sort:\n");
    printf("Best Case: O(n)\n");
    printf("Average Case: O(n^2)\n");
    printf("Worst Case: O(n^2)\n");

    return 0;
}
