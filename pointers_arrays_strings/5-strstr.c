#include "main.h"

/**
*_strstr - Locates a substring
*@haystack: The main string to search in
*@needle: The substring to find
*Return: Pointer to the beginning of the located substring,
*or NULL if not found
*/
char *_strstr(char *haystack, char *needle)
{
char *h, *n;
if (*needle == '\0')
return (haystack);
while (*haystack)
{
h = haystack;
n = needle;
while (*h && *n && (*h == *n))
{
h++;
n++;
}
if (*n == '\0')
return (haystack);
haystack++;
}
return (NULL);
}
