#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 * Return: the address of the loop node
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *start = head, *coyote = head;

    while (coyote && coyote->next)
    {
        coyote = coyote->next->next;
        start = start->next;
        if (coyote == start)
        {
            start = head;
            while (start != coyote)
            {
                start = start->next;
                coyote = coyote->next;
            }
            return (coyote);
        }
    }
    return (NULL);
}