#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - print name.
 * @name: print name.
 * @f: take name form func.
 */
void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
{
f(name);
}
}
