#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* createNewNode(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void addNodeAtEnd(Node** head,int val){
    Node* newNode=createNewNode(val);
    if((*head)==NULL){
        (*head)=newNode;
        return;
    }
    Node* temp=(*head);
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;

}

void traverseLinkedList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void getOutput(int result,int target)
{
    if(result){
        printf("\n%d is Found",target);
    }else{
        printf("\n%d is Not Found",target);
    }
}

Node *getInput(int *target)
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
    printf("Enter target Value: ");
    scanf("%d",&(*target));
    printf("Linked List is:\n");
    traverseLinkedList(head);
    return head;
}
int searchUsing2Pointers(Node* head,Node* tail,int target){
    while (head!=tail)
    {
         if(head->data==target || tail->data==target){
            return 1;
         }
         if(head->next==tail){
            return 0;
         }
         head=head->next;
         tail=tail->prev;
    }
    if(head->data==target){
        return 1;
    }
    return 0;
    
}
Node* getTail(Node* head){
    while (head->next!=NULL)
    {
        head=head->next;
    }
    return head;
}
int main(){

    int target;
    Node *head = getInput(&target);
    Node* tail=getTail(head);
    int result=searchUsing2Pointers(head,tail,target);
    getOutput(result,target);

    return 0;
}