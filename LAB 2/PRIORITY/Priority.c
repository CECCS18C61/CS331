#include<stdio.h>
void main()
 {
   int x,n,p[10],pp[10],pt[10],w[10],t[10],awt,atat,i;
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("\n Enter time priorities and burst time");
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d Priority: ",i+1);
      scanf("%d",&pt[i]);
      printf("Process no %d Burst Time: ",i+1);
      scanf("%d",&pp[i]);
      p[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pp[i]<pp[j])
       {
         x=pp[i];
         pp[i]=pp[j];
         pp[j]=x;
         x=pt[i];
         pt[i]=pt[j];
         pt[j]=x;
         x=p[i];
         p[i]=p[j];
         p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=pt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+pt[i];
   atat+=t[i];
 }
printf("\n Process \t Burst Time \t Waiting Time \tTurnaround Time\t Priority \n");
for(i=0;i<n;i++)
  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t    %d \n",p[i],pt[i],w[i],t[i],pp[i]);
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d",awt);
printf("\n Average Turn Around Time : %d \n",atat);
}
