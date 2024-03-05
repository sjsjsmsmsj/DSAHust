#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1;i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (a[i][j] == 1 && i < j) {
                printf("%d %d\n", i  , j);
            }
        }
    }
    return 0;
}