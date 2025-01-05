#include<stdio.h>
#include<stdlib.h>

int size;
int *arr=NULL;

int row;
int column;
int **arr2;

void printAddressOfVariable(int num,int *ptr,int **ptr2){
    printf("Address of num variable: %d\n",&num);
    printf("Address of num variable: %d\n",ptr);
    printf("Address of num variable: %d\n",*(ptr2));
}

void printValueOfVariable(int num,int *ptr,int **ptr2){
    printf("Value of num variable: %d\n",num);
    printf("Value of num variable: %d\n",*(&num));
    printf("Value of num variable: %d\n",*(ptr));
    printf("Value of num variable: %d\n",**(ptr2));
}

void AllocateMemoryDynamicallyFor1dArray(){
    
    printf("Enter size of array:\n");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
}

void AllocateMemoryDynamicallyFor2dArray(){
    
    printf("Enter number of rows:\n");
    scanf("%d",&row);
    printf("Enter number of column:\n");
    scanf("%d",&column);

    arr2=(int**)malloc(row*sizeof(int*));

    for(int index=0;index<row;index++){
        arr2[index]=(int *)malloc(column*sizeof(int));
    }
}

void getInputFor1dArray(){

    for(int index=0;index<size;index++){

        printf("Enter element for index %d:",index);
        scanf("%d",&arr[index]);

    }
}
void getInputFor2dArray(){

    for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int columnIndex=0;columnIndex<column;columnIndex++){
    
            printf("Enter element for index [%d][%d]:",rowIndex,columnIndex);
            scanf("%d",&arr2[rowIndex][columnIndex]);

        }
    }
}

void print1dArray(){
   
    for(int index=0;index<size;index++){
        printf("Value at index %d is : %d\n",index,arr[index]);
    }
}
void print2dArray(){
     for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int columnIndex=0;columnIndex<column;columnIndex++){

            printf("Value at index [%d][%d] is : %d\t",rowIndex,columnIndex,*(*(arr2 + rowIndex) + columnIndex));
        
        }
        printf("\n");
    }
    
}

void free2dArrayMemory(){
    for (int index = 0; index < row; index++) {
        free(arr2[index]); 
    }
    free(arr2); 
    arr2 = NULL; 
}

int main(){

    int num=25;
    int *ptr=&num;
    int **ptr2=&ptr;

    printAddressOfVariable(num,ptr,ptr2);
    printValueOfVariable(num,ptr,ptr2);
    

    AllocateMemoryDynamicallyFor1dArray();
    getInputFor1dArray();
    print1dArray();    


    AllocateMemoryDynamicallyFor2dArray();
    getInputFor2dArray();
    print2dArray();

    free(arr);
    arr=NULL;
    free2dArrayMemory();

    return 0;
}