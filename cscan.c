#include<stdio.h>
int main()
{
    int i,h,n,sum=0,d,t,j,temp;
    printf("Enter no. of request : ");
    scanf("%d",&n);
    int r[n];
    printf("Enter the request sequence : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    printf("Enter initial head position : ");
    scanf("%d",&h);
    printf("enter the total disk position : ");
    scanf("%d",&t);
    printf("Enter head movement direction (low:0 high:1) : ");
    scanf("%d",&d);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]>r[j+1])
            {
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
            }
        }
    }
    if(d==0)
    {
        for(i=0;i<n;i++)
        {
            if(h<=r[i])
            {
                j=i;
                break;
            }
        }
        for(i=j-1;i>=0;i--)
        {
            sum=sum+(h-r[i]);
            h=r[i];
            if(i==0)
            {
                sum=sum+h;
                h=0;
            }
        }
        for(i=n-1;i>=j;i--)
        {
            if(i==n-1)
            {
                sum=sum+((t-1));
                h=t-1;
            }
            sum=sum+(h-r[i]);
            h=r[i];
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(h<=r[i])
            {
                j=i;
                break;
            }
        }
        for(j=i;i<n;i++)
        {
            sum=sum+(r[i]-h);
            h=r[i];
            if(i==(n-1))
            {
                sum=sum+(t-1);
                h=t-1;
            }
        }
        for(i=0;i<j;j++)
        {
            if(i==0)
            {
                sum=sum+h;
                h=0;
            }
            sum=sum+(h-r[i]);
            h=r[i];
        }
    }
    printf("total head movement : %d",sum);
    return 0;
}