#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
        if (value == 1 || value == 0)
        {
            addNodeAtEnd(&head, value);
        }
        else
        {
            exit(0);
        }
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

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;

    while (head != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}

int getDecimalOfBinaryForm(Node *head)
{
    head = reverseLinkedList(head);

    int decimal = 0;
    int powerValue = 0;
    while (head != NULL)
    {
        decimal = decimal + (head->data * pow(2, powerValue));
        powerValue++;
        head = head->next;
    }

    return decimal;
}

void getOutput(int answer)
{
    printf("Decimal for of above binary number is:%d ", answer);
}
int main()
{
    Node *list = getInput();
    traverseLinkedList(list);

    int answer = getDecimalOfBinaryForm(list);
    getOutput(answer);

    return 0;
}