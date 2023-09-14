#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: The height of the binary tree, 0 if `tree` is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = binary_tree_height(tree->left);
		right = binary_tree_height(tree->right);
		return (1 + ((right >= left) ? right : left));
	}

	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Balance factor of the binary tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * sub_tree_perfect - Checks if a subtree is perfect
 * @tree: Pointer to the root node of the subtree to check
 *
 * Return: 1 if the subtree is perfect, 0 otherwise
 */
int sub_tree_perfect(const binary_tree_t *tree)
{
	if (tree && !tree->right & !tree->left)
		return (1);

	if (tree && tree->right && tree->left)
		return (1 && sub_tree_perfect(tree->left)
		&& sub_tree_perfect(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree to check
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_height(tree) != 0)
		return (0);

	return (sub_tree_perfect(tree->left) && sub_tree_perfect(tree->right));
}
