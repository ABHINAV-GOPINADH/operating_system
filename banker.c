#include<stdio.h>
int main()
{
    int r,c,ct;
    printf("enter number of process: ");
    scanf("%d",&r);
    int p[r];
    for(int i=1;i<=r;i++)
    {
        p[i]=0;
    }
    printf("Enter number of resources :");
    scanf("%d",&c);
    int max [r][c];
    printf("Enter max number of resources required for each process : \n");
    for(int i=1;i<=r;i++)
    {
        printf("p[%d] :\n ",i);
        for(int j=1;j<=c;j++)
        {
            printf("\t R[%d]",j);
            scanf("%d",&max[i][j]);
        }
    }
    int allo[r][c];
    printf("Enter number of resources allocated for each process: \n");
    for(int i=1;i<=r;i++)
    {
        printf("P[%d]:\n",i);
        for(int j=1;j<=c;j++)
        {
            printf("\t R[%d]: ",j);
            scanf("%d",&allo[i][j]);
        }
    }
    int need[r][c];
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    int av[1][c];
    printf("Enter number of available resouces: \n");
    for(int j=1;j<=c;j++)
    {
        scanf("%d",&av[1][j]);
    }
    for(int i=1;i<=r;i++)
    {
        if(p[i]!=1)
        {
            ct=0;
            for(int j=1;j<=c;j++)
            {
                if(need[i][j]<=av[1][j])
                {
                    ct=ct+1;
                }
                else
                {
                    break;
                }
            }
            if(ct==c)
            {
                p[i]=1;
                printf("p[%d]\t",i);
                for(int j=1;j<=c;j++)
                {
                    av[1][j]+=allo[i][j];
                }
                i=0;
            }

        }
    }
    for(int i =1;i<=r;i++)
    {
        if(p[i]==1)
        {
            continue;
        }
        else
        {
            printf("\n not safe");
            return 0;
        }
    }
    printf("\n safe ");
    return 0;
}