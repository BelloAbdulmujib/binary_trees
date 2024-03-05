Task 21.
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	queue < binary_tree_t * > q;
	q.push(tree);
	bool flag = false;

	while (!q.empty())
	{
	binary_tree_t *temp = q.front();

	q.pop();

	if (temp->left)
	{
		if (flag == true)
		return (0);
		q.push(temp->left);
	}
	else
		flag = true;

	if (temp->right)
	{
		if (flag == true)	
		return (0);
		q.push(temp->right);
	}
	else
		flag = true;
	}

		return (1);
}


int main(void)
{
	binary_tree_t *root = NULL;

	if (binary_tree_is_complete(root))
	printf("The tree is a complete binary tree.\n");
	else
	printf("The tree is NOT a complete binary tree.\n");

	return (0);
}
