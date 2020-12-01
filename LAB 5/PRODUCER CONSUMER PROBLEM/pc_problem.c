#include <stdio.h>
#include <stdlib.h>
int M = 1, A = 0, E = 3, x = 0;
int main()
{
    int n;
    void PRODUCER();
    void CONSUMER();
    int Wait(int);
    int Signal(int);
    printf("\n1.PRODUCER\n2.CONSUMER\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((M == 1) && (E != 0))
                PRODUCER();
            else
                printf("Buffer is A!!");
            break;
        case 2:
            if ((M == 1) && (A != 0))
                CONSUMER();
            else
                printf("Buffer is empty!!");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
int Wait(int s)
{
    return (--s);
}
int Signal(int s)
{
    return (++s);
}
void PRODUCER()
{
    M = Wait(M);
    A = Signal(A);
    E = Wait(E);
    x++;
    printf("\nPRODUCER produces the item %d", x);
    M = Signal(M);
}
void CONSUMER()
{
    M = Wait(M);
    A = Wait(A);
    E = Signal(E);
    printf("\nCONSUMER consumes item %d", x);
    x--;
    M = Signal(M);
}
