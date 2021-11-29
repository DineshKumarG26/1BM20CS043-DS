#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int items[SIZE];
int front=-1, rear=-1;

int isFull()
{
    if((front==rear+1) || (front==0 && rear==SIZE-1))
        return 1;
    return 0;
}
int isEmpty()
{
    if(front==-1)
        return 1;
    return 0;
}

void  enque(int element)
{
    if(isFull())
        printf("Queue is full. \n");
    else
    {
        if(front==-1)
            front =0;
        rear=(rear+1) % SIZE;
        items[rear] = element;
    }
}

int deque()
{
    int element;
    if(isEmpty())
    {
        printf("Queue is Empty. \n");
        return -1;
    }
    else
    {
        element = items[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front+1)%SIZE;
        printf("Deleted item : %d", element);     
    }
}

void display()
{
    int i;
    if(isEmpty())
        printf(" Empty queue");
    else 
        printf("\nItems : ");
        for(i=front; i!=rear; i=(i+1)%SIZE)
             printf("%d \t", items[i]);
        printf("%d", items[i]);
                
}

int main()
{
    int option, item;
    while(1)
    {
        printf("\n1.Insert to queue.\n2.Delete from queue\n3.Display the content\n4.Exit");
        printf("\nEnter the option: ");
        scanf("%d",&option);
        switch(option)
        {
             case 1:printf("\nEnter the number: ");
                     scanf("%d",&item);
                    enque(item);
                    break;
            case 2:deque();
                    break;
            case 3:display();
                    break;
             case 4:exit(0);
        }
    }
    return 0;
}