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

struct PrintJob {
    int job_id;
    char doc_name[100];
    int pages;
    struct PrintJob* next;
};

struct PrintJob *front = NULL, *rear = NULL;
int queue_size = 0;

void enqueue(int id, char* name, int pages) {
    struct PrintJob* newJob = (struct PrintJob*)malloc(sizeof(struct PrintJob));
    newJob->job_id = id;
    strcpy(newJob->doc_name, name);
    newJob->pages = pages;
    newJob->next = NULL;
    
    if (rear == NULL) {
        front = rear = newJob;
    } else {
        rear->next = newJob;
        rear = newJob;
    }
    queue_size++;
    printf("Print job added: %s\n", name);
}

void dequeue() {
    if (front == NULL) {
        printf("No pending print jobs.\n");
        return;
    }
    struct PrintJob* temp = front;
    printf("Processing job: %s (%d pages)\n", temp->doc_name, temp->pages);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    queue_size--;
}

void peek() {
    if (front == NULL) {
        printf("No pending print jobs.\n");
        return;
    }
    printf("Next job: %s (ID: %d)\n", front->doc_name, front->job_id);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct PrintJob* temp = front;
    printf("Pending Print Jobs:\n");
    while (temp != NULL) {
        printf("[ID: %d, Doc: %s, Pages: %d] -> ", temp->job_id, temp->doc_name, temp->pages);
        temp = temp->next;
    }
    printf("NULL\n");
}

void isEmpty() {
    if (front == NULL) printf("Queue is Empty: Yes\n");
    else printf("Queue is Empty: No\n");
}

void getSize() {
    printf("Pending jobs count: %d\n", queue_size);
}

int main() {
    enqueue(101, "Assignment.pdf", 5);
    enqueue(102, "Resume.docx", 2);
    enqueue(103, "Notes.txt", 15);
    display();
    peek();
    getSize();
    dequeue();
    display();
    isEmpty();
    return 0;
}