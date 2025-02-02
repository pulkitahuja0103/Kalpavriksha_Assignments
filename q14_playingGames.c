#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char employeeID[100];
    struct node* next;
}Node;

void myStrcpy(char* str1,char* str2){
    while (*str2!='\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    
}
Node* createNewNode(char* employee_ID){
    Node* newNode=(Node*)malloc(sizeof(Node));
    myStrcpy(newNode->employeeID,employee_ID);
    newNode->next=NULL;
    return newNode;
}

void addNodeAtEnd(Node** head,char* employee_ID){
    Node* newNode=createNewNode(employee_ID);
    if((*head)==NULL){
        (*head)=newNode;
        return;
    }

    Node* temp=(*head);
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void traverseLinkedList(Node* head){
    if(head==NULL){
        printf("Linked List is empty");
        return;
    }

    while (head!=NULL)
    {
        printf("%s ",head->employeeID);
        head=head->next;
    }
    printf("\n");
}

Node* getInput(){
    Node* list=NULL;

    int numberOfParticipation;
    printf("Enter number of participations:");
    scanf("%d",&numberOfParticipation);

    for(int i=0;i<numberOfParticipation;i++){
        printf("Enter employee ID:");
        char str[100];
        scanf("%s",str);
        addNodeAtEnd(&list,str);
    }
    
    return list;
}

int MyStrcmp(char* str1,char* str2){
    while (*str1!='\0' && *str2!='\0')
    {
        if(*str1!=*str2){
            int num1=*str1-'0';
            int num2=*str2-'0';
            if(num1<num2){
                return -1;
            }else{
                return 1;
            }
        }
        str1++;
        str2++;
    }

    if(*str1=='\0' && *str2=='\0'){
        return 0;
    }
    return 1;
    
}
void getCommonParticipants(Node* list1,Node* list2){
    printf("Common participants:\n");
    while (list1!=NULL)
    {
        Node* list2Iterator=list2;
        while (list2Iterator!=NULL)
        {   
            if(MyStrcmp(list1->employeeID,list2Iterator->employeeID)==0){
                printf("%s ",list1->employeeID);
            }
            list2Iterator=list2Iterator->next;
        }
        list1=list1->next;
    }
    printf("\n");
    
}

Node* getMiddleNode(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }

    Node* answer=NULL;
    addNodeAtEnd(&answer,"");
    Node* tail=answer;
    
    while (left!=NULL && right!=NULL)
    {
        if(left!=NULL && right!=NULL){
            if(MyStrcmp(left->employeeID , right->employeeID)<0){
                tail->next=left;
                tail=left;
                left=left->next;
            }else{
                tail->next=right;
                tail=right;
                right=right->next;
            }
        }
    }

    if(left==NULL){
        tail->next=right;
    }

    if(right==NULL){
        tail->next=left;
    }

    return answer->next;
    
}
Node* mergeSort(Node* list){
    if(list==NULL || list->next==NULL){
        return list;
    }

    Node* middleNode=getMiddleNode(list);
    Node* right=middleNode->next;
    middleNode->next=NULL;
    list=mergeSort(list);
    right=mergeSort(right);

    Node* mergedList=merge(list,right);
    return mergedList;
}

void deleteDuplicateNodes(Node** head){
    if((*head)==NULL || (*head)->next==NULL){
        return;
    }

    Node* prev=NULL;
    Node* curr=(*head);
    while (curr->next!=NULL)
    {
        if(MyStrcmp(curr->employeeID,curr->next->employeeID)==0){
            Node* nodeToDelete=curr;
            if(prev==NULL){
                curr=curr->next;
                (*head)=curr;
            }else{
                curr=curr->next;
                prev->next=curr;
            }
            free(nodeToDelete);
        }else{
            prev=curr;
            curr=curr->next;
        }
    }
    
}
int main(){

    Node* list1=getInput();
    Node* list2=getInput();

    printf("Employee Id of foosball players:\n");
    traverseLinkedList(list1);

    printf("Employee Id of table tennis players\n");
    traverseLinkedList(list2);

    getCommonParticipants(list1,list2);

    list1=mergeSort(list1);
    list2=mergeSort(list2);
    
    printf("Sorted Employee Id of foosball players:\n");
    traverseLinkedList(list1);

    printf("Sorted Employee Id of table tennis players\n");
    traverseLinkedList(list2);

    Node* mergedList=merge(list1,list2);
    deleteDuplicateNodes(&mergedList);

    printf("All participants Employee Id\n");
    traverseLinkedList(mergedList);

    return 0;
}