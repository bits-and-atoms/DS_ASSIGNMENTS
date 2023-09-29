//SUBHAM MAJUMDER
//2212020
/*
    Program to implement polynomial expression using a singly linked list.
    time complexity is O(n)
    space complexity is O(n)
*/
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void addTerm(struct Term **poly, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void displayPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct Term *polynomial = NULL;

    // Adding terms to the polynomial
    addTerm(&polynomial, 3, 2);
    addTerm(&polynomial, -4, 1);
    addTerm(&polynomial, 1, 0);

    // Displaying the polynomial
    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
