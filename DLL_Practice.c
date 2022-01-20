#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *prev,*next;
}nod;
nod *head=NULL;
void push(int val){
    nod *newnode;
    newnode=(nod *)malloc(sizeof(nod));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        newnode->prev=NULL;
        head=newnode;
    }
}
void append(int val){
    nod *newnode,*temp;
    newnode=(nod *)malloc(sizeof(nod));
    newnode->data=val;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
    }
}
void atpos(int val,int pos){
    nod *newnode,*temp;
    newnode=(nod *)malloc(sizeof(nod));
    newnode->data=val;
    temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
}
void delfront(){
    nod *temp=head;
    if(head==NULL){
        printf("The list is empty\n");
    }
    else if(temp->next==NULL){
        printf("Element deleted is %d \n",head->data);
        free(head);
        head=NULL;
    }
    else{
        head=head->next;
        head->prev=NULL;
        printf("Element deleted is %d \n",temp->data);
        free(temp);
    }
}
void delrear(){
    nod *temp=head;
    if(head==NULL){
        printf("The list is empty\n");
    }
    else if(temp->next==NULL){
        printf("Element deleted is %d \n",head->data);
        free(head);
        head=NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("Element deleted is %d \n",temp->data);
        temp->prev->next=NULL;
        free(temp);
    }
}
void del(int pos){
    nod *temp=head;
    if(head->next==NULL){
        printf("Element deleted is %d\n",temp->data);
        free(head);
        head=NULL;
    }
    else{
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        printf("Element deleted is %d\n",temp->data);
        free(temp);
    }
}
int len(){
    nod *temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void display(){
    nod *temp;
    int i=1;
    temp=head;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        printf("\n");
        i++;
        temp=temp->next;
    }
}
int search(int pos){
    nod *temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    return temp->data;
}
int main()
{
    int n,cho,po,lent;
printf("1.Insert at begin\n2.At end\n3.At pos\n4.Display\n5.Delete at front\n6.Delete at end\n7.Delete at a position\n8.Search\n9.Exit\n");
    printf("Enter choice :");
    scanf("%d",&cho);
    while(cho!=9){
        switch(cho){
            case 1:
                printf("Enter number : ");
                scanf("%d",&n);
                push(n);
                break;
            case 2:
                printf("Enter number : ");
                scanf("%d",&n);
                append(n);
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&po);
                printf("Enter number : ");
                scanf("%d",&n);
                lent=len();
                if(po<1 || po>lent){
                    printf("Invalid position \n");
                }
                else if(po==1){
                    push(n);
                }
                else if(po==lent){
                    append(n);
                }
                else{
                    atpos(n,po);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                delfront();
                break;
            case 6:
                delrear();
                break;
            case 7:
                printf("Enter the position : ");
                scanf("%d",&po);
                n=len();
                if(po<=0 || po>n){
                    printf("Invalid position \n");
                }
                else if(po==n){
                    delrear();
                }
                else{
                    del(po);
                }
                break;
            case 8:
                printf("Enter the position : ");
                scanf("%d",&po);
                n=len();
                if(po<=0 || po>n){
                    printf("Invalid position \n");
                }
                else{
                    printf("Element at location %d is %d\n",po,search(po));
                }
                break;
            case 9:
                exit(0);
        }
        printf("Enter choice :");
        scanf("%d",&cho);
    }
return 0;
}
