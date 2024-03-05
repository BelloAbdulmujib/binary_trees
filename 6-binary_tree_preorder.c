#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs pre-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node (takes an int parameter).
 *
 * Description: The function visits each node in the tree using pre-order
 * traversal (Root-Left-Right) and applies the provided function to the value
 * stored in each node.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	return;

	func(tree->n);

	binary_tree_preorder(tree->left, func);

	binary_tree_preorder(tree->right, func);
}
