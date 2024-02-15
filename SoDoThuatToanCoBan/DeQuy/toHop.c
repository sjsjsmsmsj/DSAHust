#include<stdio.h>
int C(int k, int n) {
    if (k == 0 || k == n)
        return 1;
    else {
        int C1 = C(k - 1, n - 1);
        int C2 = C(k, n - 1);
        return C1 + C2;
    }
}
int main() {
    int k, n;
    printf("Hay nhap lan luot hai gia tri k, n: ");
    scanf("%d%d", &k, &n);
    printf("%d", C(k, n));
    return 0;
}