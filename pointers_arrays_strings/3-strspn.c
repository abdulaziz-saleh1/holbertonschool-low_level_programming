#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search in
 * @accept: The characters to match
 * Return: The number of bytes in s consisting of only bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int i, match;
while (*s)
{
match = 0;
for (i = 0; accept[i]; i++)
{
if (*s == accept[i])
{
match = 1;
break;
}
}
if (!match)
break;
count++;
s++;
}
return (count);
}
