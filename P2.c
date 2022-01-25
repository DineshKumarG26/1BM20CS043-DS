#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
}*rear=NULL;


void insert(int item)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=item;
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }

        if( isEmpty() ) 
        {
                rear=tmp;
                tmp->link=rear;
        }
        else
        {
                tmp->link=rear->link;
                rear->link=tmp;
                rear=tmp;
        }
}

int del()
{
        int item;
        struct node *tmp;
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        if(rear->link==rear)  
        {
                tmp=rear;
                rear=NULL;
        }
        else
        {
                tmp=rear->link;
                rear->link=rear->link->link;
        }
        item=tmp->info;
        free(tmp);
        return item;
}

int isEmpty()
{
        if( rear == NULL )
            return 1;
        else
            return 0;
}


void display()
{
        struct node *p;
        if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
        printf("\nQueue is :\n");
        p=rear->link;
        do
        {
            printf("%d ",p->info);
            p=p->link;
        }while(p!=rear->link);
        printf("\n");
}

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert\t 2.Delete\t 3.Display\t 4.Exit");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                 case 1:printf("\nEnter the element for insertion : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                 case 2:printf("\nDeleted element is %d\n",del());
                        break;
                 case 3:display();
                        break;
                 case 4:exit(0);
                        break;
                 default:
                        printf("\nWrong choice !!!");
                }
        }
}

