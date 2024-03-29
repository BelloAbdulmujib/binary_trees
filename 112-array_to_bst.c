#include <stdlib.h>
#include "binary_trees.h"
/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	if (!array || size == 0)
	return (NULL);

	bst_t *root = NULL;

	for (size_t i = 0; i < size; ++i)
	{

	if (bst_insert(&root, array[i]) == NULL)
		{
			bst_free(root)
			return (NULL);
		}
	}

	return (root);
}
