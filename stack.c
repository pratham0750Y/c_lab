#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 50
int stack[max_size],top=-1;
void push(int n)
{
    if(top>max_size-1)
        printf("Stack overflow\n");
    else
        stack[++top]=n;
}

void pop()
{
    if(top==-1)
        printf("stack is empty\n\n");
    else
        printf("%d was poped\n\n",stack[top--]);
}

void display()
{
    if(top==-1)
        printf("Stack is empty\n");
    else
        printf("printing stack:");
        for(int i=top;i>=0;i--)
        printf("%d ",stack[i]);

}
void main()
{
    while(1)
        {
            printf("1.push\n2.pop\n3.display\n4. to quit\nenter your choice:");
            int choice;
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                printf("enter the number to push:");
                int n;
                scanf("%d",&n);
                printf("pushing %d\n\n",n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                printf("\n\n");
                break;
            case 4:
                printf("quitting program\n");
                exit(0);
            default:
                printf("plese enter a valid number\n");
            }
        }
}
