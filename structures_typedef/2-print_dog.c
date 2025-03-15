#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializes a variable of type struct dog.
 * @d: Pointer to struct dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;
d->name = name;
d->age = age;
d->owner = owner;
}
#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_dog - Prints the details of a struct dog.
 * @d: Pointer to the struct dog to print.
 */
void print_dog(struct dog *d)
{
if (d == NULL)
return;
printf("Name: %s\n", (d->name) ? d->name : "(nil)");
printf("Age: %.6f\n", d->age);
printf("Owner: %s\n", (d->owner) ? d->owner : "(nil)");
}
