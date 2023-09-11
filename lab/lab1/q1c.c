//using dynamic programming
// We can avoid the repeated work done in the Recursion approach by storing the Fibonacci numbers calculated so far.
#include <stdio.h>

int fib(int n){
    int arr[n+1];
    arr[0]=0,arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}
