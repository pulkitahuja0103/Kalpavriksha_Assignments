#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int getValueOfK()
{
    int k;
    printf("Enter Value of k (Groups of linked list to be reversed):");
    scanf("%d", &k);
    return k;
}

int getLength(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int getLastKthNodeValue(Node *head, int k)
{
    int size = getLength(head);
    if (k > size || k == 0 || k < 0)
    {
        return INT_MIN;
    }
    int kFromStart = size - k;

    while (kFromStart > 0 && head != NULL)
    {
        head = head->next;
        kFromStart--;
    }

    return head->data;
}

int main()
{
    Node *list = getInput();
    traverseLinkedList(list);

    int k = getValueOfK();
    int value = getLastKthNodeValue(list, k);

    if (value != INT_MIN)
    {
        printf("kth node from last:%d\n", value);
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}