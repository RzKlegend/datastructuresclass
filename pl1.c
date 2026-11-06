/*Problem Statement 1: Customer Service Ticket Management System
A customer support center maintains service requests using a Singly Linked List. Each ticket contains:
•	Ticket ID 
•	Customer Name 
•	Issue Category 
Develop a C program to perform the following operations:
1.	Create a linked list of service tickets. 
2.	Insert a new ticket at the beginning, end, or a specified position. 
3.	Delete a ticket using its Ticket ID. 
4.	Display all pending service tickets. 
5.	Search for a ticket using its Ticket ID. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    int ticketID;
    char customerName[50];
    char issueCategory[50];
    struct Ticket *next;
};

// Insert at beginning for simplicity
struct Ticket* insertTicket(struct Ticket* head, int id, char* name, char* category) {
    struct Ticket* newTicket = (struct Ticket*)malloc(sizeof(struct Ticket));
    newTicket->ticketID = id;
    strcpy(newTicket->customerName, name);
    strcpy(newTicket->issueCategory, category);
    newTicket->next = head;
    return newTicket;
}

struct Ticket* deleteTicket(struct Ticket* head, int id) {
    if (head == NULL) return NULL;
    
    if (head->ticketID == id) {
        struct Ticket* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Ticket* temp = head;
    while (temp->next != NULL && temp->next->ticketID != id) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        struct Ticket* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
    return head;
}

void displayTickets(struct Ticket* head) {
    struct Ticket* temp = head;
    while (temp != NULL) {
        printf("[ID: %d | Name: %s | Issue: %s] -> \n", temp->ticketID, temp->customerName, temp->issueCategory);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

void searchTicket(struct Ticket* head, int id) {
    struct Ticket* temp = head;
    while (temp != NULL) {
        if (temp->ticketID == id) {
            printf("Found Ticket - ID: %d, Name: %s\n", temp->ticketID, temp->customerName);
            return;
        }
        temp = temp->next;
    }
    printf("Ticket %d not found.\n", id);
}

int main() {
    struct Ticket* head = NULL;
    
    head = insertTicket(head, 101, "John Doe", "Internet Down");
    head = insertTicket(head, 102, "Jane Smith", "Hardware Fault");
    
    printf("All Pending Tickets:\n");
    displayTickets(head);
    
    searchTicket(head, 101);
    
    printf("\nDeleting Ticket 102...\n");
    head = deleteTicket(head, 102);
    displayTickets(head);
    
    return 0;
}

