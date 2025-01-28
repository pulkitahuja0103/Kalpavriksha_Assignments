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
void traverseLinkedList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node *getInput()
{
    int numberOfNodes;
    printf("Enter Numbers of Node to be created: ");
    scanf("%d", &numberOfNodes);
    if (numberOfNodes <= 0)
    {
        if(numberOfNodes==0){
            printf("Linked List is empty");
            exit(0);
        }
        printf("Invalid Size");
        exit(0);
    }
    Node *head = NULL;
    for (int itr1 = 0; itr1 < numberOfNodes; itr1++)
    {
        int val;
        printf("Enter Value for %d node: ", itr1 + 1);
        scanf("%d", &val);
        addNodeAtEnd(&head, val);
    }
    printf("Un-Sorted Linked List:\n");
    traverseLinkedList(head);
    if (numberOfNodes == 1)
    {
        printf("Sorted Linked List:\n");
        traverseLinkedList(head);
        exit(0);
    }

    return head;
}
void getOutput(Node *head)
{
    printf("Sorted Linked List:\n");
    traverseLinkedList(head);
}
void swapValues(Node *ptr1, Node *ptr2)
{
    int temporaryValue = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temporaryValue;
}
Node *getTailOfLinkedList(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    return tail;
}
void bubble_sort(Node **head)
{
    Node *tail = getTailOfLinkedList(*head);
    Node *iterator = (*head);

    while (iterator != tail)
    {
        Node *current = iterator;
        Node *previous = NULL;
        while (current != tail)
        {
            if (current->data > current->next->data)
            {
                swapValues(current, current->next);
            }
            previous = current;
            current = current->next;
        }
        tail = previous;
    }
}
int main()
{
    Node *head = getInput();
    bubble_sort(&head);
    getOutput(head);
    return 0;
}