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

int getValueOfK()
{
    int k;
    printf("Enter Value of k (Groups of linked list to be reversed):");
    scanf("%d", &k);
    return k;
}
int getLength(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *reverseLinkedList(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;

    for (int itr = 0; itr < k; itr++)
    {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    return prev;
}

Node *getKthNode(Node *temp, int k)
{
    Node *kthNode = temp;

    k--;
    while (k>0 && kthNode!=NULL)
    {
        kthNode=kthNode->next;
        k--;
    }

    return kthNode;
}
void reverseLinkedListInKGroups(Node **head, int k, int size)
{
    Node *temp = (*head);
    Node *prevNode = NULL;
    while (temp != NULL)
    {
        
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevNode != NULL)
            {
                prevNode->next = temp;
            }
            break;
        }
        Node *nextTemp = kthNode->next;
        kthNode->next = NULL;

        Node *reverseLLHead = reverseLinkedList(temp, k);
        if (temp == (*head))
        {
            (*head) = reverseLLHead;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextTemp;
    }
}
int main()
{
    Node *list = getInput();
    traverseLinkedList(list);

    int k = getValueOfK();
    int currentCount = 0;
    int size = getLength(list);
    reverseLinkedListInKGroups(&list, k, size);
    traverseLinkedList(list);

    return 0;
}