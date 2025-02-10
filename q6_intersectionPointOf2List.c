#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *mergedHead = NULL;
    addNodeAtEnd(&mergedHead, 0);

    Node *tail = mergedHead;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }

    if (left == NULL)
    {
        tail->next = right;
    }
    else
    {
        tail->next = left;
    }

    return mergedHead->next;
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

    head = mergeSort(head);
    right = mergeSort(right);

    Node *mergedHead = merge(head, right);
    return mergedHead;
}

int intersectionPoint(Node *list1, Node *list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        return INT_MIN;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data == list2->data)
        {
            return list1->data;
        }
        else
        {
            if (list1->data < list2->data)
            {
                list1 = list1->next;
            }
            else
            {
                list2 = list2->next;
            }
        }
    }

    return INT_MIN;
}

void getOutput(int intersectionValue)
{
    if (intersectionValue != INT_MIN)
    {
        printf("intersection Point of Linked List is %d:\n", intersectionValue);
    }
    else
    {
        printf("No Intersection. \n");
    }
}
int main()
{
    Node *list1 = getInput();
    traverseLinkedList(list1);
    list1 = mergeSort(list1);

    Node *list2 = getInput();
    traverseLinkedList(list2);
    list2 = mergeSort(list2);

    int intersectionValue = intersectionPoint(list1, list2);

    getOutput(intersectionValue);

    return 0;
}