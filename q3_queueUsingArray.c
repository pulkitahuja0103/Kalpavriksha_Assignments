// enqueue operation time-complexity O(1)
// dequeue operation time-complexity O(1)
// front operation time-complexity O(1)
// traversal operation time-complexity O(n)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *queue, int size)
{
    queue->arr = (int *)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue *queue, int size)
{
    if (queue->rear == size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue *queue)
{
    if (queue->front == -1 || queue->front > queue->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue *queue, int size)
{
    if (isFull(queue, size))
    {
        printf("Queue is Full\n");
        return;
    }
    int value;
    printf("Enter value to be enqueue: ");
    scanf("%d", &value);
    if (queue->front == -1 && queue->rear == -1)
    {
        queue->front = 0;
    }
    queue->arr[++(queue->rear)] = value;

    printf("%d is inserted in queue\n", value);
}

void dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    (queue->front)++;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return INT_MIN;
    }
    return queue->arr[queue->front];
}

void traverseQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is Empty\n");
        return;
    }
    for (int iterator = queue->front; iterator <= queue->rear; iterator++)
    {
        printf("%d ", queue->arr[iterator]);
    }
    printf("\n");
}
int getSize(Queue *queue)
{
    if (isEmpty(queue))
    {
        return 0;
    }

    int size = queue->rear - queue->front + 1;
    return size;
}
void getInput()
{
    int size;
    printf("Enter size of Queue: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid Size");
        exit(0);
    }

    Queue queue;
    initializeQueue(&queue, size);

    while (1)
    {
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. front\n");
        printf("4. check isFull\n");
        printf("5. check isEmpty\n");
        printf("6. traverse queue\n");
        printf("7. get size\n");
        printf("8. exit\n");
        int choice;
        printf("Enter choice from above options: ");
        scanf("%d", &choice);
        int value;
        switch (choice)
        {
        case 1:
            enqueue(&queue, size);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            value = front(&queue);
            if (value != INT_MIN)
            {
                printf("Current front value is %d\n", value);
            }
            break;
        case 4:
            if (isFull(&queue, size))
            {
                printf("queue is Full.\n");
            }
            else
            {
                printf("queue is Not Full.\n");
            }
            break;
        case 5:
            if (isEmpty(&queue))
            {
                printf("queue is Empty.\n");
            }
            else
            {
                printf("queue is Not Empty.\n");
            }
            break;
        case 6:
            traverseQueue(&queue);
            break;
        case 7:
            printf("Size of queue is %d\n", getSize(&queue));
            break;
        case 8:
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