#include<stdio.h>
#include<stdbool.h>
int n, k;
int a[100];
bool check[10];
void print() {
    for (int i = 0; i < n; i ++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int check2(int a[]) {
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[j] < a[i])
                return 0;
        }
    }
    return 1;
}
void backTracking(int i) {
    if (i == n && check2(a)) {
        print();
    } else {
        for (int j = 1; j <= k; j ++) {
            if (!check[j] ) {
                    a[i] = j;
                    check[j] = true;
                    backTracking(i + 1);
                    check[j] = false;
            }
        }
    }
}
int main() {
    for (int i = 0; i < 10; i ++) {
        check[i] = false;
    }
    scanf("%d", &n);
    scanf("%d", &k);
    backTracking(0);
    return 0;
}