#include<stdio.h>
int main()
{
    int i,n,tsum=0,twt=0;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    int a[n][5];
    for(i=0;i<n;i++)
    {
        printf("enter the %d at : ",i+1);
        scanf("%d",&a[i][1]);
        printf("enter the %d bt : ",i+1);
        scanf("%d",&a[i][2]);
    }
    a[0][3]=a[0][2];
    for(i=1;i<n;i++)
    {
        a[i][3]=a[i-1][3]+a[i][2];
    }
    for(i=0;i<n;i++)
    {
        a[i][4]=a[i][3]-a[i][1];
        a[i][5]=a[i][4]-a[i][2];
    }
    printf("AT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]);
        tsum=tsum+a[i][4];
        twt=twt+a[i][5];
    }
    printf("average turn around time : %d \n",tsum/n);
    printf("average waiting time : %d",twt/n);
}