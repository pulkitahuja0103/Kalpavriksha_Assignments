#include <stdio.h>

long long calculateRemainder(long long baseValue, long long exponentValue, long long modulusValue)
{
    long long result = 1;
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

void getInputs(long long *baseValue, long long *exponentValue, long long *modulusValue)
{
    printf("Enter values of base , exponent and modulus: \n");
    scanf("%lld %lld %lld", &(*baseValue), &(*exponentValue), &(*modulusValue));
    if (baseValue<0 || exponentValue<0 || modulusValue<0)
    {
        printf("Enter positive values of base , exponent and modulus: \n");
        scanf("%lld %lld %lld", &(*baseValue), &(*exponentValue), &(*modulusValue));
    }
    
}

int main()
{

    long long baseValue, exponentValue, modulusValue;
    getInputs(&baseValue, &exponentValue, &modulusValue);

    long long remainder = calculateRemainder(baseValue, exponentValue, modulusValue);

    printf("Remainder is : %lld", remainder);

    return 0;
}