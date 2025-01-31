// push operation time-complexity O(1) 
// pop operation time-complexity O(1) 
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
    Node *top;
} Stack;

Node *createNewNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *stack, int val)
{
    Node *newNode = createNewNode(val);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d is inserted in stack\n", val);
}

int isEmpty(Stack *stack)
{
    if (stack->top == NULL)
    {
        return 1;
    }
    return 0;
}

void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return;
    }
    Node *temp = stack->top;
    int val = temp->data;
    printf("%d is removed from stack\n", val);
    stack->top = temp->next;
    free(temp);
}

void traverseStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return;
    }
    Node *temp = stack->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    Node *temp = stack->top;
    return temp->data;
}
int getSize(Stack *stack)
{
    if (isEmpty(stack))
    {
        return 0;
    }

    Node *temp = stack->top;
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
    Stack stack;
    stack.top = NULL;

    int value;
    while (1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. check isEmpty\n");
        printf("5. traverse stack\n");
        printf("6. size of stack\n");
        printf("7. exit\n");
        int choice;
        printf("Enter choice from above options: ");
        scanf("%d", &choice);
        int nodeValue;
        switch (choice)
        {
        case 1:

            printf("Enter value to be push into stack: ");
            scanf("%d", &nodeValue);
            push(&stack, nodeValue);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            value = peek(&stack);
            if (value != INT_MIN)
            {
                printf("Current top value is %d\n", value);
            }
            break;
        case 4:
            if (isEmpty(&stack))
            {
                printf("Stack is Empty.\n");
            }
            else
            {
                printf("Stack is Not Empty.\n");
            }
            break;
        case 5:
            traverseStack(&stack);
            break;
        case 6:
            printf("Size of stack is %d\n",getSize(&stack));
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