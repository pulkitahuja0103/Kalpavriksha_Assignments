#include<stdio.h>
#include<stdlib.h>

int row;
int column;
int **arr2;

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

void getInputFor2dArray(){

    for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int columnIndex=0;columnIndex<column;columnIndex++){
    
            printf("Enter element for index [%d][%d]:",rowIndex,columnIndex);
            scanf("%d",&arr2[rowIndex][columnIndex]);

        }
    }
}

void printDiagonalElements(){
     for(int rowIndex=0;rowIndex<row;rowIndex++){
        for(int columnIndex=0;columnIndex<column;columnIndex++){

            if(rowIndex==columnIndex)
                printf("%d\t",*(*(arr2 + rowIndex) + columnIndex));
            else
                printf("\t");
        
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

    AllocateMemoryDynamicallyFor2dArray();
    getInputFor2dArray();
    printDiagonalElements();
    free2dArrayMemory();

    return 0;
}