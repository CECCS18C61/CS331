#include <stdio.h>

int n, m;
void read(int Alloc[][50], int Max[][50], int Avail[50], int Need[][50], int n, int m);
void display(int temp[][50], int n, int m);
int safety(int Alloc[][50], int Avail[50], int Need[][50], int n, int m);

int main()
{
    int Alloc[50][50], Max[50][50], Avail[50], Need[50][50];

    printf("Deadlock avoidancs using Banker’s Algorithm\n");
    read(Alloc, Max, Avail, Need, n, m);
    return 0;
}

//BANKER'S ALGORITHM
void read(int Alloc[][50], int Max[][50], int Avail[50], int Need[][50], int n, int m) {

    int i, j;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    printf("Enter total number of resources: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Allocation Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &Alloc[i][j]);
        }
        printf("Maximum Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("\nAvailable System Resources: ");
    for (i = 0; i < m; ++i) {
        scanf("%d", &Avail[i]);
    }
      for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }

    printf("\nProcess\tCurrently-Allocated-Resources\n");
    display(Alloc, n, m);
    printf("\nProcess\tMaximum-Resources\n");
    display(Max, n, m);
    printf("\nProcess\tPossibly-Needed-Resources\n");
    display(Need, n, m);

    safety(Alloc, Avail, Need, n, m);
}

//SAFETY ALGORITHM

/* AVAILABLE >= NEED, THEN AVAILABLE += ALLOCATED */

int safety(int Alloc[][50], int Avail[50], int Need[][50], int n, int m)  {

    int i, j, k, index = 0;
    int isDone[50], sequence[50], count = 0;

    for (i = 0; i < n; ++i) {
        isDone[i] = 0;
    }

    for (k = 0; k < n; ++k) {

        for (i = 0; i < n; ++i)
        {
            if (isDone[i] == 0) {
                for (j = 0; j < m; ++j)
                {
                    if (Avail[j] >= Need[i][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                if (j == m) {
                    for (j = 0; j < m; ++j) {
                        Avail[j] += Alloc[i][j];
                    }
                    count++;
                    isDone[i] = 1;
                    sequence[count - 1] = i + 1;
                }
            }
        }
        if (count == n) {
            printf("The safe sequence is\n");
            int i;
            for (i = 0; i < n; ++i) {
                printf("P%d ", sequence[i]);
            }
            printf("\n");
            break;
        }
            }

    if (count != n) {
        printf("\nDeadlock has occured.\n");
    }
}

void display(int temp[][50], int n, int m)
{
    int i, j;
    for (i = 0; i < n; ++i) {
        printf("P%d", i + 1);
        for (j = 0; j < m; ++j) {
            printf("\t%d", temp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
