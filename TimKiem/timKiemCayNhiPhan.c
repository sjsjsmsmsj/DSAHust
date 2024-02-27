#include <stdio.h>

struct Node {
    int v;
    Node* leftMost;
    Node* right;
} ;
Node* root;

Node* makeNode(int k) {
    Node* r = (Node*)malloc(Node);
    r -> v = k;
    r -> leftMost = NULL;
    l -> right = NULL;
    return r;
}

Node* insert(struct Node* r, int v) {
    if (r == NULL) {
       r = makeNode(v);
       return r;
    } 
    else if (r  -> v < v) {
        insert(r -> leftMost, v);
    } 
    else if (r  -> v > v) {
        insert(r -> right, v);
    }
    else {
        return ;
    }
    return r;
}

Node* find(struct Node* r,int v) {
    if (r == NULL) {
        return NULL;
    }
    if (r -> v == v) {
        return r;
    }
     else if(r -> v > v) {
        find(r -> right, v);
    } else if (r -> v < v) {
        find(r -> leftMost, v);
    } 
    
}

int main() {
    root = NULL;
    insert(root, 7);
}
