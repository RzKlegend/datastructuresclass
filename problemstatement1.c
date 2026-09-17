/*Problem Statement 1: Browser Back Navigation Using Stack
A web browser maintains a history of the web pages visited by a user. Since the user normally wants to return to the most recently visited page first, the browser can use a Stack data structure based on the LIFO (Last In, First Out) principle. In this case study, implement a Stack using a Singly Linked List to manage the browser's page history. Each node in the linked list should store information about a visited webpage, such as:
•	Page ID 
•	Page name/URL 
•	Pointer to the next node 
The system should provide the following operations:
1.	Push – Add a newly visited webpage to the top of the stack. 
2.	Pop – Remove the most recently visited webpage when the user clicks the Back button. 
3.	Peek/Top – Display the currently active/top webpage without removing it. 
4.	Display – Display all webpages currently stored in the browser history. 
5.	isEmpty – Check whether the browser history stack is empty. 
6.	Size – Display the total number of webpages currently stored in the stack.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Page {
    int pageID;
    char pageName[100];
    struct Page *next;
};

struct Page *top = NULL;

void push(int id, char name[]) {
    struct Page *newPage;

    newPage = (struct Page *)malloc(sizeof(struct Page));

    newPage->pageID = id;
    strcpy(newPage->pageName, name);

    newPage->next = top;
    top = newPage;

    printf("Page added to browser history.\n");
}

void pop() {
    struct Page *temp;

    if (top == NULL) {
        printf("Browser history is empty.\n");
        return;
    }

    temp = top;

    printf("Going back from: %s\n", top->pageName);

    top = top->next;

    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Browser history is empty.\n");
    } else {
        printf("Current Page:\n");
        printf("Page ID: %d\n", top->pageID);
        printf("Page Name: %s\n", top->pageName);
    }
}

void display() {
    struct Page *temp;

    if (top == NULL) {
        printf("Browser history is empty.\n");
        return;
    }

    temp = top;

    printf("\nBrowser History:\n");

    while (temp != NULL) {
        printf("Page ID: %d | Page: %s\n",
               temp->pageID, temp->pageName);

        temp = temp->next;
    }
}

void isEmpty() {
    if (top == NULL)
        printf("Browser history is empty.\n");
    else
        printf("Browser history is not empty.\n");
}

void size() {
    int count = 0;
    struct Page *temp = top;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of webpages: %d\n", count);
}

int main() {
    int choice, id;
    char name[100];

    while (1) {
        printf("\n--- BROWSER HISTORY ---\n");
        printf("1. Push / Visit Page\n");
        printf("2. Pop / Back\n");
        printf("3. Peek / Current Page\n");
        printf("4. Display History\n");
        printf("5. isEmpty\n");
        printf("6. Size\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Page ID: ");
                scanf("%d", &id);

                printf("Enter Page Name/URL: ");
                scanf(" %[^\n]", name);

                push(id, name);
                break;

            case 2:
                pop();
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