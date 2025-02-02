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
        (*head)->next = (*head);
        return;
    }
    Node *temp = (*head);
    while (temp->next != (*head))
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = (*head);
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

void traverseCircularLinkedList(Node *head)
{
    Node *temp = head;
    do
    {
        printf("%d ", head->data);
        head = head->next;
    } while (head != temp);
    printf("%d ", temp->data);

    printf("\n");
}

Node *getMiddleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void splitListInto2Halfs(Node *head)
{
    if (head == head->next)
    {
        printf("Not Possible");
        return;
    }
    Node *middleNode = getMiddleNode(head);
    Node *list2 = middleNode->next;
    middleNode->next = head;
    traverseCircularLinkedList(head);

    Node *temp = list2;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = list2;
    traverseCircularLinkedList(list2);
}

int main()
{
    Node *list = getInput();
    traverseCircularLinkedList(list);
    splitListInto2Halfs(list);

    return 0;
}