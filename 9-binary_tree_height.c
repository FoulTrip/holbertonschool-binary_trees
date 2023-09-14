#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the binary tree, 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	while (tree->left || tree->right)
	{
		height++;
		if (binary_tree_balance(tree) > 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (height);
}
