// tìm số a[i] + a[j] = b i , j khác nhau
#include<stdio.h>

void input(int a[], int n) {
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
}

int solution1(int a[], int n, int b) {
    int count = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            if (a[i] + a[j] == b) {
                count ++;
            }
        }
    }
    return count;
}

int binarySearch(int a[], int l, int r, int b) {
    if (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == b)
            return m;
        if (a[m] < b)
            return binarySearch(a, m + 1, r, b);
        else
            return binarySearch(a, l, m - 1, b);
    }
    return -1;
}

int solution2(int a[], int n, int b) {
    int count = 0;
    for (int i = 0; i < n; i ++) {
        if (binarySearch(a, i + 1, n - 1, b - a[i]) != -1) {
            count ++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    input(a, n);
    int b;
    scanf("%d", &b);
    printf("%d", solution2(a, n, b));
    return 0;
}
