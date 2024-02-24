#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* head; // pointer to the first element of the linked list

Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p -> value = v;
    p -> next = NULL;
    return p;
}

void printList(Node* h) {
    Node* p = h;
    while (p != NULL) {
        printf("%d ", p->value); // added space after printing value for clarity
        p = p->next;
    }
}

Node* addLast(int val, Node* h) {
    // create a new node having value = v, insert this node at the end of list pointed by h
    // return a pointer to the first node of the resulting list
    Node* p = makeNode(val);
    if (h == NULL) {
        return p;
    }

    Node* q = h;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
    return h;
}

Node* removeNode(int v, Node* h) {
    if ( h == NULL) {
        return NULL;
    }
    if (h -> value == v) {
        Node* tmp = h;
        h = h -> next;
        return h;
    } 
    Node* p = h;
    while (p -> next != NULL && p -> next -> value != v) {
        p = p -> next;
    }
    if (p -> next == NULL) {
        return h;
    }
    else {
        Node* tmp = p -> next;
        p -> next = p -> next -> next;
        return h;
    }
}

Node* insertFirst(int v, Node* h) {
    Node* p = makeNode(v);
    p -> next = h;
    return p;
}

Node* removeNodeRecursive(int v, Node* h) {
    if (h == NULL) {
        return h;
    } 
    if (h -> value == v) {
        Node* p = h -> next;
        free(h);
        return p;
    }
    h -> next = removeNodeRecursive(v, h -> next);
    return h;
}

Node* insertBefore(int v, int u, Node* h) {
    if (h == NULL) {
        return NULL;
    }
    if (h -> value == u) {
        Node* p = makeNode(v);
        p -> next = h;
        return p;
    }
    h -> next = insertBefore(v, u, h -> next);
    return h;
}

Node* reverse(Node* h) {
    Node* p = NULL;
    Node* k = h;
    while (k != NULL) {
        Node* q = k -> next;
        k -> next = p;
        p = k;
        k = q;
    }
    return p;
}

int sumRecusive(Node* h) {
    if (h == NULL) {
        return 0;
    } else {
        return h -> value + sumRecusive(h -> next);
    }
}

Node* insertAfter(int v, int u, Node* h) {
    if (h == NULL) {
        return NULL;
    }
    if (h -> value == u) {
        Node* p = makeNode(v);
        p -> next = h -> next;
        h -> next = p;
        return h;
    }
    h -> next = insertAfter(v, u, h -> next);
    return h;
}
int main() {
    head = NULL;
    int n;
    printf("Input value for n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++) {
        head = addLast(i, head);
    }
    head = reverse(head);
    printf("Sum = %d\n" , sumRecusive(head));
    printList(head);
    return 0;
}
