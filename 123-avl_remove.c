#include <stdlib.h>
#include "binary_trees.h"


/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the desired value,
 *         and after rebalancing, or NULL on failure.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return (NULL);


    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
       
        if (root->left == NULL || root->right == NULL)
        {
            avl_t *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        avl_t *temp = avl_find_min(root->right);
        root->n = temp->n;
        root->right = avl_remove(root->right, temp->n);
    }


        root = avl_balance(root);


    return root;
}


/**
 * avl_find_min - Finds the minimum value node in an AVL tree.
 * @node: Pointer to the root node of the tree.
 *
 * Return: Pointer to the minimum value node.
 */
avl_t *avl_find_min(avl_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}


/**
 * avl_balance - Rebalances the AVL tree after deletion.
 * @node: Pointer to the root node of the tree.
 *
 * Return: Pointer to the new root node after rebalancing.
 */
avl_t *avl_balance(avl_t *node)
{
    // Implement AVL tree balancing logic here
    // (rotations, height updates, etc.)
    // You need to handle different cases (Left Left, Left Right, Right Right, Right Left)
    // See references for details.


    // Placeholder implementation (replace with actual logic)
    return node;
}
