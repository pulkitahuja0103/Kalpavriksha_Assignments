// enqueue operation time-complexity O(1)
// dequeue operation time-complexity O(n)
// front operation time-complexity O(1)
// traversal operation time-complexity O(n)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = NULL;
}
Node *createNewNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(Stack *stack, int value)
{
    Node *newNode = createNewNode(value);
    if (stack->top == NULL)
    {
        stack->top = newNode;
        printf("%d element is inserted in queue\n", value);
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d element is inserted in queue\n", value);
}

void dequeue(Stack *S1, Stack *S2)
{
    if (isEmpty(S1))
    {
        printf("Queue is Empty\n");
        return;
    }

    while (S1->top->next != NULL)
    {
        enqueue(S2, S1->top->data);
        Node *temp = S1->top;
        S1->top = S1->top->next;
        free(temp);
    }
    printf("%d element is deleted from stack\n", S1->top->data);
    free(S1->top);
    S1->top = NULL;


    while (S2->top != NULL)
    {
        enqueue(S1, S2->top->data);
        Node *temp = S2->top;
        S2->top = S2->top->next;
        free(temp);
    }
    S2->top = NULL;

}

void printQueueRecursively(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    printf("%d ", temp->data);
    printQueueRecursively(temp->next);
}

void traverseQueue(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Queue is Empty\n");
        return;
    }

    printQueueRecursively(stack->top);
    printf("\n");
}

int getFront(Stack *S1)
{
    if (isEmpty(S1))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return S1->top->data;
}

int getSize(Stack *S1)
{
    if (isEmpty(S1))
    {
        return 0;
    }
    Node *temp = S1->top;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void getInput()
{
    Stack S1;
    initializeStack(&S1);
    Stack S2;
    initializeStack(&S2);

    while (1)
    {
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. front\n");
        printf("4. check isEmpty\n");
        printf("5. traverse queue\n");
        printf("6. Get Size\n");
        printf("7. exit\n");
        int choice;
        printf("Enter choice from above options: ");
        scanf("%d", &choice);
        int nodeValue;
        int value;
        switch (choice)
        {
        case 1:
            printf("Enter value to be enqueue into queue: ");
            scanf("%d", &nodeValue);
            enqueue(&S1, nodeValue);
            break;
        case 2:
            dequeue(&S1, &S2);
            break;
        case 3:
            value = getFront(&S1);
            if (value != INT_MIN)
            {
                printf("Current front value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&S1))
            {
                printf("queue is Empty.\n");
            }
            else
            {
                printf("queue is Not Empty.\n");
            }
            break;
        case 5:
            traverseQueue(&S1);
            break;
        case 6:
            printf("Size of queue is %d\n", getSize(&S1));
            break;
        case 7:
            exit(0);
        default:
            printf("Enter a valid choice\n");
            break;
        }
    }
}
int main()
{
    getInput();
}