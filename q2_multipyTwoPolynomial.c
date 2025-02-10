#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coefficient;
    int power;
    struct node *next;
} Node;

Node *createNewNode(int coefficient, int power)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->power = power;
    newNode->next = NULL;

    return newNode;
}

void addNodeAtEnd(Node **head, int coefficient, int power)
{
    Node *newNode = createNewNode(coefficient, power);
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

void traverseLinkedList(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    printf("Linked List is:\n");
    while (head != NULL)
    {
        if (head->power == 0)
        {
            printf("%d ", head->coefficient);
        }
        else
        {
            printf("%dx^%d ", head->coefficient, head->power);
        }

        head = head->next;
    }
    printf("\n");
}

Node *getInput(int number)
{
    Node *head = NULL;
    printf("Enter values for %d linked list (Enter negative power to stop)\n", number);
    while (1)
    {
        int coefficient, power;
        printf("\nEnter power:");
        scanf("%d", &power);
        if (power < 0)
        {
            break;
        }
        printf("\nEnter coefficient:");
        scanf("%d", &coefficient);

        addNodeAtEnd(&head, coefficient, power);
    }

    return head;
}
Node *getMiddleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *mergedNodeHead = createNewNode(0, 0);
    Node *tail = mergedNodeHead;

    while (left != NULL && right != NULL)
    {
        if (left->power > right->power)
        {
            tail->next = left;
            tail = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            tail = right;
            right = right->next;
        }
    }

    if (left == NULL)
    {
        tail->next = right;
    }

    if (right == NULL)
    {
        tail->next = left;
    }

    return mergedNodeHead->next;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middleNode = getMiddleNode(head);
    Node *right = middleNode->next;
    middleNode->next = NULL;

    head = mergeSort(head);
    right = mergeSort(right);

    Node *mergedNode = merge(head, right);
    return mergedNode;
}
Node *sortLinkedAsPerPowers(Node *head)
{
    head = mergeSort(head);
    return head;
}
void combineSameCoffiecient(Node **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *temp = (*head);
    while ((temp)->next != NULL)
    {
        if (temp->power == temp->next->power)
        {
            temp->coefficient = temp->coefficient + temp->next->coefficient;
            Node *nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            temp = nodeToDelete->next;
            free(nodeToDelete);
        }
        else
        {
            temp = temp->next;
        }
    }
}

Node *performMultiplication(Node *head1, Node *head2)
{
    Node *answer = NULL;
    if (head1 == NULL || head2 == NULL)
    {
        return answer;
    }

    while (head2 != NULL)
    {
        Node *head1Iterator = head1;
        while (head1Iterator != NULL)
        {
            int newCoefficient = head1Iterator->coefficient * head2->coefficient;
            int newPower = head1Iterator->power + head2->power;

            addNodeAtEnd(&answer, newCoefficient, newPower);
            head1Iterator = head1Iterator->next;
        }
        answer = sortLinkedAsPerPowers(answer);
        combineSameCoffiecient(&answer);

        head2 = head2->next;
    }

    return answer;
}

int main()
{
    Node *head1 = getInput(1);
    head1 = sortLinkedAsPerPowers(head1);
    combineSameCoffiecient(&head1);
    traverseLinkedList(head1);

    Node *head2 = getInput(2);
    combineSameCoffiecient(&head2);
    head2 = sortLinkedAsPerPowers(head2);
    traverseLinkedList(head2);

    Node *answer = performMultiplication(head1, head2);
    traverseLinkedList(answer);

    return 0;
}