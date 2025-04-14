#include<stdio.h>
#include<stdlib.h>

int deque[10];
int front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == 9) || (front == rear + 1)) {
        printf("Queue is full. Cannot insert from front.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = 9;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Element %d inserted from front.\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == 9) || (front == rear + 1)) {
        printf("Queue is full. Cannot insert from rear.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == 9) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Element %d inserted from rear.\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Queue is empty. Cannot delete from front.\n");
    } else {
        printf("Element %d deleted from front.\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == 9) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Queue is empty. Cannot delete from rear.\n");
    } else {
        printf("Element %d deleted from rear.\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = 9;
        } else {
            rear--;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the deque: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear) break;
            if (i == 9) {
                i = 0;
            } else {
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert from front\n");
        printf("2. Insert from rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted from front: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter the value to be inserted from rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}