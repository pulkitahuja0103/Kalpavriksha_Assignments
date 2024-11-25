#include<stdio.h>
#include <stdbool.h> 
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

bool checkValid(char *str){
    int i=0;
    while(str[i] != '\0'){
        if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && str[i]!=' ' && !isdigit(str[i])){
            return false;
        }
        i++;
    }

    return true;
}

int priority(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }

    if(ch=='*' || ch=='/'){
        return 2;
    }

    return 0;//for any other symbol
}

int calculate(int num1,int num2,char ch){
    if(ch=='+'){
        return num1+num2;
    }else if(ch=='-'){
        return num1-num2;
    }else if(ch=='*'){
        return num1*num2;
    }else if(ch=='/'){
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

int solve(char *str){
    int stack1[100];//to store operands
    char stack2[100];//to store operators

    int top1=-1;
    int top2=-1;

    int i=0;

    while(str[i]!='\0'){

        // space
        if(str[i]==' '){
            i++;
            continue;
        }

        // number
        if(isdigit(str[i])){
           //get full number
           int num=0;
           while(i < strlen(str) && isdigit(str[i])){
            num=num * 10 + (str[i]-'0');
            i++;
           }
           top1++;
            stack1[top1]=num;
            continue;
        }

        // operator
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' ||str[i]=='/' ){
            while(top2!=-1 && priority(stack2[top2])>=priority(str[i])){
                int num2=stack1[top1];
                top1--;

                int num1=stack1[top1];
                top1--;

                char op=stack2[top2];
                top2--;

                int ans=calculate(num1,num2,op);

                top1++;
                stack1[top1]=ans;
            }

            top2++;
            stack2[top2]=str[i];
        }

        i++;
    }

    // for remaining elements in stack2
    while (top2 != -1)
    {
        int num2 = stack1[top1];
        top1--;

        int num1 = stack1[top1];
        top1--;

        char op = stack2[top2];
        top2--;

        top1++;
        stack1[top1] = calculate(num1, num2, op);
    }

    return stack1[top1]; 
}

int main(){

    char str[1000];

    printf("Enter your string: ");
    fgets(str,sizeof(str),stdin);//also to get spaces

    str[strcspn(str,"\n")]='\0';//to remove enter (\n)

    if(checkValid(str)){
        int ans=solve(str);
        printf("Result: %d",ans);
    }else{
        printf("Error: Invalid expression.");
    }

    return 0;
}