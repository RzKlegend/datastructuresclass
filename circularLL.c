#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("malloc failed");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    newNode->next = head;
    tail->next = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    if (pos <= 1) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head) {
        temp->next = newNode;
        newNode->next = head;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtEnd(head, 30);
    head = insertAtPosition(head, 20, 2);

    printf("List after insertions: ");
    display(head);

    return 0;
}
