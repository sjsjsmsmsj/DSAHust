#include<stdio.h>
int n;
int ans;
//tìm dãy con lớn nhất dùng quy hoạch động
int max(int a, int b) {
    if ( a > b ) {
        return a;
    } else {
        return b;
    }
}

void dpMaxSeq(int a[], int l, int r) {
    int S = a[1];
    ans = a[1];
    for (int i = l + 1; i <= r; i ++) {
        if(S > 0) {
            S = S + a[i];
        } else {
            S = a[i];
        }
        ans = max(ans, S);
    }
        printf("Dãy con lớn nhất có giá trị: %d\n", ans);
}

int main() {
    printf("Hãy nhập số phần tử: ");
    scanf("%d", &n);
    int a[n];
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    dpMaxSeq(a, 1, n);
    return 0;
}