#include<stdio.h>
int main()
{
    int a[100][4],at[50],bt[50],ct[50],tat[50],wt[50],process[50],pr[50];
    int i,j,n,total=0,index,temp,current_time=0,start_time,completed=0,count;
    float avg_wt,avg_tat;
    printf("Enter no. of processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time of process %d :",i);
        scanf("%d",&at[i]);
        printf("Enter burst time of process %d :",i);
        scanf("%d",&bt[i]);
        printf("Enter the piority of process %d : ",i );
        scanf("%d",&pr[i]);
        process[i]=i;
        printf("\n");
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(at[i]>at[j])
            {
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
            }
        }
    }
    printf("\n Process \t Arrival time \t Burst time \t Completion time \t Turnaround time \t waiting time \n");
    while(completed<n)
    {
        count=0;
        for(i=completed;i<n;i++)
        {
            if(at[i]<=current_time)
                count++;
            else 
                break;
        }
        if(count>1)
        {
            for(i=completed;i<(completed+count-1);i++)
            {
                for(j=i+1;j<(completed+count);j++)
                {
                    if(pr[i]>pr[j])
                    {
                        temp=pr[i];
                        pr[i]=pr[j];
                        pr[j]=temp;
                        temp=at[i];
                        at[i]=at[j];
                        at[j]=temp;
                        temp=bt[i];
                        bt[i]=bt[j];
                        bt[j]=temp;
                        temp=process[i];
                        process[i]=process[j];
                        process[j]=temp;  
                    }                 
                }
            }
        }
        start_time = current_time;
        ct[completed]=start_time+bt[completed];
        tat[completed]=ct[completed]-at[completed];
        wt[completed]=tat[completed]-bt[completed];
        current_time=ct[completed];
        printf("\n %d \t \t %d \t \t %d \t \t \t  %d \t \t \t %d \t \t %d \n",process[completed],at[completed],bt[completed],ct[completed],tat[completed],wt[completed]);
        avg_tat+=tat[completed];
        avg_wt+=wt[completed];
        completed++;
    }
    printf("\n average turn arpund time =%f \n ",avg_tat/n);
    printf("average waiting time = %f \n",avg_wt/n);
    return 0;
}