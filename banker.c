#include <stdio.h>

int main() {

    int allocation[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };


    int max[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };


    int need[5][3];

    printf("Need Matrix:\n");
    printf("Process | R1 R2 R3\n");
    printf("--------|---------\n");

    for (int i = 0; i < 5; i++) {
        printf("P%d      | ", i+1);
        for (int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d  ", need[i][j]);
        }
        printf("\n");
    }

    return 0;
}
