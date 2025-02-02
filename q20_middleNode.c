#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNewNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void addNodeAtEnd(Node **head, int val)
{
    Node *newNode = createNewNode(val);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }
    Node *temp = (*head);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *getInput()
{
    Node *head = NULL;

    printf("Enter Linked List (to stop enter -1)\n");
    while (1)
    {
        int value;
        printf("Enter Node Value:");
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        addNodeAtEnd(&head, value);
    }

    return head;
}

void traverseLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void getMiddleNode(Node* head){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    if(head->next==NULL){
        printf("Middle Node: %d",head->data);
        return;
    }

    Node* slow=head;
    Node* fast=head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    if(fast!=NULL){
        printf("Middle Node: %d",slow->next->data);
    }else{
        printf("Middle Node: %d",slow->data);
    }
}

int main()
{
    Node *list = getInput();
    traverseLinkedList(list);
    getMiddleNode(list);
   
    return 0;
}