#include<stdio.h>
int a[9][9];
int markR[9][10];
int markC[9][10];
int markS[3][3][10];
void print() {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n\n\n");
}

int check(int v, int r, int c) {
    if (markR[r][v] == -1)
        return 0;
    if (markC[c][v] == -1)
        return 0;
    if (markS[r/3][c/3][v] == -1)
        return 0;
    return 1;
}

void backTracking(int r, int c) {
    for (int i = 1; i <= 9; i ++) {
        if (!check(i, r, c)) {
            a[r][c] = i;
            markR[r][i] = 1;
            markC[c][i] = 1;
            markS[r / 3][c / 3][i] = 1;
            if (r == 8 && c == 8) {
                print();
            } else {

                if (c < 8) {
                    backTracking(r, c + 1);
                } else {
                    backTracking(r + 1, 0);
                }

            }

            markR[r][i] = -1;
            markC[c][i] = -1;
            markS[r / 3][c / 3][i] = -1;
        }
    }
}

int main() {
    for (int i = 1; i < 10; i ++) {
        for (int r = 0; r < 9; r ++) {
            markR[r][i] = -1;
        } 
        for (int c = 0; c < 9; c ++) {
            markC[c][i] = -1;
        }
        for (int j = 0; j < 3; j ++) {
            for (int k = 0; k < 3; k ++) {
                markS[j][k][i] = -1;
            }
        }
    }
    backTracking(0, 0);
    return 0;
}


