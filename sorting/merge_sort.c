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

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}
Node *merge(Node *list1, Node *list2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            if (head == NULL && tail == NULL)
            {
                head = list1;
                tail = head;
                list1 = list1->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
                tail->next = NULL;
            }
        }
        else
        {
            if (head == NULL && tail == NULL)
            {
                head = list2;
                tail = head;
                list2 = list2->next;
                tail->next = NULL;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
                tail->next = NULL;
            }
        }
    }

    while (list1 != NULL)
    {
        tail->next = list1;
        tail = tail->next;
        list1 = list1->next;
        tail->next = NULL;
    }
    while (list2 != NULL)
    {
        tail->next = list2;
        tail = tail->next;
        list2 = list2->next;
        tail->next = NULL;
    }
    return head;
}
Node *merge_sort(Node *head)
{
    if (head == NULL || (head)->next == NULL)
    {
        return (head);
    }
    Node *mid = findMid(head);
    Node *midNextNode = mid->next;
    mid->next = NULL;
    Node *list1 = merge_sort(head);
    Node *list2 = merge_sort(midNextNode);

    Node *newHead = merge(list1, list2);

    return newHead;
}
int main()
{
    Node *head = getInput();
    head=merge_sort(head);
    getOutput(head);
}