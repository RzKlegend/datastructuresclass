/*Problem Statement: Digital Library Catalog Management using Bubble Sort
A digital library maintains records of newly added books. Each record contains the following information:
•	Book ID 
•	Number of Available Copies 
Develop a C program using Bubble Sort to perform the following tasks:
1.	Read the details of N books from the user. 
2.	Allow the user to choose the sorting criterion: 
o	Book ID (Ascending Order) 
o	Number of Available Copies (Ascending Order) 
3.	Sort the book records using the Bubble Sort algorithm. 
4.	Display the sorted list of books. 
5.	Count and display the total number of comparisons and swaps performed during the sorting process. 
6.	Display the book having the maximum number of available copies. 
7.	Analyze and display the time complexity of Bubble Sort.
*/

#include <stdio.h>

int main() {
    int id[100], copies[100];
    int n, i, j, choice, temp;
    int comparisons = 0, swaps = 0;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Book ID and Available Copies for book %d: ", i + 1);
        scanf("%d %d", &id[i], &copies[i]);
    }

    printf("\nChoose sorting criterion:\n");
    printf("1. Book ID (Ascending)\n");
    printf("2. Number of Available Copies (Ascending)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            int shouldSwap = 0;

            if (choice == 1) {
                if (id[j] > id[j + 1])
                    shouldSwap = 1;
            } else {
                if (copies[j] > copies[j + 1])
                    shouldSwap = 1;
            }

            if (shouldSwap) {
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;

                temp = copies[j];
                copies[j] = copies[j + 1];
                copies[j + 1] = temp;

                swaps++;
            }
        }
    }

    printf("\nSorted Book Records:\n");
    printf("Book ID\tAvailable Copies\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", id[i], copies[i]);

    printf("\nTotal comparisons: %d", comparisons);
    printf("\nTotal swaps: %d\n", swaps);

    int maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (copies[i] > copies[maxIndex])
            maxIndex = i;
    }
    printf("\nBook with maximum available copies -> Book ID: %d, Copies: %d\n",
           id[maxIndex], copies[maxIndex]);

    printf("\nTime Complexity of Bubble Sort:\n");
    printf("Best Case: O(n)\n");
    printf("Average Case: O(n^2)\n");
    printf("Worst Case: O(n^2)\n");

    return 0;
}
