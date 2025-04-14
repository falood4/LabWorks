#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void main() {
    struct Node *head = NULL;
    int option, value, key;

while(option!=4) {
        printf("\n***Choose an option***\n");
        printf("1. Insertion\n");
        printf("   1. Insert at the beginning\n");
        printf("   2. Insert at the end\n");
        printf("   3. Insert after a specified node\n");
        printf("2. Deletion\n");
        printf("   1. Delete from the beginning\n");
        printf("   2. Delete from the end\n");
        printf("   3. Delete a specified node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);

            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL) {
                printf("Memory allocation failed.\n");
                exit(EXIT_FAILURE);
            }

            newNode->data = value;
            newNode->next = NULL;

            printf("Choose an insertion option (1/2/3): ");
            scanf(" %d", &option);
            switch (option) {
            case 1:
                newNode->next = head;
                head = newNode;
                printf("Node inserted at the beginning.\n");
                break;
            case 2:
                if (head == NULL) {
                    head = newNode;
                } else {
                    struct Node *temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                }
                printf("Node inserted at the end.\n");
                break;
            case 3:
                printf("Enter the key after which to insert: ");
                scanf("%d", &key);
                struct Node *temp = head;
                while (temp != NULL && temp->data != key) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Key not found. Cannot insert.\n");
                    free(newNode);
                } else {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    printf("Node inserted after the specified node.\n");
                }
                break;
            default:
                printf("Invalid option for insertion.\n");
            }
            break;

        case 2:
            printf("Choose a deletion option (1/2/3): ");
            scanf(" %d", &option);
            switch (option) {
            case 1:
                if (head == NULL) {
                    printf("List is empty. Cannot delete.\n");
                } else {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                    printf("Node deleted from the beginning.\n");
                }
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty. Cannot delete.\n");
                } else if (head->next == NULL) {
                    free(head);
                    head = NULL;
                    printf("Node deleted from the end.\n");
                } else {
                    struct Node *temp = head;
                    while (temp->next->next != NULL) {
                        temp = temp->next;
                    }
                    free(temp->next);
                    temp->next = NULL;
                    printf("Node deleted from the end.\n");
                }
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                struct Node *temp = head;
                struct Node *prev = NULL;
                while (temp != NULL && temp->data != key) {
                    prev = temp;
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Key not found. Cannot delete.\n");
                } else {
                    if (prev == NULL) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    free(temp);
                    printf("Node with key %d deleted.\n", key);
                }
                break;
            default:
                printf("Invalid option for deletion.\n");
            }
            break;

        case 3:
            display(head);
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid option. Please choose a valid option.\n");
        }

    }
}

