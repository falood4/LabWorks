#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterNode(int data, int key);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAfterNode(int key);
void displayForward();
void displayBackward();

int main() {
    int choice, data, key;

    do {
        printf("\n\n 1.Insert at the beginning 2. Insert at the end 3. Insert after a specified node 4. Delete at the beginning 5. Delete at the end 6. Delete after a specified node 7. Display forward 8. Display backward 9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter key after which to insert: ");
                scanf("%d", &key);
                insertAfterNode(data, key);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter key after which to delete: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 9);

    return 0;
}

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node inserted at the end.\n");
}

void insertAfterNode(int data, int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;

    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with key %d not found!\n", key);
        free(newNode);
        return;
    }

    newNode->prev = temp;
    newNode->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    printf("Node inserted after the node with key %d.\n", key);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;

    if (head->next != NULL) {
        head->next->prev = NULL;
    }

    head = head->next;
    free(temp);

    printf("Node deleted from the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);

    printf("Node deleted from the end.\n");
}

void deleteAfterNode(int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Node with key %d not found or it is the last node!\n", key);
        return;
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;

    if (deleteNode->next != NULL) {
        deleteNode->next->prev = temp;
    }

    free(deleteNode);

    printf("Node deleted after the node with key %d.\n", key);
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Nodes in forward order: ");
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Nodes in backward order: ");
    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}
