//SUBHAM MAJUMDER
//2212020
/*
    program to add two polynomial expressions that are represented using a singly linked list.
    time complexity is O(m + n)
    space complexity is O(m + n + p).
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

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;

    while (poly1 != NULL || poly2 != NULL)
    {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp1 = (poly1 != NULL) ? poly1->exponent : 0;
        int exp2 = (poly2 != NULL) ? poly2->exponent : 0;

        int sum_coeff = coeff1 + coeff2;

        addTerm(&result, sum_coeff, exp1);

        if (poly1 != NULL)
            poly1 = poly1->next;
        if (poly2 != NULL)
            poly2 = poly2->next;
    }

    return result;
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

void freePolynomial(struct Term *poly)
{
    struct Term *current = poly;
    while (current != NULL)
    {
        struct Term *temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    struct Term *polynomial1 = NULL;
    struct Term *polynomial2 = NULL;

    addTerm(&polynomial1, 3, 2);
    addTerm(&polynomial1, -4, 1);
    addTerm(&polynomial1, 1, 0);

    addTerm(&polynomial2, 2, 3);
    addTerm(&polynomial2, 5, 1);
    addTerm(&polynomial2, -2, 0);

    printf("Polynomial 1: ");
    displayPolynomial(polynomial1);

    printf("Polynomial 2: ");
    displayPolynomial(polynomial2);

    struct Term *result = addPolynomials(polynomial1, polynomial2);

    printf("Result: ");
    displayPolynomial(result);

    freePolynomial(polynomial1);
    freePolynomial(polynomial2);
    freePolynomial(result);

    return 0;
}
