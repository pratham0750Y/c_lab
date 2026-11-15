#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

typedef struct node node;

node* getnode(int val)
{
	node *f=malloc(sizeof(node));
	f->val=val;
	f->next=NULL;
	return f;
}

void insertfirst(node **f,int val)
{
	node *temp=getnode(val);
	temp->next=*f;
	*f=temp;
}

void insertlast(node **f,int val)
{
	if(*f==NULL){
		*f=getnode(val);
	}else{
		node* temp=*f;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=getnode(val);
	}
}

void insert(node *f,int pos,int val)
{
	node *temp=f;
	for(int i=0;i<pos-1;i++){
		if(temp==NULL||temp->next==NULL){
			printf("The linked list doesn't have enough elements\n");
			return;
		}
		temp=temp->next;
	}
	node *temp1=getnode(val);
	temp1->next=temp->next;
	temp->next=temp1;
}

void display(node *f)
{
	node *temp=f;
	if(f==NULL){
		printf("linked list is empty\n");
	}else{
		while(temp!=NULL){
			printf("%d -> ",temp->val);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}

void deletefirst(node **n)
{
	if(*n==NULL){
		printf("linked list is empty\n");
	}else{
		node *temp=*n;
		*n=(*n)->next;
		free(temp);
	}
}

void deletelast(node **f)
{
	if(*f==NULL){
		printf("linked list is empty\n");
		return;
	}
	if((*f)->next==NULL){
		free(*f);
		*f=NULL;
		return;
	}
	node *temp=*f;
	while(temp->next->next!=NULL)
		temp=temp->next;
	free(temp->next);
	temp->next=NULL;
}

void deletenode(node *f,int pos)
{
	node *temp=f;
	for(int i=0;i<pos-1;i++){
		if(temp==NULL||temp->next==NULL){
			printf("not enough elements in linked list\n");
			return;
		}
		temp=temp->next;
	}
	node *temp1=temp->next;
	if(temp1!=NULL){
		temp->next=temp1->next;
		free(temp1);
	}
}

struct node *sortList(struct node *head) {
    struct node *i,*j;
    int temp;

    for (i=head;i!=NULL;i=i->next) {
        for (j=i->next;j!=NULL;j=j->next) {
            if (i->val>j->val) {
                temp=i->val;
                i->val=j->val;
                j->val=temp;
            }
        }
    }
    return head;
}

node *reverse(node *head) {
    node *prev = NULL,*current = head,*next = NULL;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

node *concatenate(node *head1,node *head2) {
    if(head1==NULL)
        return head2;
    node *temp=head1;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=head2;
    return head1;
}

int main(){
    node *head1=getnode(10);
    insertlast(&head1,15);
    insertlast(&head1,20);
    insertlast(&head1,23);
    insertlast(&head1,30);
    insertlast(&head1,35);

    node *head2=getnode(70);
    insertlast(&head2,80);
    insertlast(&head2,90);
    insertlast(&head2,100);
    insertlast(&head2,110);
    insertlast(&head2,120);

    int choice, val, n, i;
    printf("1. Sort First List\n");
    printf("2. Reverse First List\n");
    printf("3. Concatenate Two Lists\n");
    printf("4. Display List");
    printf("5. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 4:
                display(head1);
                break;

            case 1:
                head1=sortList(head1);
                printf("Sorted List: ");
                display(head1);
                break;

            case 2:
                head1=reverse(head1);
                printf("Reversed List: ");
                display(head1);
                break;

            case 3:
                head1=concatenate(head1, head2);
                head2=NULL;
                printf("Concatenated List: ");
                display(head1);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}


