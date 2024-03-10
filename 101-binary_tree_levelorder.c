#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_levelorder - Traverses a binary tree
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int front = 0, rear = 0;
	binary_tree_t *current = queue[front++];
	func(current->n);
	binary_tree_t *queue[1000];
	queue[rear++] = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
	return;

	while (front < rear)
	{
	if (current->left)
	queue[rear++] = current->left;

	if (current->right)
	queue[rear++] = current->right;
	}
}
