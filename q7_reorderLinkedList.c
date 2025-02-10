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
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseList(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }

    return prev;
}

Node *reorderALinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *middleNode = getMiddle(head);
    Node *list2 = middleNode->next;
    middleNode->next = NULL;

    list2 = reverseList(list2);

    Node *answer = NULL;
    addNodeAtEnd(&answer, 0);
    Node *tail = answer;

    while (head != NULL && list2 != NULL)
    {
        tail->next = head;
        head = head->next;
        tail = tail->next;

        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    if (head == NULL)
    {
        tail->next = list2;
    }

    if (list2 == NULL)
    {
        tail->next = head;
    }

    return answer->next;
}

int main()
{
    Node *list = getInput();
    traverseLinkedList(list);

    Node *newHead = reorderALinkedList(list);
    traverseLinkedList(newHead);

    return 0;
}