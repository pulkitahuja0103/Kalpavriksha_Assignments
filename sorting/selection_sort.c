#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void addNodeAtEnd(Node **head, int val)
{
    Node *newNode = createNode(val);
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

void traverseLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty");
        exit(0);
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

Node *getInput()
{
    int numberOfNodes;
    printf("Enter Number of Nodes in Linked List: ");
    scanf("%d", &numberOfNodes);
    if (numberOfNodes <= 0)
    {
        if (numberOfNodes == 0)
        {
            printf("Linked List is empty");
            exit(0);
        }
        printf("Invalid Size");
        exit(0);
    }

    Node *head = NULL;
    for (int itr1 = 0; itr1 < numberOfNodes; itr1++)
    {
        int value;
        printf("Enter value for %d node: ", itr1 + 1);
        scanf("%d", &value);
        addNodeAtEnd(&head, value);
    }
    printf("Un-Sorted Linked List:\n");
    traverseLinkedList(head);
    if (numberOfNodes == 1)
    {
        traverseLinkedList(head);
        exit(0);
    }

    return head;
}

void swapValues(Node *current, Node *smallest)
{
    int temporaryValue = current->data;
    current->data = smallest->data;
    smallest->data = temporaryValue;
}
void selectionSort(Node **head)
{
    Node *current = (*head);

    while (current->next != NULL)
    {
        Node *smallest = current;
        Node *temp = smallest;
        while (temp != NULL)
        {
            if (temp->data < smallest->data)
            {
                smallest = temp;
            }
            temp = temp->next;
        }
        swapValues(smallest, current);
        current = current->next;
    }
}
void getOutput(Node *head)
{
    printf("\nSorted Linked List:\n");
    traverseLinkedList(head);
}
int main()
{
    Node *head = getInput();
    selectionSort(&head);
    getOutput(head);
    return 0;
}