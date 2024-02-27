#include<stdio.h>

void sapXepChon(int a[], int n) {
    for(int i = 0; i < n - 1; i ++) {
        int key = i;
        for (int j = i + 1; j < n; j ++) {
            if (a[key] > a[j]) {
                key = j;
            }
        }
        int tmp = a[i];
        a[i] = a[key];
        a[key] = tmp;
    }
}

void sapXepChen(int a[], int n) {
    for (int i = 1; i < n; i ++) {
        int key = i;
        int tmp = a[key];
        while (key > 0 && a[key - 1] > tmp) {
            a[key] = a[key - 1];
            key --;
        }
        a[key] = tmp;
    }
}

void sapXepNoiBot(int a[], int n) {
    int count = 0;
    for (int j = 0; j < n - 1;j ++) {
        for (int i = 0; i < n - 1 - count; i ++) {
            if(a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
        count ++;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i ++) {
        L[i] = a[l + i];
    }

    for (int i = 0; i < n2; i ++) {
        R[i] = a[m + i + 1];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if (L[i] < R[j]) {
            a[k ++] = L[i ++];
        } else {
            a[k ++] = R[j ++];
        }
    }
    while (i < n1) {
        a[k ++] = L[i ++];
    }
    
    while(j < n2) {
        a[k ++] = R[j ++];
    }
}

void mergeSort(int a[], int L, int R) {
    if(L < R) {
        int m = (L + R) / 2;
        mergeSort(a, L, m);
        mergeSort(a, m + 1, R);
        merge(a, L, m, R);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmpp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmpp;
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);
        
        // Sorting elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}




int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i ++) {
        printf("%d ", a[i]);
    }
    return 0;
}