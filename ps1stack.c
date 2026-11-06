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

struct WebPage {
    int page_id;
    char url[100];
    struct WebPage* next;
};

struct WebPage* top = NULL;
int size = 0;

void push(int id, char* url) {
    struct WebPage* newPage = (struct WebPage*)malloc(sizeof(struct WebPage));
    newPage->page_id = id;
    strcpy(newPage->url, url);
    newPage->next = top;
    top = newPage;
    size++;
    printf("Visited: %s\n", url);
}

void pop() {
    if (top == NULL) {
        printf("No history to go back to.\n");
        return;
    }
    struct WebPage* temp = top;
    printf("Going back from: %s\n", temp->url);
    top = top->next;
    free(temp);
    size--;
}

void peek() {
    if (top == NULL) {
        printf("Browser history is empty.\n");
        return;
    }
    printf("Current Page: %s (ID: %d)\n", top->url, top->page_id);
}

void display() {
    if (top == NULL) {
        printf("Browser history is empty.\n");
        return;
    }
    struct WebPage* temp = top;
    printf("Browser History (Most recent first):\n");
    while (temp != NULL) {
        printf("[ID: %d, URL: %s] -> ", temp->page_id, temp->url);
        temp = temp->next;
    }
    printf("NULL\n");
}

void isEmpty() {
    if (top == NULL) printf("Stack is Empty: Yes\n");
    else printf("Stack is Empty: No\n");
}

void getSize() {
    printf("Total webpages in history: %d\n", size);
}

int main() {
    push(1, "google.com");
    push(2, "github.com");
    push(3, "stackoverflow.com");
    display();
    peek();
    getSize();
    pop();
    display();
    isEmpty();
    return 0;
}