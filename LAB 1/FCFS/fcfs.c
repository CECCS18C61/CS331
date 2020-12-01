#include <stdio.h>
void main()
{
  int a, bt[50], wt[50], tt[50], awt=0, att=0,i,j;
  printf("enter total number of process(max 50) ");
  scanf("%d", &a );
  printf("\nEnter process burst time \n");
  for(i = 0; i < a; i++)
  {
    printf("Process %d- ",i+1);
    scanf("%d", &bt[i]);
  }
  wt[0]=0; //waiting time of the 1st process is 0
  for(i=0; i<a; i++)
  {
    wt[i]=0;
    for (j = 0; j < i; j++)
    {
      wt[i]+=bt[j];
    }
  }
  printf("\nProcess \t Burst time \t waiting time \t turnaround time");
  for(i = 0; i < a; i++)
  {
    tt[i]=bt[i]+wt[i];
    awt+=wt[i];
    att+=tt[i];
    printf("\nP[%d] \t %d \t %d \t %d", i+1, bt[i], wt[i], tt[i]);
  }
  awt/=i;
  att/=i;
  printf("\n Average Waiting time= %d", awt);
  printf("\n Average Turnaround time= %d\n", att);
}
