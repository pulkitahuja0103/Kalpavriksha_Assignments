
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNewNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
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

Node* solve(Node* head) {
     if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* temp=head;
    head=head->next;
    Node* forward=head->next;

    head->next=temp;
    temp->next=solve(forward);

    return head;
    
}
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    addNodeAtEnd(&head,1);
    addNodeAtEnd(&head,2);
    addNodeAtEnd(&head,3);
    addNodeAtEnd(&head,4);

    head=solve(head);
    printLinkedList(head);
}