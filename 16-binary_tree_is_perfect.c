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

		right = binary_tree_height(tree->right);
		left = binary_tree_height(tree->left);
		return (1 + ((left >= right) ? left : right));
	}

	return (0);
}

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: nodes with at least 1 child in the tree, or 0 if tree is NULL;
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	
	left += binary_tree_nodes(tree->left);
	right += binary_tree_nodes(tree->right);
	
	if (tree->left != NULL && tree->right != NULL)
		return (left + right + 1);
	else
		return (left + right + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the binary tree to check
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int firstValue = 0, secondValue = 0;

	if (tree == NULL)
		return (0);
	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
		firstValue = 1;
	if (binary_tree_nodes(tree->left) == binary_tree_nodes(tree->right))
		secondValue = 1;
	if (firstValue == 1 && secondValue == 1)
		return (1);
	else
		return (0);
}
