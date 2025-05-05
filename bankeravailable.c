#include <stdio.h>

int main() {

    int available[3] = {3, 3, 2};


    int allocation[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };


    int execution_order[] = {1, 3};
    int num_processes = 2;

    printf("Initial Available: (%d, %d, %d)\n\n", available[0], available[1], available[2]);

    for (int i = 0; i < num_processes; i++) {
        int process_idx = execution_order[i];

        printf("%d. Allocation: P%d\n", i+1, process_idx+1);
        printf("   Allocation resources: (%d, %d, %d)\n",
               allocation[process_idx][0],
               allocation[process_idx][1],
               allocation[process_idx][2]);


        printf("   New Available = Available + Allocation\n");
        printf("   (%d, %d, %d) + (%d, %d, %d)\n",
               available[0], available[1], available[2],
               allocation[process_idx][0],
               allocation[process_idx][1],
               allocation[process_idx][2]);

        for (int j = 0; j < 3; j++) {
            available[j] += allocation[process_idx][j];
        }

        printf("   = (%d, %d, %d)\n\n", available[0], available[1], available[2]);
    }

    printf("Final Available: (%d, %d, %d)\n", available[0], available[1], available[2]);

    return 0;
}
