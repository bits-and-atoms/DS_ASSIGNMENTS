//2212020
//SUBHAM MAJUMDER
//TO FIND POWER WITHOUT USING pow()
//TC O(n) SC O(n)
#include <stdio.h>


int powr(unsigned int x, unsigned int y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return powr(x, y / 2) * powr(x, y / 2);
	else
		return x * powr(x, y / 2) * powr(x, y / 2);
}


int main()
{
    unsigned int x,y;
    printf("enter base: ");
    scanf("%u",&x);
    printf("enter power: ");
    scanf("%u",&y);
	printf("%u", powr(x, y));
	return 0;
}
