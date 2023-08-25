//2212020
//SUBHAM MAJUDMER
//to find the sum of two very large numbers using string
//time complexity O(n) and space complexity O(length of string)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for finding sum of larger numbers
char* findSum(const char* str1, const char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    
    // Find the maximum length
    int maxLength = (n1 > n2) ? n1 : n2;
    
    // Allocate memory for result (one extra for carry)
    char* result = (char*)malloc((maxLength + 2) * sizeof(char));
    result[maxLength + 1] = '\0'; // Null-terminate the result
    
    int carry = 0;
    int i = n1 - 1, j = n2 - 1, k = maxLength;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += str1[i--] - '0';
        if (j >= 0)
            sum += str2[j--] - '0';
        
        carry = sum / 10;
        result[k--] = (sum % 10) + '0';
    }
    
    // Move result to the beginning of the allocated memory
    char* finalResult = result + k + 1;
    
    // Return the result
    return finalResult;
}

int main() {
    char* str1;
    char* str2;
    char x[1000],y[1000];
    printf("enter first number: ");
    scanf("%s",x);
    printf("enter second number: ");
    scanf("%s",y);
    str1=x,str2=y;
    char* result = findSum(str1, str2);
    
    printf("Sum: %s\n", result);
    
    free(result);
    
    return 0;
}
