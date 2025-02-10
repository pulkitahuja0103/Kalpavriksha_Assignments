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
        printf("Empty Linked List\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *getInput(int num)
{
    Node *head = NULL;
    while (1)
    {
        printf("Enter Node Value in list %d(enter -1 to stop)\n", num);
        int value;
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        addNodeAtEnd(&head, value);
    }
    return head;
}


void placeEvenNumbers(Node* head){
    Node* evenPosiHead=NULL;
    Node* evenPosiTail=NULL;

    Node* oddPosiHead=NULL;
    Node* oddPosiTail=NULL;
    
    while (head!=NULL)
    {
        if(head->data%2==0){
            if(evenPosiHead==NULL){
                evenPosiHead=head;
                evenPosiTail=head;
                head=head->next;
                evenPosiTail->next=NULL;
            }else{
                evenPosiTail->next=head;
                evenPosiTail=head;
                head=head->next;
                evenPosiTail->next=NULL;
            }
        }else{
            if(oddPosiHead==NULL){
                oddPosiHead=head;
                oddPosiTail=head;
                head=head->next;
                oddPosiTail->next=NULL;
            }else{
                oddPosiTail->next=head;
                oddPosiTail=head;
                head=head->next;
                oddPosiTail->next=NULL;
            }
        }
    }

    traversal(evenPosiHead);
    traversal(oddPosiHead);
    
}

void getOutput(Node *head)
{
    printf("Original Linked List\n");
    traversal(head);
    placeEvenNumbers(head);
    printf("Linked List After placing Even at front\n");
}

int main()
{
    Node *head = getInput(1);

    getOutput(head);

    return 0;
}