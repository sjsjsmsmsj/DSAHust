#include<stdio.h>
#include<stdbool.h>
int n;


void print(int a[n][n]) {
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check(int a[n][n], int c, int r) {

    for (int i = 0; i < c; i ++) {
        if (a[r][i]) {
            return 0;
        }
    }

    for (int i = 0; i < r; i ++) {
        if (a[i][c]) {
            return 0;
        }
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i --, j --) {
        if (a[i][j]) {
            return 0;
        }
    }
    for (int i = r, j = c; j >= 0 && i < n; i ++, j --) {
        if (a[i][j])
            return 0;
    }

    for (int i = r, j = c; j < n && i < n; i ++, j ++) {
        if (a[i][j])
            return 0;
    }

    for (int i = r, j = c; j < n && i >= 0; i --, j ++) {
        if (a[i][j])
            return 0;
    }
    return 1;
}

void backTracking(int a[n][n] ,int c) {
    if (c >= n) {
        print(a);
    } 
    for (int i = 0; i < n; i ++) {
        if (check(a, c, i)) {
            a[i][c] = 1;
            backTracking(a, c + 1);
            a[i][c] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            a[i][j] = 0;
        }
    }
    backTracking(a, 0);
    return 0;
}