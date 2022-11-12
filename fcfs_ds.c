#include<stdio.h>
int main()
{
    int i,h,n,m=0;
    printf("Enter the no of request : ");
    scanf("%d",&n);
    int r[n];
    printf("Enter request sequence : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    printf("Enter the head postion : ");
    scanf("%d",&h);
    for(i=0;i<n;i++)
    {
        if(r[i]>h)
        {
            m=m+(r[i]-h);
        }
        else
        {
            m=m+(h-r[i]);
        }
        h=r[i];
    }
    printf("Total head movement : %d",m);
}