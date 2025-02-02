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
        addNodeAtBeginning(&head, value);
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

Node *addList(Node *list1, Node *list2)
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
    int carry = 0;

    while (list1 != NULL && list2 != NULL)
    {
        int sum = list1->data + list2->data + carry;

        carry = sum / 10;
        sum = sum % 10;

        addNodeAtEnd(&answer, sum);
        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL)
    {
        int sum = list1->data + carry;

        carry = sum / 10;
        sum = sum % 10;

        addNodeAtEnd(&answer, sum);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        int sum = list2->data + carry;

        carry = sum / 10;
        sum = sum % 10;

        addNodeAtEnd(&answer, sum);
        list2 = list2->next;
    }
    while (carry != 0)
    {
        int sum = carry;

        carry = sum / 10;
        sum = sum % 10;

        addNodeAtEnd(&answer, sum);
    }

    return answer;
}
int main()
{
    Node *list1 = getInput();
    traverseLinkedList(list1);
    Node *list2 = getInput();
    traverseLinkedList(list2);
    Node *answer = addList(list1, list2);
    printf("Answer is:\n");
    traverseLinkedList(answer);

    return 0;
}