#include<stdio.h>
#include <stdbool.h> 
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

int stackOperand[100];
char stackOperator[100];

int topOperand=-1;
int topOperator=-1;


bool checkIsDigit(char ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    return false;
}

bool checkValid(char expression[1000]) {

     int indx=0;
    while(expression[indx] != '\0'){
        if(expression[indx]!='+' && expression[indx]!='-' && expression[indx]!='*' && expression[indx]!='/' && expression[indx]!=' ' && !checkIsDigit(expression[indx])){
            return false;
        }
        indx++;
    }

    return true;
}

int priority(char character){
    if(character=='+' || character=='-'){
        return 1;
    }

    if(character=='*' || character=='/'){
        return 2;
    }

    return 0;
}

int calculate(int num1,int num2,char operator){
    if(operator=='+'){
        return num1+num2;
    }else if(operator=='-'){
        return num1-num2;
    }else if(operator=='*'){
        return num1*num2;
    }else if(operator=='/'){
        if(num2==0){
            printf("Error: Division by zero.");
            exit(1);
        }else{
            return num1/num2;
        }

    }else{
        printf("Error: Invalid Operator");
        exit(1);
    }
}
int getStringLength(char expression[1000]){

    int length=0;

    while (expression[length]!='\0')
    {   
        length++;
    }
    
    return length;

}
void fetchCalculateAndSave(){
        int num2 = stackOperand[topOperand];
        topOperand--;

        int num1 = stackOperand[topOperand];
        topOperand--;

        char operator = stackOperator[topOperator];
        topOperator--;

        topOperand++;
        stackOperand[topOperand] = calculate(num1, num2, operator);
}
int evluateExpression(char expression[1000]){

    int indx=0;

    while(expression[indx]!='\0'){

        // space
        if(expression[indx]==' '){
            indx++;
            continue;
        }

        // number
        if(checkIsDigit(expression[indx])){
           //get full number
           int num=0;
           while(indx < getStringLength(expression) && checkIsDigit(expression[indx])){
            num=num * 10 + (expression[indx]-'0');
            indx++;
           }
            topOperand++;
            stackOperand[topOperand]=num;
            continue;
        }

        // operator
        if(expression[indx]=='+' || expression[indx]=='-' || expression[indx]=='*' ||expression[indx]=='/' ){

            while(topOperator!=-1 && priority(stackOperator[topOperator])>=priority(expression[indx])){

                fetchCalculateAndSave();
            }

            topOperator++;
            stackOperator[topOperator]=expression[indx];
        }

        indx++;
    }

    // for remaining elements in stackOperator
    while (topOperator != -1)
    {
        fetchCalculateAndSave();
    }
    
    return stackOperand[topOperand]; 
}

void getInput(char expression[1000]){
    printf("Enter your Expression: ");
    scanf("%[^\n]", expression);//also to get spaces
}

void setOutput(char expression[1000]){
    if(checkValid(expression)){
        int result=evluateExpression(expression);
        printf("Result: %d",result);
    }else{
        printf("Error: Invalid expression.");
    }
}

int main(){

    char expression[1000];
    getInput(expression);
    setOutput(expression);

    return 0;
}
