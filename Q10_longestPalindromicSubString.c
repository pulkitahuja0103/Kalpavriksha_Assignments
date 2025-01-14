#include<stdio.h>
#include<string.h>

int getLength(char* input,int startIndex,int endIndex){
    int length=0;

    while(startIndex<=endIndex){
        length++;
        startIndex++;
    }
    return length;
}

int isPalindromicString(char* input,int startIndex,int endIndex){
    while(startIndex<=endIndex){
        if(input[startIndex]!=input[endIndex]){
            return 0;
        }
        startIndex++;
        endIndex--;
    }
    return 1;
}

void printSubString(char* input,int startIndex,int endIndex){
    while(startIndex<=endIndex){
        printf("%c",input[startIndex]);
        startIndex++;
    }
}

void findLongestPalindromicSubString(char* input){
    int maximumLengthOfSubString=0;
    int maximumLengthOfSubStringStartIndex=-1;
    int maximumLengthOfSubStringEndIndex=-1;

    int size=strlen(input);
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            int currentLength=getLength(input,i,j);
            if(currentLength>=maximumLengthOfSubString){
                if(isPalindromicString(input,i,j)){
                    maximumLengthOfSubString=currentLength;
                    maximumLengthOfSubStringStartIndex=i;
                    maximumLengthOfSubStringEndIndex=j;
                }
            }
        }
    }

    printSubString(input,maximumLengthOfSubStringStartIndex,maximumLengthOfSubStringEndIndex);
}

void getInput(char* input){
    printf("Enter String:\n");
    scanf("%[^\n]",input);
}

int main(){

    char input[100];
    getInput(input);

    findLongestPalindromicSubString(input);

    return 0;
}