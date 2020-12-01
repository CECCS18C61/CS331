#include<stdio.h>
#include<stdlib.h>

int main() {
    int DQ[20], n, i, ST=0, d;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {
        scanf("%d",&DQ[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &DQ[0]);
    printf("\nMovement of Cylinders\n");
    for(i=0;i<n;i++) {
        d= abs(DQ[i+1] - DQ[i]);
        ST+= d;
        printf("Move from %d to %d with seek time %d\n", DQ[i], DQ[i+1], d);
    }
    printf("\nTotal Seek Time: %d", ST);
    printf("\nAverage Seek Time = %f",(float) ST/n);
    printf("\n");
    return 0;
}
