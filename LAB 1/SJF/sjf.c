#include<stdio.h>
int main()
{
    int bt[50],p[50],wt[50],tt[50],i,j,n,c=0,a,b;
    float awt,att;
    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("process%d- ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }     //sorting of burst times
    for(i=0;i<n;i++)
    {
        a=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[a])
                a=j;
        }
        b=bt[i];
        bt[i]=bt[a];
        bt[a]=b;
        b=p[i];
        p[i]=p[a];
        p[a]=b;
    }
   wt[0]=0;
   for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            {wt[i]+=bt[j];}
        c+=wt[i];
    }
    awt=(float)c/n;
    c=0;
    printf("nProcesst \t Burst Time \t Waiting Time \t Turnaround Time");
    for(i=0;i<n;i++)
    {
        tt[i]=bt[i]+wt[i];
        c+=tt[i];
        printf("\np[%d] \t %d\t %d \t %d",p[i],bt[i],wt[i],tt[i]);
    }
    att=(float)c/n;
    printf("\nAverage Waiting Time=%f",awt);
    printf("\nAverage Turnaround Time=%f \n",att);
}
