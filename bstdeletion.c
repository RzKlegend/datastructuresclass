/*Instruction: Write a complete C program to construct a Binary Search Tree and perform deletion operations.
The program should:
1.	Create a structure for a BST node. 
2.	Implement a function to create a new node. 
3.	Implement a function to insert elements into the BST. 
4.	Implement a function to delete a specified node from the BST. 
5.	Handle all three deletion cases. 
6.	Take the element to be deleted from the user. 
7.	Display the BST before deletion using Inorder Traversal. 
8.	Perform the deletion operation. 
9.	Display the BST after deletion using Inorder Traversal. 
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an element
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find the Inorder Successor (minimum value in right subtree)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Search for the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        // Case 1 & 2: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data; // Copy successor's value
        root->right = deleteNode(root->right, temp->data); // Delete successor
    }
    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, delValue;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nBST before deletion (Inorder): ");
    inorder(root);
    printf("\n");

    printf("\nEnter element to delete: ");
    scanf("%d", &delValue);

    root = deleteNode(root, delValue);

    printf("BST after deletion (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}