#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 10

int stack[SIZE], top = -1;

void push(int value)
{
    if(top == SIZE-1)
        printf("\nStack is Full");
    else
    {
        top++;
        stack[top] = value;
        printf("\nInsertion success");
    }
}

void pop()
{
    if(top == -1)
        printf("\nStack is Empty ");
    else
    {
        printf("\nDeleted : %d", stack[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
        printf("\nStack is Empty");
    else
    {
        int i;
        printf("\nStack elements are:\n");
        for(i=top; i>=0; i--)
          printf("%d\n",stack[i]);
    }
}

void main()
{
    int value, choice;
    while(1)
    {
        printf("\n 1.Push\t 2.Pop\t 3.Display\t 4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nWrong Choice!!!");
            
        }
        
    }
}


