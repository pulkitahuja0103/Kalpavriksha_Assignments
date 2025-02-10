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

void traversal(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List");
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void swapValues(Node *ptr1, Node *ptr2)
{
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
}
Node *placePivot(Node *head, int pivot)
{
    int count = 0;
    Node *temp = head;
    Node *pivotNode = head;
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data <= pivot)
        {
            count++;
        }
        if (temp->data == pivot)
        {
            flag = 1;
            pivotNode = temp;
        }
        temp = temp->next;
    }

    if (count == 0 || flag == 0)
    {
        return NULL;
    }

    count--;

    temp = head;
    while (count != 0)
    {
        temp = temp->next;
        count--;
    }
    swapValues(temp, pivotNode);

    return temp;
}
void selectionSort(Node *head, Node *tail)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *iterator1 = head;
    while (iterator1->next != tail)
    {
        Node *maximum = iterator1;
        Node *iterator2 = iterator1->next;
        while (iterator2 != tail)
        {
            if (iterator2->data >= maximum->data)
            {
                maximum = iterator2;
            }
            iterator2 = iterator2->next;
        }
        swapValues(iterator1, maximum);
        iterator1 = iterator1->next;
    }
}
int getLength(Node *head)
{
    int length = 0;
    if (head == NULL)
    {
        return length;
    }

    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}
void makeKgroupAndSort(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    int length = getLength(head);

    Node *start = head;
    Node *end = head;

    while (length >= k)
    {
        int count = 1;
        while (count != k)
        {
            end = end->next;
            count++;
        }
        if (count == k)
        {
            end = end->next;
            selectionSort(start, end);
            start = end;
        }
        length = length - k;
    }
}
void getInput()
{
    Node *head = NULL;
    while (1)
    {
        int val;
        printf("Enter Node Value (-1 to stop): ");
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        addNodeAtEnd(&head, val);
    }
    if(getLength(head)==0){
        printf("Linked list is empty");
        return;
    }
    int k;
    printf("Enter value of k:");
    scanf("%d", &k);
    if (k < 0)
    {
        return;
    }

    traversal(head);
    if (k != 0)
    {
        makeKgroupAndSort(head, k);
    }
    traversal(head);
}
int main()
{
    getInput();
    return 0;
}