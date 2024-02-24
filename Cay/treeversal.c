#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
    int id;
    struct TNode* leftMostChild;
    struct TNode* rightSibling;
} Node;

Node* root;

int depthNode(int v, Node* r, int d) {
    if (r == NULL) {
        return -1; // Node not found
    }

    if (r->id == v) {
        return d;
    }

    Node* p = r->leftMostChild;
    while (p != NULL) {
        int depth = depthNode(v, p, d + 1);
        if (depth != -1) {
            return depth;
        }
        p = p->rightSibling;
    }

    return -1; // Node not found
}

int count(Node* r) {
    if (r == NULL) {
        return 0;
    } 
    int ans = 1;
    Node* p = r -> leftMostChild;
    while(p != NULL) {
        ans += count(p);
        p = p -> rightSibling;
    }
    return ans;
}

int countLeaves(Node* r) {
    if (r == NULL) {
        return 0;
    }
    if (r->leftMostChild == NULL) {
        return 1;
    }
    int ans = 0;
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        ans += countLeaves(p);
    }
    return ans;
}

Node* makeNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = v;
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* find(int v, Node* r) {
    if (r == NULL) {
        return NULL;
    }

    if (r->id == v) {
        return r;
    }

    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* q = find(v, p);
        if (q != NULL)
            return q;
        p = p->rightSibling;
    }

    return NULL;
}

int heightNode(Node* r) {
    if (r == NULL) {
        return 1; // Height of empty tree is 1
    } 
    int max = 0;
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        int h = heightNode(p);
        if (h > max) {
            max = h;
        }
    }
    return max + 1;
}

int height(int v) {
    Node* r = find(v, root);
    return heightNode(r);
}

void insert(Node* parent, int u) {
    Node* p = makeNode(u);
    if (parent->leftMostChild == NULL) {
        parent->leftMostChild = p;
    } else {
        Node* h = parent->leftMostChild;
        while (h->rightSibling != NULL) {
            h = h->rightSibling;
        }
        h->rightSibling = p;
    }
}

void inOrder(Node* r) {
    if (r == NULL)
        return;
    inOrder(r->leftMostChild);
    printf("%d ", r->id);
    inOrder(r->rightSibling);
}

void preOrder(Node* r) {
    if (r == NULL)
        return;
    printf("%d ", r->id);
    preOrder(r->leftMostChild);
    preOrder(r->rightSibling);
}

void postOrder(Node* r) {
    if (r == NULL)
        return;
    postOrder(r->leftMostChild);
    postOrder(r->rightSibling);
    printf("%d ", r->id);
}

void printTree(Node* r) {
    if (r == NULL) {
        return;
    }
    printf("%d: ", r->id);
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        printf("%d ", p->id);
    }
    printf("\n");
    for (Node* p = r->leftMostChild; p != NULL; p = p->rightSibling) {
        printTree(p);
    }
}

int main() {
    char cmd[50];
    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "$MakeRoot") == 0) {
            int v;
            scanf("%d", &v);
            root = makeNode(v);
        } else if (strcmp(cmd, "$Insert") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            Node* parent = find(v, root);
            if (parent != NULL)
                insert(parent, u);
        } else if (strcmp(cmd, "$InOrder") == 0) {
            printf("In-Order Traversal: ");
            inOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "$PreOrder") == 0) {
            printf("Pre-Order Traversal: ");
            preOrder(root);
            printf("\n");
        } else if (strcmp(cmd, "$PostOrder") == 0) {
            printf("Post-Order Traversal: ");
            postOrder(root);
            printf("\n");
        }  else if (strcmp(cmd, "*") == 0) {
            break;
        }
    }
    printf("Total node: %d\n", count(root));
    printf("Leaves: %d\n", countLeaves(root));
    printf("Height: %d\n", height(10));
    printf("Depth: %d", depthNode(9, root, 1)); // Example depth calculation
    return 0;
}
