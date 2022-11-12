#include<stdio.h>
int main()
{
    int np,nf,i,j,pfc=0,k;
    printf("Enter the number of pages : ");
    scanf("%d",&np);
    int ap[np],f[np];
    printf("Enter page numbers : \n");
    for(i=0;i<np;i++)
    {
        scanf("%d",&ap[i]);
        f[i]=0;
    }
    printf("Enter number of frames : ");
    scanf("%d",&nf);
    int af[nf][3];
    for(i=0;i<nf;i++)
    {
        af[i][0]=-1;
        af[i][1]=0;//frequency
        af[i][2]=-1;//time
    }
    for(i=0;i<np;i++)
    {
        for(j=0;j<nf;j++)
        {
            if(af[j][1]==-1)
            {
                af[j][0]==ap[i];
                af[j][1]=1;
                af[j][2]=i;
                pfc++;
                printf("%d \t",ap[i]);
                for(k=0;k<nf;k++)
                {
                    printf("%d",af[k][0]);
                }
                printf("\n");
                break;
            }
            else if(ap[i]==af[j][0])
            {
                af[j][1]++;
                printf("%d \n",ap[i]);
                break;
            }
        }
        if(j==nf)
        {
            int min=0,c=0;
            for(k=1;k<nf;k++)
            {
                if(af[k][1]<af[min][1])
                {
                    min=k;
                    c++;
                }
                if(af[k][2]<af[min][2] && af[k][1]==af[min][1])
                {
                    min=k;
                    c++;
                }
            }
            af[min][0]=ap[i];
            af[min][1]=1;
            af[min][2]=i;
            pfc++;
            printf("%d \t ",ap[i]);
            for(k=0;k<nf;k++)
            {
                printf("%d  ",af[k][0]);
            }
            printf("\n");
        }
    }
    printf("page fault is %d",&pfc);
    return 0;
}