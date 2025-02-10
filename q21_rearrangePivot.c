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
    int flag=0;
    while (temp != NULL)
    {
        if (temp->data <= pivot)
        {
            count++;
        }
        if (temp->data == pivot)
        {
            flag=1;
            pivotNode = temp;
        }
        temp = temp->next;
    }

    if (count == 0|| flag==0)
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
void selectionSort(Node *head,Node* tail)
{   
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *iterator1 = head;
    while (iterator1->next != tail)
    {
        Node *minimum = iterator1;
        Node *iterator2 = iterator1->next;
        while (iterator2 != tail)
        {
            if (iterator2->data <= minimum->data)
            {
                minimum = iterator2;
            }
            iterator2 = iterator2->next;
        }
        swapValues(iterator1, minimum);
        iterator1 = iterator1->next;
    }
}

void arrangeDecIncAroundPivot(Node *head, Node *pivotNode){
    Node* left=head;
    Node* right=pivotNode->next;

    while (left!=pivotNode && right!=NULL)
    {
        while (left!=pivotNode && left->data <= pivotNode->data)
        {
            left=left->next;
        }
        while (right!=NULL && right->data > pivotNode->data)
        {
            right=right->next;
        }
        swapValues(left,right);
        left=left->next;
        right=right->next;
    }
    
}
void arrangeElements(Node *head, Node *pivotNode)
{
    arrangeDecIncAroundPivot(head,pivotNode);

    if(head!=pivotNode){
        selectionSort(head,pivotNode);
    }
    
    if(pivotNode->next!=NULL){
        selectionSort(pivotNode->next,NULL);
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
    traversal(head);
    int pivot;
    printf("Enter Pivot element: ");
    scanf("%d", &pivot);

    Node *pivotNode = placePivot(head, pivot);
    
    if(pivotNode==NULL){
        printf("Pivot Not found\n");
        traversal(head);
        return;
    }
    arrangeElements(head, pivotNode);
    traversal(head);
}
int main()
{
    getInput();
    return 0;
}