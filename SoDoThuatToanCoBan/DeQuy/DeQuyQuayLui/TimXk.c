#include<stdio.h>
int n, M, T, R;
int a[20];
int x[20];
void input() {
    scanf("%d%d", &n, &M);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
}
void print() {
    for (int i = 1; i <= n; i ++) {
        printf("%d*%d ", a[i], x[i]);
    }
    printf("= %d\n", M);
}
int check(int i, int j) {
    if (j < n) 
        return 1;
    if (T + a[n]* i == M) 
        return 1;
    else 
        return 0;
}

void backTracking(int j) {
    for (int i = 1; i <= (M - T - R) / a[j]; i ++) {
        if (check(i, j)) {
            x[j] = i;

            T += a[j] * x[j];
            R -= a[j + 1];

            if (j == n) {
                print();
            }
            else 
                backTracking(j + 1);
            
            T -= a[j] * x[j];
            R += a[j + 1];

        }
    }
}

int main() {
    input();
    T = 0;
    R = 0;
    for (int i = 2; i <= n; i ++) {
        R = R + a[i];
    }
    backTracking(1);
    return 0;
}