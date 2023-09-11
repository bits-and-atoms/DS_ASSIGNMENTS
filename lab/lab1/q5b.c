#include<stdio.h>
int foo1 ( )
{
static int n=100;
if ( n<=0)
return 0 ;
return n--;
}
int main ( )
{
for ( foo1 ( ) ; foo1 ( ) ; foo1 ( ) )
printf ("%d\t" , foo1 ( ) ) ;
return 0 ;
}