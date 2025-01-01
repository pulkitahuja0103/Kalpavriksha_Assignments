#include <stdio.h>

int calculateRemainder(int baseValue, int exponentValue, int modulusValue)
{
    int result = 1;
    baseValue = baseValue % modulusValue; 
    while (exponentValue > 0)
    {
        
        if (exponentValue % 2 == 1)
        {
            result = (result * baseValue) % modulusValue;
        }
        exponentValue = exponentValue / 2;
        baseValue = (baseValue * baseValue) % modulusValue;
    }

    return result;
}

void getInputs(int *baseValue, int *exponentValue, int *modulusValue)
{
    printf("Enter values of base , exponent and modulus: \n");
    scanf("%d %d %d", &(*baseValue), &(*exponentValue), &(*modulusValue));
}

int main()
{

    int baseValue, exponentValue, modulusValue;
    getInputs(&baseValue, &exponentValue, &modulusValue);

    int remainder = calculateRemainder(baseValue, exponentValue, modulusValue);

    printf("Remainder is : %d", remainder);

    return 0;
}