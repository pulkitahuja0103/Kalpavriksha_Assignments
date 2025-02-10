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

Node *getMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int getValue(Node *head)
{
    if (head->data < 0)
    {
        return (-1 * head->data);
    }
    return head->data;
}
Node *merge(Node *list1, Node *list2)
{
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node *answer = NULL;
    int val1 = getValue(list1);
    int val2 = getValue(list2);

    if (val1 <= val2)
    {
        answer = list1;
        answer->next = merge(list1->next, list2);
    }
    else
    {
        answer = list2;
        answer->next = merge(list1, list2->next);
    }

    return answer;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middleNode = getMiddle(head);
    Node *right = middleNode->next;
    middleNode->next = NULL;

    Node *list1 = mergeSort(head);
    Node *list2 = mergeSort(right);

    return merge(list1, list2);
}
void getInput()
{
    int numberOfNodes;
    printf("Enter number of nodes\n");
    scanf("%d", &numberOfNodes);

    Node *head = NULL;
    while (numberOfNodes != 0)
    {
        int val;
        printf("Enter Node Value: ");
        scanf("%d", &val);
        addNodeAtEnd(&head, val);
        numberOfNodes--;
    }
    traversal(head);
    Node *answer = mergeSort(head);
    traversal(answer);
}
int main()
{
    getInput();
    return 0;
}