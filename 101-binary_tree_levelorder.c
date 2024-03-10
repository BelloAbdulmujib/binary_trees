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
	binary_tree_t *queue[1000];
	int front = 0, rear = 0;
	binary_tree_t *current = queue[front++];

	if (tree == NULL || func == NULL)
	return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{

	func(current->n);

	if (current->left)
	queue[rear++] = current->left;

	if (current->right)
	queue[rear++] = current->right;
	}
}
