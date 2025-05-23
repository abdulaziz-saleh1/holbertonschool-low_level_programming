#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
* add_node - adds a new node at the beginning of a list_t list
* @head: pointer to the pointer to the head of the list
* @str: string to duplicate and add to the list
*
* Return: address of the new element, or NULL if it failed
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
unsigned int i = 0;
if (head == NULL || str == NULL)
return (NULL);
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);
new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}
while (str[i])
i++;
new_node->len = i;
new_node->next = *head;
*head = new_node;
return (new_node);
}
