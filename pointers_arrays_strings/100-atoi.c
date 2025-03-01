#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: Pointer to the string
 * Return: The converted integer, or 0 if no numbers are found
 */
int _atoi(char *s)
{
int i = 0, sign = 1, num = 0, found_digit = 0;
while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
else if (s[i] >= '0' && s[i] <= '9')
{
num = num * 10 + (s[i] - '0');
found_digit = 1;
}
else if (found_digit)
break;
i++;
}
return (num *sign);
}
