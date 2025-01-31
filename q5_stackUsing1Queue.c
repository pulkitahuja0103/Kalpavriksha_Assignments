// push operation time-complexity O(1) 
// pop operation time-complexity O(n) 
// peek operation time-complexity O(1) 
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
    Node *front;
    Node *rear;
} Queue;

Node *createNewNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void initializeQueue(Queue *queue)
{
    queue->rear = NULL;
    queue->front = NULL;
}

int isEmpty(Queue *queue)
{
    if (queue->front == NULL)
    {
        return 1;
    }
    return 0;
}
void push(Queue *queue1, int value)
{
    Node *newNode = createNewNode(value);
    if (queue1->front == NULL && queue1->rear == NULL)
    {
        queue1->front = newNode;
        queue1->rear = newNode;
        printf("%d element is inserted in stack\n", value);
        return;
    }

    queue1->rear->next = newNode;
    queue1->rear = newNode;
    printf("%d element is inserted in stack\n", value);
}

void pop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Stack is Empty\n");
        return;
    }

    Node *temp = queue->front;
    if (temp->next == NULL)
    {
        queue->rear = NULL;
        queue->front = NULL;
        free(temp);
        return;
    }
    while (temp->next != queue->rear)
    {
        temp = temp->next;
    }
    queue->rear = temp;
    temp = temp->next;
    queue->rear->next = NULL;
    int value = temp->data;

    printf("%d element deleted from stack\n", value);
    free(temp);
}

void printStackRecursively(Node *temp)
{
    if (temp == NULL)
    {
        return;
    }

    int val = temp->data;
    printStackRecursively(temp->next);
    printf("%d ", val);
}
void traverseStack(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Stack is Empty\n");
        return;
    }
    printStackRecursively(queue->front);
    printf("\n");
}

int getTop(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return queue->rear->data;
}

int getSize(Queue *queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }

    Node *temp = queue->front;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void getInput()
{
    Queue queue;
    initializeQueue(&queue);

    while (1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. top\n");
        printf("4. check isEmpty\n");
        printf("5. traverse stack\n");
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
            printf("Enter value to be push into stack: ");
            scanf("%d", &nodeValue);
            push(&queue, nodeValue);
            break;
        case 2:
            pop(&queue);
            break;
        case 3:
            value = getTop(&queue);
            if (value != INT_MIN)
            {
                printf("Current top value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&queue))
            {
                printf("stack is Empty.\n");
            }
            else
            {
                printf("stack is Not Empty.\n");
            }
            break;
        case 5:
            traverseStack(&queue);
            break;
        case 6:
            printf("Size of stack is %d\n", getSize(&queue));
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