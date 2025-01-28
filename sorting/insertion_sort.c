#include <Stdio.h>
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
}

void getOutput(Node *head)
{
    printf("\nSorted Linked List:\n");
    traverseLinkedList(head);
}

Node *getInput()
{
    int numberOfNodes;
    printf("Number of Nodes needed to be add: ");
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
    for (int itr = 0; itr < numberOfNodes; itr++)
    {
        int value;
        printf("Enter value for node %d: ", itr + 1);
        scanf("%d", &value);
        addNodeAtEnd(&head, value);
    }
    printf("Un-Sorted Linked List is:\n");
    traverseLinkedList(head);
    return head;
}

void insertion_sort(Node **head)
{

    Node *iterator = (*head)->next;
    Node *iteratorPrevious = (*head);

    while (iterator != NULL)
    {
        Node *beginningPrevious = NULL;
        Node *beginning = (*head);
        int found = 0;
        while (beginning != iterator)
        {
            if (beginning->data > iterator->data)
            {
                found = 1;
                break;
            }
            else
            {
                beginningPrevious = beginning;
                beginning = beginning->next;
            }
        }
        if (found)
        {
            Node *temp = iterator;
            iteratorPrevious->next = iterator->next;
            iterator = iterator->next;
            temp->next = beginning;
            if (beginning == (*head))
            {
                (*head) = temp;
            }
            else
            {
                beginningPrevious->next = temp;
            }
        }
        else
        {
            iteratorPrevious = iterator;
            iterator = iterator->next;
        }
    }
}
int main()
{
    Node *head = getInput();
    insertion_sort(&head);
    getOutput(head);
}