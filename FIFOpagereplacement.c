#include<stdio.h>


void main()
{
    int n,j,f,st=-1,ed=-1,m=0;
    printf("Enter no. of pages ");
    scanf("%d",&n);
    printf("Enter no. of Frames ");
    scanf("%d",&f);

    printf("Enter the pages ");
    int p[n],i,q[f],flg[50],a,k=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    for(i=0;i<50;i++)
    {
        flg[i]=0;
    }

    printf("str\tpage frames\n");
    for(i=0;i<n;i++)
    {
        a=p[i];
        if(flg[a]==0)
        {
            if(st==-1)
            {
                st=0;
                ed=1;
                q[ed-1]=a;
                printf("%d\t%d\n",a,q[st]);
                flg[a]=1;
            }
            else if(ed-st<f)
            {
                ed++;
                q[ed-1]=a;
                flg[a]=1;
                printf("%d\t",a);
                for(j=st;j<ed;j++)
                {
                    printf("%d\t",q[j]);
                }
                printf("\n");
            }
            else
            {
                flg[q[st]]=0;
                ed++;
                st++;
                q[ed-1]=a;
                flg[a]=1;
                printf("%d\t",a);
                for(j=st;j<ed;j++)
                {
                    printf("%d\t",q[j]);
                }
                printf("\n");
            }

        }
        else
        {
            m++;
            printf("%d\t",a);
            for(j=st;j<ed;j++)
            {
                printf("%d\t",q[j]);
            }
            printf("\n");
        }
    }
    printf("page Hit : %d\n",m);
    printf("page Fault : %d\n",n-m);
    printf("page Hit Ratio : %f\n",(float)m/n);
    printf("page Fault Ratio : %f\n",(float)(n-m)/n);
}
