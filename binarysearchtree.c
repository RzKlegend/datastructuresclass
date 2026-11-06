/*Instruction: Write a complete C program to construct a Binary Search Tree and perform insertion operations. The program should:
1.	Create a structure for a BST node. 
2.	Implement a function to create a new node. 
3.	Implement an insertion function to insert elements into the BST. 
4.	Take the required elements as input from the user. 
5.	Construct the BST by inserting the elements one by one. 
6.	Display the constructed BST using an appropriate traversal, such as Inorder Traversal. 
7.	Clearly display the elements inserted into the BST and the final traversal output.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert elements into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Duplicate values are ignored in this implementation
    return root;
}

// Function for Inorder Traversal (Left-Root-Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of elements to insert in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
        printf("Inserted %d into BST.\n", value);
    }

    printf("\nInorder Traversal of the Constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}