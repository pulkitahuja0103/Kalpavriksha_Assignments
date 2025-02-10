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

void deleteNodesWhoseRightNodesAreGreater(Node** head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *prev = (*head);

    Node *temp = (*head);
    while (temp->next != NULL)
    {
        if (temp->data < temp->next->data)
        {
            Node *nodeToDelete = temp;
            if (prev == temp)
            {
                temp = temp->next;
                prev = temp;
                (*head) = temp;
                free(nodeToDelete);
            }
            else
            {
                Node *nodeToDelete = temp;
                prev->next=temp->next;
                temp = temp->next;
                free(nodeToDelete);
            }
        }
        else
        {   
            prev=temp;
            temp=temp->next;
        }
    }
}

int main()
{
    Node *list = getInput();
    traverseLinkedList(list);
    deleteNodesWhoseRightNodesAreGreater(&list);
    traverseLinkedList(list);

    return 0;
}