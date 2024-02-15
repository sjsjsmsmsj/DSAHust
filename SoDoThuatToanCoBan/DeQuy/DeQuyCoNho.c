#include<stdio.h>
int m[50][50];

int C(int k, int n) {
    if (k == 0 || k == n) {
        m[k][n] = 1;
    } else {
        if (m[k][n] < 0) {
            m[k][n] = C(k - 1, n - 1) + C(k, n - 1);
        }
    }
    return m[k][n];
}

int main() {
    int k, n;
    scanf("%d%d", &k, &n);
    for (int i = 0; i < 50; i ++) {
        for (int j = 0; j < 50; j ++) {
            m[i][j] = -1;
        }
    }
    printf("%d", C(k, n));
    return 0;
}