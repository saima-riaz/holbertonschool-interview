#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of list
 * @number: number to be inserted
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    listint_t *current;

    if (!new_node)
        return (NULL);

    new_node->n = number;

    // If list is empty or number should be inserted at the head
    if (!*head || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }
    current = *head;
    // Find the correct position to insert
    while (current->next && current->next->n < number)
        current = current->next;

    // Insert new node
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}

