#include<stdio.h>
void thapHaNoi(char a, char b, char c, int n) {
    if (n == 1) 
        printf("%c -> %c\n", a, b);
    else {
        thapHaNoi(a, c, b, n - 1);
        thapHaNoi(a, b, c, 1);
        thapHaNoi(c, b, a, n - 1);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    thapHaNoi('a', 'b', 'c', n);
    return 0;
}