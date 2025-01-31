// push operation time-complexity O(1) 
// pop operation time-complexity O(1) 
// peek operation time-complexity O(1) 
// traversal operation time-complexity O(n) 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int *arr;
    int top;
} Stack;

void initilizeStack(Stack *stack, int size)
{
    stack->arr = (int *)malloc(size * sizeof(int));
    stack->top = -1;
}

int isFull(Stack *stack, int size)
{
    if (stack->top == size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Stack *stack)
{
    if (stack->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(Stack *stack, int size)
{
    if (isFull(stack, size))
    {
        printf("Stack is Full\n");
        return;
    }
    int value;
    printf("Enter value to be push into stack: ");
    scanf("%d", &value);
    stack->arr[++(stack->top)] = value;
    printf("Element %d is inserted\n", value);
}
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return INT_MIN;
    }
    return stack->arr[stack->top];
}
void pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return;
    }
    int topElement = peek(stack);
    printf("Element %d is pop out from stack\n", topElement);
    (stack->top)--;
}

void traverseStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return;
    }
    for (int iterator = stack->top; iterator >= 0; iterator--)
    {

        printf("%d ", stack->arr[iterator]);
    }
    printf("\n");
}
int getSize(Stack* stack){
    if(isEmpty(stack)){
        return 0;
    }

    int size=stack->top;
    return (size+1);
}

void getInput()
{
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    if (size <= 0)
    {
        printf("Invalid size.");
        exit(0);
    }
    printf("\n");

    Stack stack;
    initilizeStack(&stack, size);

    while (1)
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. check isFull\n");
        printf("5. check isEmpty\n");
        printf("6. traverse stack\n");
        printf("7. get size of stack\n");
        printf("8. exit\n");
        int choice;
        printf("Enter choice from above options: ");
        scanf("%d", &choice);
        int value;
        switch (choice)
        {
        case 1:
            push(&stack, size);
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
            if (isFull(&stack, size))
            {
                printf("Stack is Full.\n");
            }
            else
            {
                printf("Stack is Not Full.\n");
            }
            break;
        case 5:
            if (isEmpty(&stack))
            {
                printf("Stack is Empty.\n");
            }
            else
            {
                printf("Stack is Not Empty.\n");
            }
            break;
        case 6:
            traverseStack(&stack);
            break;
        case 7:
            printf("The size of stack is %d\n",getSize(&stack));
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