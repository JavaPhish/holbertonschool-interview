#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "binary_trees.h"

/**
 * binary_tree_is_avl - Check if a binary tree is an AVL tree
 * @tree: The tree to check
 *
 * Return: 1 if its an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	int left_height, right_height;

	if (!tree)
		return (1);


	if (binary_tree_sorted(tree->right, tree->n, 1) == 0)
		return (0);

	if (binary_tree_sorted(tree->left, tree->n, 0) == 0)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) <= 1 &&
	    binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}

/**
 * binary_tree_sorted - Check if its sorted
 * @tree: The tree to check
 * @root: Root node
 * @side: right or left (1 or 0)
 *
 * Return: 1 if sorted, 0 otherwise
 */
int binary_tree_sorted(const binary_tree_t *tree, int root, int side)
{
	if (tree == NULL)
		return (1);

	if (tree->n > root && side == 0)
		return (0);

	if (tree->n < root && side == 1)
		return (0);

	if (tree->right != NULL && tree->right->n < tree->n)
		return (0);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);


	return (binary_tree_sorted(tree->right, root, side)
		  && binary_tree_sorted(tree->left, root, side));
}

/**
 * binary_tree_height - returns the height of a binary tree
 * @tree: The tree to fetch the height of
 *
 * Return: The height as Int
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (1 + left_height);

	return (1 + right_height);
}
