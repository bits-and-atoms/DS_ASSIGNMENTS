#include <stdio.h>
void foo2 ( int ) ;
void foo1 ( int n )
{
if ( n <= 10 )
{

printf ("%d\t" , n ) ;
n++;
foo2 ( n ) ;
}
}
void foo2 ( int n )
{
if ( n <= 10 )
{
printf ("%d\t" , n ) ;
n++;
foo1 ( n ) ;
}
}
int main ( )
{
foo1 ( 1 ) ;
}
