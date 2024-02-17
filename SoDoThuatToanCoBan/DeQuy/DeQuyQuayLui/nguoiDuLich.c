#include <stdio.h>
# define N 100
# define INF 10000000000

int a[N]; // điểm đi, điểm đến
int n, m; // n số điểm cần muốn đến, m số chuyến bay cần phải đi
long long c[N][N]; // c[i][j] là đi từ điểm i -> j
int mark[N]; // đánh dấu thành phần chưa đi
long long f; // độ dài hành trình đã đi được
long long f_min; // tổng độ dài hành trình đi ngắn nhất
long long cm; // quãng đường từng chặn ngắn nhất

void vietThongTin() {

    printf("Hãy nhập số điểm muốn đến: ");
    scanf("%d", &n);
    printf("Hãy nhập số điểm cần phải đi: ");
    scanf("%d", &m);
    printf("\n");
    
    cm = INF;
    // gán giá trị mặc định cho các điểm đi và điểm đến để không bị lỗi
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            c[i][j] = INF;
        }
    }

    // nhập điểm đến, điểm đi, giá tiền
    int count = 0;
    for (int i = 1; i <= m; i ++) {

            count ++;
            //printf("Hãy nhập điểm đến thứ %d: ", count);
            int start, end, length;
            scanf("%d", &start);
            //printf("Hãy nhập dừng chân thứ %d: ", count);
            scanf("%d", &end);
            //printf("Hãy độ dài chuyến đi thứ %d: ", count);
            scanf("%d", &length);
            c[start][end] = length;
            if (c[start][end] < cm) {
                cm = c[start][end]; 
            }
            printf("\n");
    }

}

void capNhatQuangDuong() {
    if (f + c[a[n]][a[1]] < f_min) {
        f_min = f + c[a[n]][a[1]];
    }
}

void backTracking(int i) {
    for (int j = 1; j <= n;j ++) {
        if (mark[j] == 0) {
            a[i] = j;
            f = f + c[a[i - 1]][a[i]];
            mark[j] = 1;
            if (i == n) {
                capNhatQuangDuong();
            } else {
                int gk = f + cm*(n - i + 1);
                if (gk < f_min)
                    backTracking(i + 1);
            }
            f = f - c[a[i - 1]][a[i]];
            mark[j] = 0;
        }
    }
}

int main() {
    vietThongTin();
    for (int i = 1; i <= m; i ++) {
        mark[i] = 0;
    }
    f = 0;
    f_min = INF;
    a[1] = 1;
    mark[1] = 1;
    backTracking(2);
    if (f_min == INF)
        printf("Không tìm thấy có lẽ bạn đã nhập sai !!!");
    else
        printf("Độ dài đường đi ngắn nhất:  %lld\n", f_min);
    return 0;
}
