#include <stdlib.h>
#include "binary_trees.h"


/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (!tree)
        return NULL;
    if (*tree == NULL)
    {
        *tree = malloc(sizeof(bst_t));
        if (!*tree)
            return NULL;
        (*tree)->n = value;
        (*tree)->parent = NULL;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        return *tree;
    }


    bst_t *current = *tree;
    while (current)
    {
        if (value < current->n)
        {
            if (current->left)
                current = current->left;
            else
            {
                current->left = malloc(sizeof(bst_t));
                if (!current->left)
                    return NULL;
                current->left->n = value;
                current->left->parent = current;
                current->left->left = NULL;
                current->left->right = NULL;
                return current->left;
            }
        }
        else if (value > current->n)
        {
            if (current->right)
                current = current->right;
            else
            {
                current->right = malloc(sizeof(bst_t));
                if (!current->right)
                    return NULL;
                current->right->n = value;
                current->right->parent = current;
                current->right->left = NULL;
                current->right->right = NULL;
                return current->right;
            }
        }
        else
        {
            return NULL;
        }
    }


    return NULL;
}
