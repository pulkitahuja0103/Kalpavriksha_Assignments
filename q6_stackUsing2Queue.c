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
        return;
    }

    queue1->rear->next = newNode;
    queue1->rear = newNode;
    printf("%d element is inserted in stack\n", value);
}

void pop(Queue *queue1, Queue *queue2)
{
    if (isEmpty(queue1))
    {
        printf("Stack is Empty\n");
        return;
    }

    while (queue1->front->next != NULL)
    {
        push(queue2, queue1->front->data);
        Node *temp = queue1->front;
        queue1->front = queue1->front->next;
        free(temp);
    }
    printf("%d element is deleted from stack\n", queue1->front->data);
    free(queue1->front);
    queue1->front = queue1->rear = NULL;

    
    Queue temp = *queue1;
    *queue1 = *queue2;
    *queue2 = temp;

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

void traverseStack(Queue *queue1)
{
    if (isEmpty(queue1))
    {
        printf("Stack is Empty\n");
        return;
    }

    printStackRecursively(queue1->front);
    printf("\n");
}

int getTop(Queue *queue1)
{
    if (isEmpty(queue1))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return queue1->rear->data;
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
    Queue Q1;
    initializeQueue(&Q1);
    Queue Q2;
    initializeQueue(&Q2);

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
            push(&Q1, nodeValue);
            break;
        case 2:
            pop(&Q1, &Q2);
            break;
        case 3:
            value = getTop(&Q1);
            if (value != INT_MIN)
            {
                printf("Current top value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&Q1))
            {
                printf("stack is Empty.\n");
            }
            else
            {
                printf("stack is Not Empty.\n");
            }
            break;
        case 5:
            traverseStack(&Q1);
            break;
        case 6:
            printf("Size of stack is %d\n", getSize(&Q1));
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