#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char employeeId[100];
    struct node *next;
} Node;

Node *createNewNode(char *str)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->employeeId, str);
    newNode->next = NULL;

    return newNode;
}

void addNodeAtEnd(Node **head, char *str)
{
    Node *newNode = createNewNode(str);
    if ((*head) == NULL)
    {
        (*head) = newNode;
        (*head)->next = (*head);
        return;
    }
    Node *temp = (*head);
    while (temp->next != (*head))
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = (*head);
}

void traversal(Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty");
        return;
    }

    Node *temp = head;
    do
    {
        printf("%s ", temp->employeeId);
        temp = temp->next;

    } while (temp != head);
}

Node *getInput()
{
    Node *head = NULL;

    int numberOfParticipants;
    printf("Enter participants\n");
    scanf("%d", &numberOfParticipants);
    if(numberOfParticipants<=0){
        printf("Invalid number of participants");
        exit(0);
    }
    while (numberOfParticipants != 0)
    {
        char empId[101];
        getchar();
        printf("Enter employee id\n");
        scanf("%[^\n]", empId);
        addNodeAtEnd(&head, empId);
        numberOfParticipants--;
    }
    return head;
}

int getK()
{
    int k;
    printf("Enter value of k\n");
    scanf("%d", &k);
    if(k<=0){
        printf("invalid value of k");
        exit(0);
    }
    return k;
}

void playGame(Node *head, int k)
{
    if (k == 1)
    {

        while (head->next != head)
        {
            Node *tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }

            Node *nodeToDelete = head;
            head = head->next;
            tail->next = head;
            printf("%s ", nodeToDelete->employeeId);
            free(nodeToDelete);
        }
        printf("\nWinner\n");
        traversal(head);
        return;
    }
    while (head->next != head)
    {
        int count = 1;
        Node *prev = head;
        Node *curr = head;

        while (count != k)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        Node *nodeToDelete = curr;
        Node *newHead = curr->next;
        prev->next = newHead;
        head = newHead;

        printf("%s ", nodeToDelete->employeeId);

        prev->next = curr->next;
        free(nodeToDelete);
    }
    printf("\nWinner\n");
    traversal(head);
}
int main()
{

    Node *head = getInput();
    int k = getK();

    playGame(head, k);

    return 0;
}