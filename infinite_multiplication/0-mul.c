#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_digit - Checks if a string consists only of digits.
 * @s: The string to check.
 * Return: 1 if all digits, 0 otherwise.
 */
int is_digit(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * _calloc - Allocates memory for an array and initializes it to zero.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *p;
    unsigned int i;

    if (nmemb == 0 || size == 0)
        return (NULL);
    p = malloc(nmemb * size);
    if (!p)
        return (NULL);
    for (i = 0; i < (nmemb * size); i++)
        p[i] = '0';
    return (p);
}

/**
 * multiply - Multiplies two large numbers represented as strings.
 * @num1: First number.
 * @num2: Second number.
 * Return: The result of the multiplication as a string.
 */
char *multiply(char *num1, char *num2)
{
    int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum;
    char *result;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;
    result = _calloc(len1 + len2, sizeof(char));
    if (!result)
        return (NULL);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (n1 * n2) + (result[i + j + 1] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
        if (carry)
            result[i + j + 1] = (result[i + j + 1] - '0' + carry) + '0';
    }
    while (*result == '0' && *(result + 1))
        result++;
    return (result);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }
    num1 = argv[1];
    num2 = argv[2];
    if (!is_digit(num1) || !is_digit(num2))
    {
        printf("Error\n");
        exit(98);
    }
    result = multiply(num1, num2);
    if (!result)
    {
        printf("Error\n");
        exit(98);
    }
    printf("%s\n", result);
    free(result);
    return (0);
}
