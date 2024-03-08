#include "binary_trees.h"


/**
 * binary_tree_uncle - Finds the uncle of a given node.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if not found.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	binary_tree_t *grandparent = node->parent;

	if (grandparent == NULL)
		return (NULL);
	if (grandparent->left == node->parent)
		return (grandparent->right);
	else
		return (grandparent->left);
}
