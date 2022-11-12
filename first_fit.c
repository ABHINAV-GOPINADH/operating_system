#include<stdio.h>
int main()
{
    int np,nb,i,j;
    printf("enter the number of process : ");
    scanf("%d",&np);
    int ap[np][2];
    for(i=1;i<=np;i++)
    {
        printf("P[%d] :",i);
        scanf("%d",&ap[i][0]);
        ap[i][1]=0;
    }
    printf("enter the number of blocks :");
    scanf("%d",&nb);
    int ab[nb][3];
    for(i=1;i<=nb;i++)
    {
        printf("B[%d]",i);
        scanf("%d",&ab[i][0]);
        ab[i][1]=0;
        ab[i][2]=0;
    }
    for(i=1;i<=np;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(ap[i][0]<=ab[j][0] && ap[i][1]!=1)
            {
                ab[j][1]=i;
                ab[j][2]=ap[i][0];
                ap[i][1]=1;
            }
        }
    }
    printf("Block \t Size \t process \t Size \t Status \n");
    for(i=1;i<=nb;i++)
    {
        printf("B[%d] \t %d \t %d \t %d \t ",i,ab[i][0],ab[i][1],ab[i][2]);
        if(ab[i][1]==0)
        {
            printf("not allocated \n");
        }
        else
        {
            printf("allocated \n");
        }
    }
}