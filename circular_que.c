#include <stdio.h>
#define size 10

int que[size];
int rear=-1,front=-1;

void rearinsert(int n)
{
    if(front==(rear+1)%size)
        printf("queue overflow\n");
    else
    {
        que[++rear%size]=n;
        rear%=size;
    }
}

void frontinsert(int n)
{
    if(front==(rear+1)%size)
        printf("que overflow\n");
    else
        if(front==0)
            front=size-1;
        else
            front-=1;
        que[front]=n;
}

void reardeque()
{
    if(rear==front)
        printf("queue underflow\n");
    else
        printf("%d is removed\n",que[(rear--+size)%size]);rear%=size;
    if(rear==front)
        rear=front=-1;
}

void frontdeque()
{
    if(rear==front)
        printf("que underflow\n");
    else
        printf("%d is removed\n",que[++front%size]);front%=size;
    if(rear==front)
        rear=front=-1;
}

void display()
{
    if(rear==front)
        printf("queue is empty");

    for(int i=front;(i%size)!=rear;i++)
        printf("%d,",que[i%size]);

    printf("\n");
}

void main()
{
    rearinsert(10);
    rearinsert(15);
    rearinsert(20);
    rearinsert(25);
    rearinsert(30);
    rearinsert(35);
    reardeque();
    frontdeque();
    display();
}
