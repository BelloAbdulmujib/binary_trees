#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;


        return is_max_heap(tree);
}


/**
 * is_max_heap - Recursive helper function to check Max Heap properties.
 * @node: Current node being checked.
 *
 * Return: 1 if subtree rooted at 'node' is a valid Max Binary Heap, 0 otherwise.
 */
int is_max_heap(const binary_tree_t *node)
{
    if (node == NULL)
        return 1;


        if (node->left && node->left->n > node->n)
        return 0;
    if (node->right && node->right->n > node->n)
        return 0;


    return is_max_heap(node->left) && is_max_heap(node->right);
}
