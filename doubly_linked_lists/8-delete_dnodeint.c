#include <stdlib.h>
#include "lists.h"
/**
* delete_dnodeint_at_index - deletes node at a given index in a dlistint_t list
* @head: double pointer to the head of the list
* @index: index of the node to delete
*
* Return: 1 if success, -1 if failure
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp = *head;
unsigned int i = 0;
if (*head == NULL)
return (-1);
if (index == 0)
{
*head = temp->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
return (1);
}
while (temp != NULL && i < index)
{
temp = temp->next;
i++;
}
if (temp == NULL)
return (-1);
if (temp->prev != NULL)
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
free(temp);
return (1);
}
