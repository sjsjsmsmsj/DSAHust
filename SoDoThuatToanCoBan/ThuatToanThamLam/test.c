#include <stdio.h>
#define N 100001
// Bài toán tìm nhiều khoảng có giá trị không trùng nhau
// dùng thuật toán tham lam 
typedef struct Segment {
    int a, b;
} Segment;

Segment s[10001];
int n;

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &s[i].a, &s[i].b);
    }
}

void merge(Segment a[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    Segment R[n2 + 2], L[n1 + 2];
    for (int i = 1; i <= n2; i++) {
        R[i] = a[mid + i];
    }
    for (int i = 1; i <= n1; i++) {
        L[i] = a[l + i - 1];
    }
    int i = 1, j = 1, k = l;
    while (i <= n2 && j <= n1) {
        if (R[i].b <= L[j].b) {
            a[k++] = R[i++];
        } else {
            a[k++] = L[j++];
        }
    }
    while (i <= n2) {
        a[k++] = R[i++];
    }
    while (j <= n1) {
        a[k++] = L[j++];
    } 
}

void mergeSort(Segment a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int ans = 0;
void select() {
    mergeSort(s, 1, n);
    int last = - N;
    for (int i = 1; i <= n; i++) {
        if (s[i].a > last) {
            ans ++;
            last = s[i].b;
            printf("Select segment %d: (%d %d)\n", i, s[i].a, s[i].b);
        }
    }
    printf("%d", ans);
}

int main() {
    input();
    select();
    return 0;
}



