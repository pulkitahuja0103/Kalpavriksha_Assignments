#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addNodeAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        return;
    }

    Node *temp = (*head);
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void createCycle(Node *head, int position)
{
    if (head == NULL)
    {
        printf("Invalid position to create a cycle.\n");
        return;
    }

    Node *temp = head;
    Node *cycleNode = NULL;
    int count = 1;

    while (temp->next)
    {
        if (count == position)
        {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (count < position)
    {
        printf("Invalid position\n");
        exit(0);
    }
    else
    {
        temp->next = cycleNode;
        printf("Cycle created \n");
    }
}

void removeCycle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }

    if (slow != fast)
    {
        return;
    }

    slow = head;
    if (slow == fast)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
    }
    else
    {
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
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

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node *createLinkedListWithCycle(int listNumber)
{
    Node *list = NULL;
    int n, value, cyclePosition;
    printf("Enter the number of nodes for List %d: ", listNumber);
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid size");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &value);
        addNodeAtEnd(&list, value);
    }
    printf("Enter the position of node to create cycle: ");
    scanf("%d", &cyclePosition);
    if (cyclePosition > 0)
    {
        createCycle(list, cyclePosition);
    }
    else
    {
        printf("Invalid cycle position");
        exit(0);
    }
    return list;
}

void getOutput(Node *head)
{
    printf("Merged sorted linked list:\n");
    printList(head);
}
int main()
{
    Node *list1 = createLinkedListWithCycle(1);
    Node *list2 = createLinkedListWithCycle(2);

    removeCycle(list1);
    removeCycle(list2);

    list1 = merge_sort(list1);
    list2 = merge_sort(list2);
    Node *mergedList = merge(list1, list2);

    getOutput(mergedList);

    return 0;
}
