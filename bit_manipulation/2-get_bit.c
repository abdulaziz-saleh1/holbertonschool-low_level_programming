#include "main.h"

/**
* get_bit - returns the value of a bit at a given index
* @n: number to check
* @index: index of the bit (starting from 0)
*
* Return: value of bit (0 or 1), or -1 if error
*/
int get_bit(unsigned long int n, unsigned int index)
{
if (index >= (sizeof(n) * 8))
return (-1);

return ((n >> index) & 1);
}
