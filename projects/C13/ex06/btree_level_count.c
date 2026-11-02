/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:18:17 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 15:31:46 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	lc;
	int	rc;
	int	maxc;

	if (root == 0)
		return (0);
	lc = btree_level_count(root->left);
	rc = btree_level_count(root->right);
	maxc = lc;
	if (rc > maxc)
		maxc = rc;
	return (1 + maxc);
}
