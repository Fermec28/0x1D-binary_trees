#include "binary_trees.h"

/**
 * node_is_complete - checks if a binary tree is complete
 * @node: node to evaluate
 * Return: 1 if its complete 0 if not
 */
int node_is_complete(const binary_tree_t *node)
{
	if ((node && node->left && node->right))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree.
 *@tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		return (right);
	}
	return (0);
}
/**
 * check_complete_level - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @level: pointer to a function to call for each node.
 * Return: true if its complete
 */
int check_complete_level(const binary_tree_t *tree, int level)
{
	if (tree)
	{
		int left_v = 0, right_v = 0;

		if (level == 1)
			return (node_is_complete(tree));
		left_v = check_complete_level(tree->left, level - 1);
		right_v = check_complete_level(tree->right, level - 1);
		return (left_v || right_v);
	}
	return (0);
}
/**
 * check_left_level - check especific level contain left node
 * @tree: pointer to the root node of the tree to traverse
 * @flag: flag to determinate if has left
 * @level: pointer to a function to call for each node.
 * Return: true if its complete
 */
int check_left_level(const binary_tree_t *tree, int level, int *flag)
{

	if (tree)
	{
		if (level == 1)
		{
			if (*flag && tree->right == NULL)
				*flag = 0;
			if (*flag == 1 && tree->right == NULL && tree->left == NULL)
				return (1);
			if (tree->left == NULL && *flag)
				return (0);
			if (*flag == 0 && (tree->right || tree->left))
				return (0);
			return (1);
		}
		else
		{
			int left_v = 0, right_v = 0;

			left_v = check_left_level(tree->left, level - 1, flag);
			right_v = check_left_level(tree->right, level - 1, flag);
			return (left_v && right_v);
		}
	}
	return (0);
}
/**
 * binary_tree_is_complete -checks if a binary tree is complete
 * @tree: tree to evaluate if is complete
 * Return: 1 if its complete 0 if not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int aux = 1, level = 1, t;

	if (tree)
	{
		t = binary_tree_height(tree);
		while (level < t  && aux)
		{
			aux = check_complete_level(tree, level);
			level++;
		}
		if (t == 0)
			return (1);
		if (aux)
			return (check_left_level(tree, t, &aux));
	}
	else
	{
		return (0);
	}
	return (0);
}
