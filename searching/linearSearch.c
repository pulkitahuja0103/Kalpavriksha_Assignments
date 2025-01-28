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

void getOutput(int result,int target,int position)
{
    if(result){
        printf("\n%d is Found at %d Position",target,position);
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

int linearSearch(Node* head,int target,int *position){
    while (head!=NULL)
    {   (*position)++;
        if(head->data==target){
            return 1;
        }
        head=head->next;
    }
    return 0;
}

int main()
{   
    int target;
    int position=0;
    Node *head = getInput(&target);
    int result=linearSearch(head,target,&position);
    getOutput(result,target,position);
}