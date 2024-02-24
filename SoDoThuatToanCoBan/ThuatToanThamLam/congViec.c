#include <stdio.h>
#include <stdlib.h>
//Bài toán chọn số công việc sao cho kịp deadline và nhiều tiền nhất
// Định nghĩa cấu trúc công việc
struct Job {
    int deadline;  // Thời hạn hoàn thành
    int profit;    // Lợi nhuận
};

// Hàm so sánh để sử dụng trong việc sắp xếp công việc
int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Hàm chọn các công việc để thực hiện
void selectJobs(struct Job arr[], int n) {
    // Sắp xếp các công việc theo lợi nhuận giảm dần
    qsort(arr, n, sizeof(struct Job), compare);

    // Mảng để kiểm tra xem công việc i đã được chọn hay chưa
    int *result = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        result[i] = -1; // Khởi tạo tất cả các công việc chưa được chọn
    }

    // Điều này sẽ giúp đánh dấu thời điểm cuối cùng của công việc đang chọn
    int maxProfit = 0;
    
    // Lặp qua tất cả các công việc
    for (int i = 0; i < n; i++) {
        // Tìm vị trí cuối cùng mà công việc có thể được thực hiện
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (result[j] == -1) {
                result[j] = i;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }

    // In ra các công việc được chọn
    printf("Cac cong viec duoc chon la: ");
    for (int i = 0; i < n; i++) {
        if (result[i] != -1) {
            printf("%d ", result[i] + 1);
        }
    }
    printf("\nTong loi nhuan thu duoc la: %d\n", maxProfit);

    free(result);
}

int main() {
    int n;
    printf("Nhap so cong viec: ");
    scanf("%d", &n);

    // Nhập thông tin về công việc
    struct Job *arr = (struct Job *)malloc(sizeof(struct Job) * n);
    printf("Nhap thoi han hoan thanh va loi nhuan cua moi cong viec:\n");
    for (int i = 0; i < n; i++) {
        printf("Cong viec %d: ", i + 1);
        scanf("%d %d", &arr[i].deadline, &arr[i].profit);
    }

    // Chọn các công việc để thực hiện
    selectJobs(arr, n);

    free(arr);
    return 0;
}
