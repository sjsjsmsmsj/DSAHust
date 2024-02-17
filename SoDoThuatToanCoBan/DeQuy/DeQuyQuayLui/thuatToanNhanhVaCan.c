#include<stdio.h>
#define N 30
int n, m;
int a[N];
long long c[N][N];
int mark[N];
int f;
long long f_min;
void viet() {

    printf("Hãy các nước muốn đi: ");
    scanf("%d", &n);
    printf("Hãy nhập số chuyến mình thích đi: ");
    scanf("%d", &m);
    printf("\n");
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n;j ++) {
            c[i][j] = 10000000000;
        } 
    }

    int count = 0;
    for (int k = 1; k <= m; k ++) {
        count ++;
        int i, j, d;
        printf("Hãy nhập điểm bắt đầu cho chuyến bay %d: ", count);
        scanf("%d", &i);
        printf("Hãy nhập điểm thúc cho chuyến bay %d: ", count);
        scanf("%d", &j);
        printf("Hãy nhập số tiền cho chuyến bay %d: ", count);
        scanf("%d", &d);
        printf("\n");
        c[i][j] = d;
    }

}
void nguoiDuLich() {

    if (f + c[a[n]][a[1]] < f_min) {
        f_min = f + c[a[n]][a[1]];
    }

}
void backTracking(int i) {

    for (int j = 1; j <= n; j ++) {
        if (mark[j] == 0) {
            a[i] = j;
            f = f + c[a[i - 1]][a[i]];
            mark[j] = 1;
            if (i == n) {
                nguoiDuLich();
            } else {
                backTracking(i + 1);
            }
            f = f - c[a[i - 1]][a[i]];
            mark[j] = 0;
        }
    }

}
int main() {
    viet();
    f = 0;
    for (int i = 1; i <= n; i ++) {
        mark[i] = 0;
    }
    a[1] = 1; 
    mark[1] = 1;
    f_min = 10000000000;
    backTracking(2);
    printf("Giá tiền phải trả cho chuyến quãng đường ngắn nhất của bạn là: %lld\n", f_min);
    return 0;
}