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

Node *getTail(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL, *curr = head, *tail = pivot;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if (*newHead == NULL)
            {
                *newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            Node *temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*newHead == NULL)
    {
        *newHead = pivot;
    }

    *newEnd = tail;

    return pivot;
}
Node *quick_sort(Node *head, Node *end)
{
    if (head == NULL || head == end)
    {
        return head;
    }

    Node *newHead = NULL, *newEnd = NULL;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quick_sort(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quick_sort(pivot->next, newEnd);

    return newHead;
}
int main()
{
    Node *head = getInput();
    Node *tail = getTail(head);
    head = quick_sort(head, tail);
    getOutput(head);
}