#include <stdio.h>
struct DNode {
    int val;
    DNode* prev;
    DNode* next;
};

DNode* first;
DNode* last;

DNode* makeNode(int v) {
    DNode* h;
    h -> val = v;
    h -> prev = NULL;
    h -> next = NULL;
}

DNode* remove(DNode* p) {
    if (p == NULL)
        return NULL;
    if (first == last && p == first) {
        first = NULL;
        last = NULL;
        free(p);
        return NULL;
    } 
    if (p == first) {
        first = p -> next;
        first -> prev = NULL;
        free(p);
        return p;
    }
    if (p == last) {
        last = p -> prev;
        last -> next = NULL;
        free(p);
        return p;
    }
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;
    free(p);
    return p;
}

DNode* insertLast(int x) {
    DNode* q = makeNode(x);
    if (first == NULL && last == NULL) {
        first = q;
        last = q;
        return q;
    } 
    q -> prev = last;
    last -> next = q;
    last = q;
    return q;
}