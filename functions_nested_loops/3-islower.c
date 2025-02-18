#include "main.h"
/**
 * _islower - checks for lowercase character.
 * @c: the char to check
 *
 * Return: 1 is lowercase, 0 ohterwise
*/
int _islower(int c)
{
if (c >= 'a' && c <= 'z')
return (1);
else
return (0);
}
