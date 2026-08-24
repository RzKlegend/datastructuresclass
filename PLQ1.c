/*Post Lab Questions
1. Browser History Management System 
A web browser maintains the user's browsing history using a Doubly Linked List.
Each node contains:
•	Page ID 
•	Website Name 
•	URL 
•	Timestamp 
Develop a C program to:
1.	Visit and add a new webpage to the history. 
2.	Move to the previous webpage. 
3.	Move to the next webpage. 
4.	Delete a webpage from the history. 
5.	Display browsing history from oldest to newest. 
6.	Display browsing history from newest to oldest. 
7.	Search for a webpage using its URL. 
(Write the complete C program here.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Page {
    int pageID;
    char websiteName[50];
    char url[50];
    char timestamp[20];
    struct Page* prev;
    struct Page* next;
};

struct Page* addPage(struct Page* head, int id, char* name, char* url, char* time) {
    struct Page* newPage = (struct Page*)malloc(sizeof(struct Page));
    newPage->pageID = id;
    strcpy(newPage->websiteName, name);
    strcpy(newPage->url, url);
    strcpy(newPage->timestamp, time);
    newPage->next = NULL;
    
    if (head == NULL) {
        newPage->prev = NULL;
        return newPage;
    }
    
    struct Page* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newPage;
    newPage->prev = temp;
    return head;
}

void displayOldestToNewest(struct Page* head) {
    struct Page* temp = head;
    while (temp != NULL) {
        printf("[%s] %s (%s)\n", temp->timestamp, temp->websiteName, temp->url);
        temp = temp->next;
    }
}

void displayNewestToOldest(struct Page* head) {
    if (head == NULL) return;
    struct Page* temp = head;
    while (temp->next != NULL) temp = temp->next;
    while (temp != NULL) {
        printf("[%s] %s (%s)\n", temp->timestamp, temp->websiteName, temp->url);
        temp = temp->prev;
    }
}

int main() {
    struct Page* history = NULL;
    history = addPage(history, 1, "Google", "google.com", "10:00 AM");
    history = addPage(history, 2, "GitHub", "github.com", "10:05 AM");
    
    printf("History (Oldest to Newest):\n");
    displayOldestToNewest(history);
    
    printf("\nHistory (Newest to Oldest):\n");
    displayNewestToOldest(history);
    
    return 0;
}
