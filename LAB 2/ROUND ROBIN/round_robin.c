#include<stdio.h>
int main()
{
      int i, l, t = 0, a, c = 0, TQ;
      int wt = 0, tt = 0, at[10], bt[10], temp[10];
      float awt, att;
      printf("\nEnter the Number of Processes: ");
      scanf("%d", &l);
      a = l;
      for(i = 0; i < l; i++)
      {
            printf("\nEnter Details of Process[%d]", i + 1);
            printf("\nArrival Time: ");
            scanf("%d", &at[i]);
            printf("Burst Time: ");
            scanf("%d", &bt[i]);
            temp[i] = bt[i];
      }
      printf("\nEnter Time Quantum: ");
      scanf("%d", &TQ);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time");
      for(t = 0, i = 0; a != 0;)
      {
            if(temp[i] <= TQ && temp[i] > 0)
            {
                  t = t + temp[i];
                  temp[i] = 0;
                  c = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - TQ;
                  t = t + TQ;
            }
            if(temp[i] == 0 && c == 1)
            {
                  a--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], t - at[i], t - at[i] - bt[i]);
                  wt = wt + t - at[i] - bt[i];
                  tt = tt + t - at[i];
                  c = 0;
            }
            if(i == l - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= t)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      awt = wt * 1.0 / l;
      att = tt * 1.0 / l;
      printf("\n\nAverage Waiting Time: %f", awt);
      printf("\nAvg Turnaround Time: %f\n", att);
      return 0;
}
