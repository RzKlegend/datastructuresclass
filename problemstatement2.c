/*Problem Statement 2: Printer Job Management System
A printer receives multiple print requests from different users. The printer processes these requests in the order in which they are received. Therefore, a Queue is appropriate because it follows the FIFO (First In, First Out) principle.
Each print job contains:
•	Job ID 
•	Document name 
•	Number of pages 
The system should support:
1.	Enqueue – Add a new print job at the rear. 
2.	Dequeue – Process and remove the print job at the front. 
3.	Peek/Front – Display the next print job without removing it. 
4.	Display – Display all pending print jobs. 
5.	isEmpty – Check whether the queue is empty. 
6.	Size – Display the number of pending print jobs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Job {
    int jobID;
    char documentName[100];
    int pages;
    struct Job *next;
};

struct Job *front = NULL;
struct Job *rear = NULL;

void enqueue(int id, char name[], int pages) {
    struct Job *newJob;

    newJob = (struct Job *)malloc(sizeof(struct Job));

    newJob->jobID = id;
    strcpy(newJob->documentName, name);
    newJob->pages = pages;
    newJob->next = NULL;

    if (rear == NULL) {
        front = rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }

    printf("Print job added successfully.\n");
}

void dequeue() {
    struct Job *temp;

    if (front == NULL) {
        printf("No print jobs pending.\n");
        return;
    }

    temp = front;

    printf("Processing Job ID: %d\n", front->jobID);
    printf("Document: %s\n", front->documentName);
    printf("Pages: %d\n", front->pages);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nNext Print Job:\n");
    printf("Job ID: %d\n", front->jobID);
    printf("Document: %s\n", front->documentName);
    printf("Pages: %d\n", front->pages);
}

void display() {
    struct Job *temp;

    if (front == NULL) {
        printf("No pending print jobs.\n");
        return;
    }

    temp = front;

    printf("\nPending Print Jobs:\n");

    while (temp != NULL) {
        printf("Job ID: %d | Document: %s | Pages: %d\n",
               temp->jobID,
               temp->documentName,
               temp->pages);

        temp = temp->next;
    }
}

void isEmpty() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

void size() {
    int count = 0;
    struct Job *temp = front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of pending jobs: %d\n", count);
}

int main() {
    int choice;
    int id, pages;
    char name[100];

    while (1) {
        printf("\n--- PRINTER JOB MANAGEMENT ---\n");
        printf("1. Enqueue Job\n");
        printf("2. Dequeue Job\n");
        printf("3. Peek / Next Job\n");
        printf("4. Display Jobs\n");
        printf("5. isEmpty\n");
        printf("6. Size\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job ID: ");
                scanf("%d", &id);

                printf("Enter Document Name: ");
                scanf(" %[^\n]", name);

                printf("Enter Number of Pages: ");
                scanf("%d", &pages);

                enqueue(id, name, pages);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                isEmpty();
                break;

            case 6:
                size();
                break;

            case 7:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}