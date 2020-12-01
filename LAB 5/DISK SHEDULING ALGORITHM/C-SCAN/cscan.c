#include<stdio.h>
#include<stdlib.h>

void Cscan(int A[50], int n, int start);
void sort(int A[50], int n);

int main() {
    int DQ[50], n, start, i, max;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {
        scanf("%d",&DQ[i]);
    }
    printf("Enter the initial head pition: ");
    scanf("%d", &start);
    DQ[0] = start;
    ++n;
    sort(DQ, n);
    Cscan(DQ, n, start);

    return 0;
}

void Cscan(int A[50], int n, int start) {
    int i, p, d, ST=0, C;

    for(i=0;i<n;i++) {
        if(A[i]==start) {
            p=i;
            break;
        }
    }

    printf("\nMovement of Cylinders\n");
    for(i=p;i<n-1;i++) {
        d = abs(A[i+1] - A[i]);
        ST+= d;
        printf("Move from %d to %d with seek time %d\n", A[i], A[i+1], d);
    }
    C=0;
    printf("Move from %d to %d with seek time %d\n", A[i], C, 0);
    for(i=0;i<p;i++) {
        d = abs(A[i] - C);
        ST+= d;
        printf("Move from %d to %d with seek time %d\n", C, A[i], d);
        C = A[i];
    }
    printf("\nTotal Seek Time: %d", ST);

    printf("\nAverage Seek Time = %f",(float) ST/(n-1));
    printf("\n");
}

void sort(int A[50], int n) {
    int i, j, tmp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1-i;j++) {
            if(A[j]>A[j+1]) {
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
