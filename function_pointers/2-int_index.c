#include <stddef.h>

/**
* int_index - Searches for an integer in an array using a comparison function.
* @array: The array to search in.
* @size: The number of elements in the array.
* @cmp: A pointer to the function used to compare values.
*
* Return: The index of the first matching element, or -1 if no match is found.
*/
int int_index(int *array, int size, int (*cmp)(int))
{
size_t i;
if (array == NULL || cmp == NULL || size <= 0)
return (-1);
for (i = 0; i < (size_t)size; i++)
{
if (cmp(array[i]) != 0)
return (i);
}
return (-1);
}
