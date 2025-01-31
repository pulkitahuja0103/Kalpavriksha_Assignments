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
void enqueue(Queue *queue, int value)
{
    Node *newNode = createNewNode(value);
    if (queue->front == NULL && queue->rear == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("%d element is inserted in queue\n", value);
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    printf("%d element is deleted from queue\n", temp->data);
    free(temp);
}

void traverseQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }
    Node *temp = queue->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getFront(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return queue->front->data;
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
            printf("Enter value to be push into queue: ");
            scanf("%d", &nodeValue);
            enqueue(&queue, nodeValue);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            value = getFront(&queue);
            if (value != INT_MIN)
            {
                printf("Current front value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&queue))
            {
                printf("queue is Empty.\n");
            }
            else
            {
                printf("queue is Not Empty.\n");
            }
            break;
        case 5:
            traverseQueue(&queue);
            break;
        case 6:
            printf("Size of queue is %d\n", getSize(&queue));
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