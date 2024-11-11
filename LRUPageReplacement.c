#include<stdio.h>


void main()
{
    int n,j,f,st=-1,ed=-1,m=0,lr,lrv,temp;
    printf("Enter no. of pages ");
    scanf("%d",&n);
    printf("Enter no. of Frames ");
    scanf("%d",&f);

    printf("Enter the pages ");
    int p[n],i,q[f],flg[50],a,k=0,s[19]={3,2,1,3,4,1,6,2,4,3,4,2,1,4,5,2,1,3,4};
    n=19;
    for(i=0;i<n;i++)
    {
        p[i]=s[i];
    }
    printf("\n");
    
    
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
            if(st==-1) //First No. into frame   
            {
                st=0;
                ed=1;
                lr=0;
                lrv=a;
                q[ed-1]=a;
                printf("%d\t%d\t%d\n",a,q[st],lrv);
                flg[a]=1;
            }
            else if(ed-st<f) // The no.s getting into free space of Frame
            {
                ed++;
                q[ed-1]=a;
                flg[a]=1;
                printf("%d\t",a);
                for(j=st;j<ed;j++)
                {
                    printf("%d\t",q[j]);
                }
                printf("%d\n",lrv);
            }
            else
            {
                lr++;
                lrv=q[lr];
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
                 printf("%d\n",lrv);
            }

        }
        else
        {
            m++;
            temp=p[i-1];
            printf("%d\t",a);
            for(j=st;j<ed;j++)
            {
                printf("%d\t",q[j]);
            }
            
            
            if((temp!=a) && (lrv==a))
            {
                //printf("\nYES lrv was =%d\n",lrv);
                lr++;
                st++;
                lrv=p[lr];
                q[ed]=a;
                ed++;
                //printf("%d=new lrv\n",lrv);
            }
            printf("Hit counted %d\n",lrv);
            
        }
    }
    printf("page Hit : %d\n",m);
    printf("page Fault : %d\n",n-m);
    printf("page Hit Ratio : %f\n",(float)m/n);
    printf("page Fault Ratio : %f\n",(float)(n-m)/n);
}
/*
Only Small changes w.r.t FIFO
as we introduce 2 new variables lr & lrv to store values of the index of the least recently used values's index and actual numerical value
temp is also introduced to avoid updating lru's value unnessarily

changes are indicated as "//updates"

Refer this youtube video to understand a this Example : https://www.youtube.com/watch?v=u23ROrlSK_g
*/
