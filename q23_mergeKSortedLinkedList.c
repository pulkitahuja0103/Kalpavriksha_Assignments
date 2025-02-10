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
void traverse(Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
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

    Node *answer = NULL;
    if (left->data <= right->data)
    {
        answer = left;
        answer->next = merge(left->next, right);
    }
    else
    {
        answer = right;
        answer->next = merge(left, right->next);
    }
    return answer;
}
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middle = getMiddle(head);
    Node *right = middle->next;
    middle->next = NULL;

    Node *list1 = mergeSort(head);
    Node *list2 = mergeSort(right);

    return merge(list1, list2);
}
void addLinkedListToAnswer(Node **answerHead, Node **answerTail, Node *head)
{
    if (head == NULL)
    {
        return;
    }

    if ((*answerHead) == NULL)
    {
        (*answerHead) = head;
        (*answerTail) = head;
    }
    else
    {
        (*answerTail)->next = head;
    }
    while ((*answerTail)->next != NULL)
    {
        (*answerTail) = (*answerTail)->next;
    }
}
Node *solve()
{
    Node *answerHead = NULL;
    Node *answerTail = NULL;
    int numberOfLinkedList;
    printf("Enter number of linked list:");
    scanf("%d", &numberOfLinkedList);
    if (numberOfLinkedList <= 0)
    {
        return answerHead;
    }

    while (numberOfLinkedList != 0)
    {
        printf("Linked List creation Start\n");
        Node *head = NULL;
        while (1)
        {
            int val;
            printf("Enter node value (-1 to stop): ");
            scanf("%d", &val);
            if (val == -1)
            {
                break;
            }
            addNodeAtEnd(&head, val);
        }

        addLinkedListToAnswer(&answerHead, &answerTail, head);

        numberOfLinkedList--;
    }

    return answerHead;
}
int main()
{
    Node *answer = solve();
    answer = mergeSort(answer);
    traverse(answer);
    return 0;
}