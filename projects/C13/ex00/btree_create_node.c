/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: losabati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 15:42:52 by losabati          #+#    #+#             */
/*   Updated: 2026/10/27 15:46:37 by losabati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*ele;

	ele = malloc(sizeof(t_btree));
	if (ele == NULL)
		return (NULL);
	ele->left = NULL;
	ele->right = NULL;
	ele->item = item;
	return (ele);
}
