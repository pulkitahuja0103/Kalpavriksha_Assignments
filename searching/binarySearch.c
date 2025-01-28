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
int getLengthOfLinkedList(Node* head){
    int length=0;
    while (head!=NULL)
    {
        length++;
        head=head->next;
    }
    return length;
}
int binarySearch(Node** low,int target){
    int len=getLengthOfLinkedList((*low));
    if((*low)->next==NULL){
        if((*low)->data!=target)
            return 0;
        return 1;
    }
    int midIndex=len/2;

    Node* midNode=(*low);
    int count=1;
    while (count!=midIndex)
    {
        midNode=midNode->next;
        count++;
    }

    if(midNode->data==target){
        return 1;
    }else if(midNode->data<target){
        return binarySearch(&(midNode->next),target);
    }else{
        midNode->next=NULL;
        return binarySearch((low),target);
    }
}

int main()
{   
    int target;
    Node *head = getInput(&target);
    int result=binarySearch(&head,target);
    getOutput(result,target);
}