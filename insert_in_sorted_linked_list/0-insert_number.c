#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head: Pointer to a pointer to the first node of the list
 * @number: The number to be inserted
 *
 * Return: Address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new_node = NULL;
listint_t *current_node = NULL;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
{
return (NULL);
}

new_node->n = number;
new_node->next = NULL;
if (*head == NULL || (*head)->n >= number)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

current_node = *head;
while (current_node->next != NULL && current_node->next->n < number)
{
current_node = current_node->next;
}

new_node->next = current_node->next;
current_node->next = new_node;

return (new_node);
}
