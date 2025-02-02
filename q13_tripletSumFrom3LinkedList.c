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

int getXValue(){
    int x;
    printf("Enter value of x:");
    scanf("%d",&x);
    return x;
}
void getTriplets(Node* list1,Node* list2,Node* list3,int x){
    if(list1==NULL || list2==NULL || list3==NULL){
        return;
    }

    while (list1!=NULL)
    {
        Node* itr2=list2;
        while (itr2!=NULL)
        {
            Node* itr3=list3;
            while (itr3!=NULL)
            {
                if(list1->data + itr2->data + itr3->data == x){
                    printf("%d %d %d \n",list1->data,itr2->data,itr3->data);
                }
                itr3=itr3->next;
            }
            itr2=itr2->next;
        }
        list1=list1->next; 
    }
    
}
int main()
{
    Node *list1 = getInput();
    traverseLinkedList(list1);
    Node *list2 = getInput();
    traverseLinkedList(list2);
    Node *list3 = getInput();
    traverseLinkedList(list3);
    int x=getXValue();
    getTriplets(list1,list2,list3,x);
   
    return 0;
}