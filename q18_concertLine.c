#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[101];
    struct node *next;
} Node;

Node *createNewNode(char* str)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name,str);
    newNode->next = NULL;
    return newNode;
}


int getLength(Node* head){
    int count=0;
    while (head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

void removalOfNthElement(Node** head,int n){
    int length=getLength(*head);
    if(n>length){
        printf("Invalid value of n");
        exit(0);
    }
    if(n==0){
        return;
    }

    if(n==length){
        Node* nodeToDelete=(*head);
        (*head)=(*head)->next;
        free(nodeToDelete);
    }else
    {
        Node* prev=(*head);
        Node* curr=(*head);

        int nodeFromFront=length-n;
        while (nodeFromFront!=0)
        {
            prev=curr;
            curr=curr->next;
            nodeFromFront--;
        }
        prev->next=curr->next;
        free(curr);
    }
    
}

void addNodeAtEnd(Node **head, char* str)
{
    Node *newNode = createNewNode(str);
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
        printf("%s ", head->name);
        head = head->next;
    }
    printf("\n");
}

Node *getInput(int num)
{
    Node *head = NULL;
    int numberOfPersons;
    printf("Enter Number of persons\n");
    scanf("%d",&numberOfPersons);
    if(numberOfPersons<=0){
        printf("Invalid number of persons\n");
        exit(0);
    }
    while (numberOfPersons!=0)
    {
        printf("Enter name\n");
        char newName[101];
        getchar();
        scanf("%[^\n]", newName);
        addNodeAtEnd(&head, newName);
        numberOfPersons--;
    }
    return head;
}

int getNvalue(){
    int n;
    printf("Enter value of node to be removed from end\n");
    scanf("%d",&n);

    if(n<0){
        printf("Invalid value of n");
        exit(0);
    }
    return n;
}
void getOutput(Node *head,int n)
{
    printf("Original Linked List\n");
    traversal(head);
    removalOfNthElement(&head,n);
    printf("Linked List After removal of nth element from end\n");
    traversal(head);
}

int main()
{
    Node *head = getInput(1);
    int n=getNvalue();
    getOutput(head,n);

    return 0;
}