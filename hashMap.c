#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node
{

    int key;
    int value;
    struct node *next;
} Node;

typedef struct hashMap
{
    Node **arrayOfHashMap;
    int capacity;
} hashMap;

void initializeMap(hashMap *mp)
{
    mp->capacity = 13;
    mp->arrayOfHashMap = (Node **)malloc((mp->capacity) * sizeof(Node *));
    for (int iterator = 0; iterator < mp->capacity; iterator++)
    {
        mp->arrayOfHashMap[iterator] = NULL;
    }
}

int getKey()
{
    int key;
    printf("Enter key:");
    scanf("%d", &key);

    if (key < 0)
    {
        return INT_MIN;
    }
    return key;
}

int getValue(hashMap *mp)
{
    int value;
    printf("Enter value:");
    scanf("%d", &value);

    if (value < 0)
    {
        return INT_MIN;
    }
    return value;
}

int hashFunction(hashMap *mp, int key)
{
    return ((key) % (mp->capacity));
}
Node *createNewNode(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int search(hashMap *mp)
{
    int key = getKey();
    if (key == INT_MIN)
    {
        printf("Invalid Key\n");
        return INT_MIN;
    }
    int hashValue = hashFunction(mp, key);

    if (mp->arrayOfHashMap[hashValue] != NULL)
    {
        Node *temp = mp->arrayOfHashMap[hashValue];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return INT_MIN;
    }

    return INT_MIN;
}

int isKeyAlreadyPresent(hashMap *mp, int newKey, int newValue)
{

    int hashValue = hashFunction(mp, newKey);
    if (mp->arrayOfHashMap[hashValue] != NULL)
    {
        Node *temp = mp->arrayOfHashMap[hashValue];
        while (temp != NULL)
        {
            printf("%d %d", temp->key, temp->value);
            if (temp->key == newKey)
            {
                temp->value = newValue;
                return 1;
            }
            temp = temp->next;
        }
    }

    return 0;
}

void insertIntoMap(hashMap *mp)
{
    int key = getKey(mp);
    if (key == INT_MIN)
    {
        printf("Invalid Key\n");
        return;
    }

    int value = getValue(mp);
    if (value == INT_MIN)
    {
        printf("Invalid value\n");
        return;
    }

    int hashValue = hashFunction(mp, key);
    Node *newNode = createNewNode(key, value);

    if (mp->arrayOfHashMap[hashValue] == NULL)
    {
        mp->arrayOfHashMap[hashValue] = newNode;
    }
    else
    {
        if (isKeyAlreadyPresent(mp, key, value))
        {
            return;
        }

        Node *temp = mp->arrayOfHashMap[hashValue];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(hashMap *mp)
{
    bool flag = false;
    for (int iterator = 0; iterator < mp->capacity; iterator++)
    {
        if (mp->arrayOfHashMap[iterator] != NULL)
        {
            flag = true;
            Node *temp = mp->arrayOfHashMap[iterator];
            while (temp != NULL)
            {
                if (temp->next != NULL)
                {
                    printf("(%d,%d)->", temp->key, temp->value);
                }
                else
                {
                    printf("(%d,%d)", temp->key, temp->value);
                }
                temp = temp->next;
            }
            if (flag != false)
            {
                printf("\n");
            }
        }
    }

    if (flag == false)
    {
        printf("Hash Map is empty\n");
    }
}

int delete(hashMap *mp)
{
    int key = getKey(mp);
    if (key == INT_MIN)
    {
        printf("Invalid Key\n");
        return INT_MIN;
    }
    int hashValue = hashFunction(mp, key);
    if (mp->arrayOfHashMap[hashValue] != NULL)
    {
        Node *prev = NULL;
        Node *curr = mp->arrayOfHashMap[hashValue];
        while (curr != NULL)
        {
            if (curr->key == key)
            {
                Node *nodeToDelete = NULL;
                if (prev == NULL)
                {
                    nodeToDelete = curr;
                    mp->arrayOfHashMap[hashValue] = curr->next;
                }
                else
                {
                    nodeToDelete = curr;
                    prev->next = curr->next;
                }
                int val = nodeToDelete->key;
                free(nodeToDelete);
                return val;
            }
            prev=curr;
            curr = curr->next;
        }
        return INT_MIN;
    }

    return INT_MIN;
}
void getInput()
{
    hashMap mp;
    initializeMap(&mp);
    int numberOfOperations;
    printf("Enter number of operations: ");
    scanf("%d", &numberOfOperations);
    if(numberOfOperations<=0){
        printf("Invalid number of operations\n");
        exit(0);
    }
    while (numberOfOperations != 0)
    {
        printf("\n1-Insert\n2-Search\n3-Delete\n4-Display\n5-Exit\n");
        int choice;
        printf("Enter choice:");
        scanf("%d", &choice);
        int result;
        switch (choice)
        {
        case 1:
            insertIntoMap(&mp);
            break;
        case 2:
            result = search(&mp);
            if (result != INT_MIN)
            {
                printf("%d\n", result);
            }
            else
            {
                printf("Key Not Found\n");
            }
            break;
        case 3:
            result = delete (&mp);
            if (result != INT_MIN)
            {
                printf("Key %d deleted\n", result);
            }
            else
            {
                printf("Key Not Found\n");
            }
            break;
        case 4:
            display(&mp);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
        numberOfOperations--;
    }
}
int main()
{
    getInput();
    return 0;
}