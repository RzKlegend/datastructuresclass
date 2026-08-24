#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Helper function to populate the list for deletion tests
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteAtBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("Deleted node from the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Deleted node from the end.\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", pos);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

int main() {
    insertAtEnd(10); insertAtEnd(20); insertAtEnd(30); insertAtEnd(40); insertAtEnd(50);
    printf("Initial ");
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtPosition(2);
    display();
    return 0;
}