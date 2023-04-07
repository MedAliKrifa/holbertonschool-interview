#include "binary_trees.h"
/**
 * swap - Swaps the values of two heap nodes.
 * @a: A pointer to the first node.
 * @b: A pointer to the second node.
 */

void swap(heap_t *a, heap_t *b)
{
    int tmp;

    tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * heapify_up - Moves a node up the heap until it is in the correct position.
 * @node: A pointer to the node to move.
 */
void heapify_up(heap_t *node)
{
    if (node->parent && node->n > node->parent->n)
    {
        swap(node, node->parent);
        heapify_up(node->parent);
    }
}

/**
 * heapify_down - Moves a node down the heap until it is in the correct position.
 * @node: A pointer to the node to move.
 */
void heapify_down(heap_t *node)
{
    heap_t *max = node;

    if (node->left && node->left->n > max->n)
    {
        max = node->left;
    }
    if (node->right && node->right->n > max->n)
    {
        max = node->right;
    }

    if (max != node)
    {
        swap(node, max);
        heapify_down(max);
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent, *current;
    int bits = 0;

    if (root == NULL)
    {
        return NULL;
    }

    /* Find the parent of the new node. */
    current = *root;
    while (current)
    {
        parent = current;
        bits++;
        current = (value >> (bits - 1)) & 1 ? current->right : current->left;
    }

    /* Create the new node. */
    new_node = malloc(sizeof(heap_t));
    if (new_node == NULL)
    {
        return NULL;
    }
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    /* Insert the new node. */
    if (parent == NULL)
    {
        *root = new_node;
    }
    else if ((value >> (bits - 1)) & 1)
    {
        parent->right = new_node;
    }
    else
    {
        parent->left = new_node;
    }

    /* Restore the Max Heap property. */
    heapify_up(new_node);

    return new_node;
}
