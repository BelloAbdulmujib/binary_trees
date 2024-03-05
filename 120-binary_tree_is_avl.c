#include <stdlib.h>
#include "binary_trees.h" // Assuming you have a header file for binary trees


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0); // Empty tree is not an AVL Tree


    // Check if the tree is a valid BST
    // (You can implement this part based on your existing BST validation logic)


    // Check if the difference between heights of left and right subtrees
    // is not more than one
    // (You can implement this part based on your existing height calculation logic)


    // Recursively check if left and right subtrees are also AVL trees
    // (You can implement this part by calling binary_tree_is_avl recursively)


    // If all conditions are met, return 1 (valid AVL Tree)
    // Otherwise, return 0


        return (0);
}
