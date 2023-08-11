#include <stdio.h>
//number to roman
//2212020
void ToRoman(int num) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    if (num <= 0 || num >= 4000) {
        printf("Roman numerals are only defined for numbers from 1 to 3999. After that bar is used\n");
        return;
    }

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            printf("%s", roman[i]);
            num -= values[i];
        }
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Roman numeral equivalent: ");
    ToRoman(num);

    return 0;
}