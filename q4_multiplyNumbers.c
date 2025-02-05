#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNewNode(int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void addNodeAtEnd(Node **head, int val)
{
    Node *newNode = createNewNode(val);
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
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node *additionOfLinkedList(Node *list1, Node *list2)
{   
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node *result = NULL;
    int carry = 0;

    while (list1 != NULL && list2 != NULL)
    {
        int val = list1->data + list2->data + carry;
        carry = val / 10;
        val = val % 10;

        addNodeAtEnd(&result, val);

        list1 = list1->next;
        list2 = list2->next;
    }

    while (list1 != NULL)
    {   
        
        int val = list1->data + carry;
        carry = val / 10;
        val = val % 10;

        addNodeAtEnd(&result, val);

        list1 = list1->next;
    }
    while (list2 != NULL)
    {   
        int val = list2->data + carry;
        carry = val / 10;
        val = val % 10;

        addNodeAtEnd(&result, val);

        list2 = list2->next;
    }
    while (carry != 0)
    {
        int val = carry % 10;
        carry = carry / 10;
        addNodeAtEnd(&result, val);
    }

    return result;
}

Node *multiplyList(Node *list1, Node *list2)
{
    Node *answer = NULL;
    int count = 1;
    int carry = 0;
    while (list2 != NULL)
    {
        Node *temp = NULL;
        if (count != 1)
        {
            int zeroNodeToInsert = count - 1;
            while (zeroNodeToInsert != 0)
            {
                addNodeAtEnd(&temp, 0);
                zeroNodeToInsert--;
            }
        }

        Node *iteratorForList1 = list1;
        while (iteratorForList1 != NULL)
        {
            int multiplyValue = (list2->data * iteratorForList1->data) + carry;
            carry = multiplyValue / 10;
            multiplyValue = multiplyValue % 10;
            addNodeAtEnd(&temp, multiplyValue);

            iteratorForList1 = iteratorForList1->next;
        }
        while (carry != 0)
        {
            int val = carry % 10;
            carry = carry / 10;
            addNodeAtEnd(&temp, val);
        }
        answer = additionOfLinkedList(answer, temp);
      
        count++;
        list2 = list2->next;
    }
    
    return answer;
}
Node *getInput(int num)
{
    Node *head = NULL;
    while (1)
    {
        printf("Enter Node Value in list %d(enter -1 to stop)\n", num);
        int value;
        scanf("%d", &value);
        if (value == -1)
        {
            break;
        }
        addNodeAtEnd(&head, value);
    }

    traversal(head);
    return head;
}

Node* reverseLinkedList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;

    while (curr!=NULL)
    {
        head=head->next;
        curr->next=prev;
        prev=curr;
        curr=head;
    }
    return prev;
    
}
int main()
{
    Node *list1 = getInput(1);
    Node *list2 = getInput(2);

    Node *answer = multiplyList(list1, list2);
    answer=reverseLinkedList(answer);
    traversal(answer);
    return 0;
}