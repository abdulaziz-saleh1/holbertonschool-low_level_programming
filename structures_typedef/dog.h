#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure defining a dog with name, age, and owner.
 * @name: Name of the dog (string).
 * @age: Age of the dog (float).
 * @owner: Owner of the dog (string).
 */
struct dog {
char *name;
float age;
char *owner;
};

typedef struct dog dog_t;

#endif /* DOG_H */
