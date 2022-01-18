#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* head = NULL;

void append_left()
{
    int value;
    printf("Enter value to append: ");
    scanf("%d", &value);
    
    struct Node* new_node = (struct Node*) malloc(sizeof(int));
    new_node->left = NULL;
    new_node->data = value;

    if (head == NULL) 
    {
        head = new_node;
        new_node->right = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    temp->left = new_node;
    new_node->right = temp;
}


void delete_value()
{
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    while (head != NULL && head->data == value)
    {
        struct Node* temp = head;
        head = head->left;
        free(temp);
    }
    if (head == NULL)
    {
        return;
    }

    struct Node* temp = head;
    while (temp->left != NULL) 
    {
        if (temp->left->data == value)
        {
            if (temp->left->left == NULL)
            {
                free(temp->left);
                temp->left = NULL;
            }
            else
            {
                struct Node* delete_node = temp->left;
                temp->left = delete_node->left;
                delete_node->left->right = temp;
                free(delete_node);
            }
        }
        else
        {
            temp = temp->left;
        }
    }
}

void display_nodes() 
{
    if (head == NULL)
    {
        printf("List Empty.\n");
        return;
    }

    printf("Elements from right to left:");
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->left;
    }
    printf("\n");
}


int main() 
{

    int choice;
    while(1)
    {
        printf("\ 1. Append a new node to the left\t 2. Delete nodes with a specific value\t 3. Display all nodes\t 4. Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:append_left();
                   break;
            case 2:delete_value();
                   break;
            case 3:display_nodes();
                   break;
            case 4:exit(0);
                   break;
            default:
                printf("Wrong Choice!!!\n");
        }
    } 
    return 0;
}