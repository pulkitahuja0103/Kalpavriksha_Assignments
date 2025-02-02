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

Node* merge2SortedLinkedList(Node* list1,Node* list2){
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node* newHead=NULL;
    addNodeAtEnd(&newHead,0);
    Node* tail=newHead;

    while (list1!=NULL && list2!=NULL)
    {
        if(list1->data<list2->data){
            tail->next=list1;
            tail=list1;
            list1=list1->next;
        }else{
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
    }

    if(list1==NULL){
        tail->next=list2;
    }else{
        tail->next=list1;
    }
    
    return newHead->next;
}

int main()
{
    Node *list1 = getInput();
    traverseLinkedList(list1);
    Node *list2 = getInput();
    traverseLinkedList(list2);
    Node *mergedLinkedListHead = merge2SortedLinkedList(list1, list2);
    printf("Merged Linked List is:\n");
    traverseLinkedList(mergedLinkedListHead);

    return 0;
}