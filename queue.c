#include <stdio.h>
#define size 10
int que[size];
int front=-1,rear=-1;
void rearinsert(int n)
{
 if(rear==size-1)
        printf("queue overflow\n");
 else
    que[++rear]=n;
}

void frontinsert(int n)
{
     if(front==-1)
        printf("queue is full\n");
    else
        que[front--]=n;
}

void reardeque()
{
    if(rear==-1)
        printf("queue underflow\n");
    else
        printf("%d is removed\n",que[rear--]);
    if(rear==front)
        rear==front==-1;
}
void frontdeque()
{
    if(front!=rear)
        printf("%d is removed\n",que[++front]);
    else
        printf("queue underflow\n");
}

void display()
{
    if(front==rear)
        printf("queue is empty");
    else
        for(int i=front+1;i<=rear;i++)
            printf("%d,",que[i]);
    printf("\n");
}
void main()
{
    int c,n;
    while(1){
            printf("\npress 1 for front enque\n");
            printf("press 2 for rear  enque\n");
            printf("press 3 for front deque\n");
            printf("press 4 for rear  deque\n");
            printf("press 5 to close program\n");
            printf("enter your choice:");
            scanf("%d",&c);

            switch(c)
            {
            case 1:
                printf("enter the number:");
                scanf("%d",&n);
                frontinsert(n);
                break;
            case 2:
                printf("enter the number:");
                scanf("%d",&n);
                rearinsert(n);
                break;
            case 3:
                frontdeque();
                break;
            case 4:
                reardeque();
                break;
            default:
                printf("enter a valid choice");
            }

            if(c==5)
                break;
    }
}
