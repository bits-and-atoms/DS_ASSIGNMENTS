// nth fib number using recursion
#include <stdio.h>

int fib(int n){
    
    if(n<=1) return n;
    else {
        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}
