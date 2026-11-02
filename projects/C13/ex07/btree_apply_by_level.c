/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:21:46 by losabati          #+#    #+#             */
/*   Updated: 2026/10/28 16:55:58 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	ft_push(t_qelem **head, t_qelem **tail, t_btree *node, int level)
{
	t_qelem	*new;

	if (!node)
		return ;
	new = malloc(sizeof(t_qelem));
	if (!new)
		return ;
	new->node = node;
	new->level = level;
	new->next = NULL;
	if (*tail)
		(*tail)->next = new;
	else
		*head = new;
	*tail = new;
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_qelem	*head;
	t_qelem	*tail;
	t_qelem	*cur;
	int		last;

	if (!root || !applyf)
		return ;
	head = NULL;
	tail = NULL;
	last = -1;
	ft_push(&head, &tail, root, 0);
	while (head)
	{
		cur = head;
		applyf(cur->node->item, cur->level, cur->level != last);
		last = cur->level;
		ft_push(&head, &tail, cur->node->left, cur->level + 1);
		ft_push(&head, &tail, cur->node->right, cur->level + 1);
		head = cur->next;
		free(cur);
		if (!head)
			tail = NULL;
	}
}
