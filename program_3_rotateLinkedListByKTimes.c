// leetcode Question Number-61
/*
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
*/

#include <stdio.h>
#include <stdlib.h>

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
void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void rotateLinkedListOneTime(Node **head)
{
    Node *temp = (*head);
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next->next = (*head);
    (*head) = temp->next;
    temp->next = NULL;
}
void getInputK(int *k)
{
    printf("Enter Number of Times you want to rotate Linked List elements:");
    scanf("%d", &(*k));
}
int main()
{

    Node *head = NULL;
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

    int k;
    getInputK(&k);

    printf("Initial Linked List:\n");
    printLinkedList(head);
    while (k != 0)
    {
        rotateLinkedListOneTime(&head);
        k--;
    }

    printf("\nLinked List After Rotation:\n");
    printLinkedList(head);

    return 0;
}