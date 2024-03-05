#include <stdlib.h>
#include "binary_trees.h"


/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;


        if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        if (*tree == NULL)
            return NULL;
        return *tree;
    }


    if (value < (*tree)->n)
        (*tree)->left = avl_insert(&((*tree)->left), value);
    else if (value > (*tree)->n)
        (*tree)->right = avl_insert(&((*tree)->right), value);
    else
        return NULL; 
        (*tree)->height = 1 + max(avl_height((*tree)->left), avl_height((*tree)->right));
    int balance = avl_balance(*tree);


        if (balance > 1) 
    {
        if (value < (*tree)->left->n)
            return avl_rotate_right(*tree); // Left-Left case
        else
        {
            (*tree)->left = avl_rotate_left((*tree)->left);             return avl_rotate_right(*tree);
        }
    }
    else if (balance < -1) // Right-heavy
    {
        if (value > (*tree)->right->n)
            return avl_rotate_left(*tree); // Right-Right case
        else
        {
            (*tree)->right = avl_rotate_right((*tree)->right); // Right-Left case
            return avl_rotate_left(*tree);
        }
    }


    return *tree;
}


/**
 * avl_height - Calculates the height of an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Height of the tree
 */
int avl_height(const avl_t *tree)
{
    if (tree == NULL)
        return 0;
    return tree->height;
}


/**
 * avl_balance - Calculates the balance factor of an AVL tree
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Balance factor (height of left subtree - height of right subtree)
 */
int avl_balance(const avl_t *tree)
{
    if (tree == NULL)
        return 0;
    return avl_height(tree->left) - avl_height(tree->right);
}


/**
 * avl_rotate_left - Performs a left rotation on an AVL tree
 * @y: Pointer to the root node of the subtree to rotate
 *
 * Return: Pointer to the new root of the rotated subtree
 */
avl_t *avl_rotate_left(avl_t *y)
{
    avl_t *x = y->right;
    avl_t *T2 = x->left;


    x->left = y;
    y->right = T2;


    y->height = 1 + max(avl_height(y->left), avl_height(y->right));
    x->height = 1 + max(avl_height(x->left), avl_height(x->right));


    return x;
}


/**
 * avl_rotate_right - Performs a right rotation on an AVL tree
 * @x: Pointer to the root node of the subtree to rotate
 *
 * Return: Pointer to the new root of the rotated subtree
 */
avl_t *avl_rotate_right(avl_t *x)
{
    avl_t *y = x->left;
    avl_t *T2 = y->right;


    y->right = x;
    x->left = T2;


    x->height = 1 + max(avl_height(x->left), avl_height(x->right));
    y->height = 1 + max(avl_height(y->left), avl_height(y->right));


    return y;
}
