#include "main.h"
/**
 * print_triangle - Prints a triangle using `#`
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
int i, j, k;
if (size > 0)
{
for (i = 1; i <= size; i++)
{
for (j = size - i; j > 0; j--)
_putchar(' ');
for (k = 0; k < i; k++)
_putchar('#');
_putchar('\n');
}
}
else
{
_putchar('\n');
}
}
