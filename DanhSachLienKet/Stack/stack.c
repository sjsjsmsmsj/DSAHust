#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// push(x, S):  chèn 1 phần tử x vào ngăn xếp 
// pop(S): lấy ra 1 phần tử khỏi ngăn xếp
// top(S): try cập phần tử ở đỉn của ngăn xếp
// empty(S): trả về true nếu ngăn xếp là rỗng
char s[100000];

typedef struct StackNode {
    char c;
    struct StackNode* next;
} Node;

int n = 0;
Node* top = NULL;



Node* makeNode(char c) {
    Node* p = (Node*)malloc(sizeof(Node));
    p -> c = c; p -> next = NULL;
    return p;
}

void push(char c) {
    Node* p = makeNode(c);
    p -> next = top;
    top = p;
}

char pop() {
    char c = top -> c;
    Node* tmp = top;
    top = top -> next;
    free(tmp);
    return c;
}

int empty() {
    return top == NULL;
}

int match(char o, char c) {
    if (o == ')' && c == '(') {
        return 1;
    } else if(o == '}' && c == '{') {
        return 1;
    } else if (o == ']' && c == '[') {
        return 1;
    } else 
        return 0;
}

int check(char* s) {
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
        } else {
            if (empty() == 1)
                return 0;
            char c = pop();
            if (match(s[i], c) == 0) 
                return 0;
        }
    }
    return empty();
}

int main() {
    scanf("%s", s);
    int ans = check(s);
    printf("%d", ans);
}