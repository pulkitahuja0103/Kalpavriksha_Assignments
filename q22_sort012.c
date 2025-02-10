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

void swapData(Node *zeros, Node *temp)
{
    int val = zeros->data;
    zeros->data = temp->data;
    temp->data = val;
}

void sort012(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *zeros = head;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            swapData(zeros, temp);
            zeros = zeros->next;
        }
        temp = temp->next;
    }
    Node *ones = zeros;
    head = zeros;
    while (head != NULL)
    {
        if (head->data == 1)
        {
            swapData(head, ones);
            ones = ones->next;
        }
        head = head->next;
    }
}

int main()
{
    Node *list = getInput();
    traverseLinkedList(list);
    sort012(list);
    traverseLinkedList(list);

    return 0;
}