#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data1, data2;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int data1, int data2) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data1 = data1;
    newNode->data2 = data2;
    newNode->next = NULL;

    // If queue is empty, set both front and rear to the new node
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Otherwise, update the rear and link the previous last node to the new node
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return ;
    }

    // Get the data from the front node
    int data1 = q->front->data1;
    int data2 = q->front->data2;

    // Move front to the next node
    Node* temp = q->front;
    q->front = q->front->next;

    // If the queue becomes empty, update rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);

    printf("%d %d\n", data1, data2);
}

// Function to display the elements of the queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("(%d %d)\n", current->data1, current->data2);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the queue
void freeQueue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    q->front = q->rear = NULL;
}

int check(Queue* p, int x, int y) {
    while(p -> front != NULL) {
        if (x == p -> front -> data1 && y == p -> front -> data2) {
            break;
            return 1;
        }
        p -> front = p -> front -> next;
       
    }
    return 0;
}

int solution(Queue* q, int a, int b, int c) {
    int k = 0;
    int count = 1;
    int h = 0;
    while (!isEmpty(q)) {
        h ++;
        printf("%d\n", h);
        int x = q -> front -> data1;
        int y = q -> front -> data2;
        dequeue(q);
            int tmp1 = x;
            int tmp2 = y;
            if (count == 1) {
                x = a;
                y = 0;
                    enqueue(q, x, y);
                x = 0;
                y = b;

                    enqueue(q, x, y);
                    count ++;
            }
            else {
                if (x != 0) {
                    x = 0;
                        enqueue(q, x, y);
                }

                if (y != 0) {
                    y = 0;
                        enqueue(q, x, y);
                }
                
                if (x + y >= b) {
                    x = x + y - b;
                    y = b;
                       enqueue(q, x, y);
                }

                if (x + y <= b) {
                    x = 0;
                    // tmp = x
                    y = tmp1 + y;
                        enqueue(q, x, y);
                }

                if (x + y >= a) {
                    x = a;
                    y = tmp1 + y - a;
                            enqueue(q, x, y);
                    
                }

                if (x + y  <= a) {
                    x = x + y;
                    y = 0;
                        enqueue(q, x, y);
                    
                }
            }
        
        
        if (x == c || y == c || x + y == c)
        {
            k = 1;
            break;
        }
    }
    if (k == 0) {
        printf("Not found solution for the problem.\n");
    }
    return k;
}

int main() {
    Queue q;
    initializeQueue(&q);
    enqueue(&q, 0, 0);  // Starting point, both jugs are empty
    solution(&q, 6, 8, 4);
    display(&q);
    return 0;
}
