#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings up to n bytes from s2.
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of bytes from s2 to include.
 *
 * Return: Pointer to the new concatenated string, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat;
unsigned int len1 = 0, len2 = 0, i, j;
if (s1 != NULL)
while (s1[len1] != '\0')
len1++;
if (s2 != NULL)
while (s2[len2] != '\0')
len2++;
if (n >= len2)
n = len2;
concat = malloc(sizeof(char) * (len1 + n + 1));
if (concat == NULL)
return (NULL);
for (i = 0; i < len1; i++)
concat[i] = s1[i];
for (j = 0; j < n; j++)
concat[i + j] = s2[j];
concat[i + j] = '\0';
return (concat);
}
