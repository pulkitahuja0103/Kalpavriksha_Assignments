#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char fileName[100];
    struct node *next;
} Node;

Node *createNewNode(char *str)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->fileName, str);
    newNode->next = NULL;

    return newNode;
}

void addNodeAtEnd(Node **head, char *str)
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
        printf("%s , ", head->fileName);
        head = head->next;
    }
    printf("\n");
}

Node *getInput()
{
    Node *head = NULL;

    int numberOfFiles;
    printf("Enter number of files\n");
    scanf("%d", &numberOfFiles);
    if (numberOfFiles <= 0)
    {
        printf("Invalid number of files");
        exit(0);
    }
    while (numberOfFiles != 0)
    {
        char fileName[101];
        getchar();
        printf("Enter file name\n");
        scanf("%[^\n]", fileName);
        addNodeAtEnd(&head, fileName);
        numberOfFiles--;
    }
    return head;
}

void removeDuplicateFiles(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *iterator = (*head);
    while (iterator != NULL)
    {
        Node *prev = (*head);
        Node *curr = (*head)->next;

        while (curr != NULL)
        {
            if (curr == iterator)
            {
                prev=curr;
                curr = curr->next;
                continue;
            }
            if (strcmp(curr->fileName, iterator->fileName) == 0)
            {
                if (curr == (*head))
                {
                    Node *nodeToDelete = curr;
                    curr = curr->next;
                    (*head)=(*head)->next;
                    free(nodeToDelete);
                    break;
                }
                Node *nodeToDelete = curr;
                prev->next = curr->next;
                curr=curr->next;
                free(nodeToDelete);
            }else{
            prev = curr;
            curr = curr->next;
            }
        }

        iterator = iterator->next;
    }
}

int main()
{
    Node *head = getInput();
    removeDuplicateFiles(&head);
    printf("Unique Files:\n");
    traversal(head);
    return 0;
}