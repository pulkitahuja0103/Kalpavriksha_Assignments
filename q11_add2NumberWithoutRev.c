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
void addNodeAtBeginning(Node **head, int val)
{
    Node *newNode = createNewNode(val);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }
    newNode->next = (*head);
    (*head) = newNode;
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
int getLength(Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

void addZeros(Node **list1, Node **list2, int len1, int len2)
{
    if (len1 < len2)
    {
        int num = len2 - len1;
        while (num != 0)
        {
            addNodeAtBeginning(list1, 0);
            num--;
        }
    }
    else if(len1>len2)
    {
        int num = len1 - len2;
        while (num != 0)
        {
            addNodeAtBeginning(list2, 0);
            num--;
        }
    }
}
void addRecersively(Node **answer, Node *list1, Node *list2, int *carry)
{
    if (list1 == NULL && list2 == NULL)
    {
        return;
    }
    addRecersively(answer, list1->next, list2->next, carry);
    int sum = list1->data + list2->data + (*carry);
    (*carry) = sum / 10;
    sum = sum % 10;
    addNodeAtBeginning(answer, sum);
}
Node *addList(Node *list1, Node *list2)
{
    int len1 = getLength(list1);
    int len2 = getLength(list2);

    if (len1 != len2)
    {
        addZeros(&list1, &list2, len1, len2);
    }

    traverseLinkedList(list1);
    traverseLinkedList(list2);
    Node *answer = NULL;
    int carry = 0;

    addRecersively(&answer, list1, list2, &carry);
    if (carry != 0)
    {
        addNodeAtBeginning(&answer, carry);
    }
    
    return answer;
}
int main()
{
    Node *list1 = getInput();
    Node *list2 = getInput();
    Node *answer = addList(list1, list2);

    traverseLinkedList(list1);
    traverseLinkedList(list2);
    printf("Answer is:\n");
    traverseLinkedList(answer);

    return 0;
}