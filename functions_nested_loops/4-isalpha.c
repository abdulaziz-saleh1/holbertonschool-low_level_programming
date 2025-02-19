#include "main.h"
/**
 * _isalpha - Checks if a char is an alphabetic letter
 * @c: The character to check
 *
 * Return: 1 if the char is a letter (uppercase or lowercase), 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
