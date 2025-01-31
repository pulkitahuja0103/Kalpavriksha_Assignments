// enqueue operation time-complexity O(1)
// dequeue operation time-complexity O(n)
// front operation time-complexity O(n)
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

Node *createNewNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void initializeStack(Stack *stack)
{
    stack->top = NULL;
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
        printf("%d element enqueued in queue\n", value);
        return;
    }

    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d element enqueued in queue\n", value);
}

int dequeue(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }

    Node *prev = NULL;
    Node *curr = stack->top;
    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    int value = curr->data;
    if (prev)
        prev->next = NULL;
    else
        stack->top = NULL;
    
    free(curr);
    printf("%d element dequeued from queue\n", value);
    return value;
}
void printQueueRecursively(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    printQueueRecursively(temp->next);
    printf("%d ", temp->data);
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
int getFront(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    Node* temp=stack->top;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    return temp->data;
}

int getSize(Stack *stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }
    Node *temp = stack->top;
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
    Stack stack;
    initializeStack(&stack);

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
            enqueue(&stack, nodeValue);
            break;
        case 2:
            dequeue(&stack);
            break;
        case 3:
            value = getFront(&stack);
            if (value != INT_MIN)
            {
                printf("Current front value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&stack))
            {
                printf("queue is Empty.\n");
            }
            else
            {
                printf("queue is Not Empty.\n");
            }
            break;
        case 5:
            traverseQueue(&stack);
            break;
        case 6:
            printf("Size of queue is %d\n", getSize(&stack));
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
    return 0;
}
