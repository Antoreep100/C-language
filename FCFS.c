#include<stdio.h>
int main()
{

    int n,i;
    printf("Enter the number of processess: ");
    scanf("%d" , &n);
    int arrival_time[n],waiting_time[n],burst_time[n],completion_time[n],turn_around[n];
    int total_turn_around = 0;
    int total_waiting_time =0;
    for(i=0;i<n;i++)
    {

        printf("Enter the arrival time and burst time for process: %d ", i + 1);
        scanf("%d%d" , &arrival_time[i],&burst_time[i]);
    }
    for(i=1 ; i<n;i++)
    {
        if(completion_time[i-1] < arrival_time[i])
        {
            completion_time[i] =arrival_time[i] + burst_time[i];
        }
        else
        {
            completion_time[i]=completion_time[i] - arrival_time[i];
        }
        turn_around[i] = completion_time[i] - arrival_time[i];
        waiting_time[i]=turn_around[i]- burst_time[i];
    }
    printf("\nPid\taT\tBT\tCT\tTAT\tWT\n");
    for( i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d",i+1,arrival_time[i],burst_time[i],turn_around[i],completion_time[i],waiting_time[i]);
        total_turn_around += turn_around[i];
        total_waiting_time += waiting_time[i];
        }
        printf("Average turn around: %.2f\n ",(float)total_turn_around);
        printf("Average waiting time: %.2f\n ",(float)total_waiting_time);
}
