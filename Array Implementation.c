#include<stdio.h>
#define MAX 50

int queue_array[MAX];
int rear=-1;
int front=-1;

display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Queue is: \n");
        for(i=front; i<=rear; i++)
            printf("%d",queue_array[i]);
            printf("\n");
    }
}

insert()
{
    int item;
    if(rear==MAX-1)
    {
        printf("Queue Overflow \n");
    }
    else
    {
        if(front==-1)
            front=0;
            printf("Insert the element in the queue: ");
            scanf("%d",&item);
            rear=rear+1;
            queue_array[rear]=item;
    }
}
delete()
{
    if(front==-1 || front>rear)
    {
        printf("queue underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from the queue is:%d\n",queue_array[front]);
        front=front+1;

    }
}

int main()
{

    int choice;
    while(1)
    {
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}


