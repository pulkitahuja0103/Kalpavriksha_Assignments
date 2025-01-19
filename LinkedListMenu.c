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

int getLengthOfLinkedList(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int length = 1;
    while (head->next != NULL)
    {
        head = head->next;
        length++;
    }

    return length;
}

int getValueForNewNode()
{
    int val;
    printf("Enter NewNode value\n");
    scanf("%d", &val);
    return val;
}

void insertAtBeginning(Node **head)
{
    int val = getValueForNewNode();
    Node *newNode = createNode(val);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }

    newNode->next = (*head);
    (*head) = newNode;
}

void insertAtEnd(Node **head)
{
    int val = getValueForNewNode();
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

int getIndexForNewNode()
{
    int index;
    printf("Enter NewNode index\n");
    scanf("%d", &index);
    if (index < 1)
    {
        printf("Invalid");
        exit(0);
    }
    return index;
}

void insertAtPosition(Node **head)
{
    int index = getIndexForNewNode();
    if (index > (getLengthOfLinkedList((*head)) + 1))
    {
        printf("Invalid");
        exit(0);
    }
    int val = getValueForNewNode();
    Node *newNode = createNode(val);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }

    if (index == 1)
    {
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }

    // index>1
    Node *temp = (*head);
    int countIndex = 1;
    while (countIndex != (index - 1))
    {
        temp = temp->next;
        countIndex++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty");
        return;
    }
    printf("Current Linked List is:\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void updateAtPosition(Node **head)
{
    if ((*head) == NULL)
    {
        printf("Invalid");
        exit(0);
    }
    int index = getIndexForNewNode();
    if (index > (getLengthOfLinkedList((*head)) + 1))
    {
        printf("Invalid");
        exit(0);
    }

    int val = getValueForNewNode();
    int countIndex = 1;

    Node *temp = (*head);
    while ((countIndex) != index && temp != NULL)
    {
        temp = temp->next;
        countIndex++;
    }

    temp->data = val;
}

void deleteAtBeginning(Node **head)
{
    if ((*head) == NULL)
    {
        printf("Invalid");
        exit(0);
    }
    Node *temp = (*head);
    (*head) = (*head)->next;

    temp->next = NULL;
    free(temp);
}

void deleteAtEnd(Node **head)
{
    if ((*head) == NULL)
    {
        printf("Invalid");
        exit(0);
    }

    if ((*head)->next == NULL)
    {
        (*head) = NULL;
        return;
    }

    Node *temp = (*head);
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *nodeToDelete = temp->next;
    temp->next = NULL;

    nodeToDelete->next = NULL;
    free(nodeToDelete);
}

void deleteAtPosition(Node **head)
{
    if ((*head) == NULL)
    {
        printf("Invalid");
        exit(0);
    }

    int index = getIndexForNewNode();
    if (index > (getLengthOfLinkedList((*head))))
    {
        printf("Invalid");
        exit(0);
    }
    if (index == 1)
    {
        Node *nodeToDelete = (*head);
        (*head) = (*head)->next;

        nodeToDelete = NULL;
        free(nodeToDelete);
        return;
    }
    int countIndex = 1;
    Node *temp = (*head);
    while ((countIndex) != (index - 1))
    {
        temp = temp->next;
        countIndex++;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    nodeToDelete->next = NULL;
    free(nodeToDelete);
}
void getNumberOfOperations(int *numberOfOperations)
{
    printf("Enter Number of Operations\n");
    scanf("%d", &(*numberOfOperations));
}

void getChoice(int *choice)
{

    printf("1- Add a node at the end.\n");
    printf("2- Add a node at the beginning.\n");
    printf("3- Add a node at the specified position.\n");
    printf("4- Displays all elements in the list.\n");
    printf("5- Update the value at the specified position.\n");
    printf("6- Delete the first node.\n");
    printf("7- Delete the last node.\n");
    printf("8- Delete the node at the specified position.\n");
    printf("0- Exit.\n");
    printf("Enter your choice from above listed choices:\n");
    scanf("%d", &(*choice));
}

int main()
{

    int numberOfOperations;
    getNumberOfOperations(&numberOfOperations);

    Node *head = NULL;

    while (numberOfOperations != 0)
    {
        int choice;
        getChoice(&choice);

        switch (choice)
        {
        case 1:
            insertAtEnd(&head);
            numberOfOperations--;
            break;
        case 2:
            insertAtBeginning(&head);
            numberOfOperations--;
            break;
        case 3:
            insertAtPosition(&head);
            numberOfOperations--;
            break;
        case 4:
            display(head);
            numberOfOperations--;
            break;
        case 5:
            updateAtPosition(&head);
            numberOfOperations--;
            break;
        case 6:
            deleteAtBeginning(&head);
            numberOfOperations--;
            break;
        case 7:
            deleteAtEnd(&head);
            numberOfOperations--;
            break;
        case 8:
            deleteAtPosition(&head);
            numberOfOperations--;
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid");
            exit(0);
        }
    }

    return 0;
}