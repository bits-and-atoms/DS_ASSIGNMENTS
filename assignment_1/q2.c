//2212020
//to multiply two very large numbers
//TC O(len1 * len2) SC O(len1+len2)
#include <stdio.h>
#include <string.h>

// Multiplies str1 and str2, and prints result.
void multiply(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0 || len2 == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // will keep the result number as an integer array
    // in reverse order
    int maxLen = len1 + len2;
    int resultArray[maxLen];
    for (int i = 0; i < maxLen; i++)
    {
        resultArray[i] = 0;
    }

    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;

        // Go from right to left in num2
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + resultArray[i_n1 + i_n2] + carry;
            carry = sum / 10;
            resultArray[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            resultArray[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = maxLen - 1;
    while (i >= 0 && resultArray[i] == 0)
        i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    // Generate the result string
    int idx = 0;
    while (i >= 0)
    {
        result[idx++] = resultArray[i] + '0';
        i--;
    }
    result[idx] = '\0';
    return;
}


int main()
{
    char str1[1000];
    char str2[1000];
    char result[1000];
    printf("enter first number: ");
    scanf("%s",str1);
    printf("enter second number: ");
    scanf("%s",str2);
    if ((str1[0] == '-' || str2[0] == '-') &&
        (str1[0] != '-' || str2[0] != '-'))
        printf("-");

    if (str1[0] == '-')
        memmove(str1, str1 + 1, strlen(str1));

    if (str2[0] == '-')
        memmove(str2, str2 + 1, strlen(str2));

    multiply(str1, str2, result);
    printf("%s\n", result);
    return 0;
}
