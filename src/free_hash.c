/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 04:13:28 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:55:58 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

void	free_hash(t_hash *ptr)
{
	int		count;
	t_file	*lst;

	count = -1;
	while (++count < 256)
	{
		if (*(ptr->hash + count))
		{
			free_hash(*(ptr->hash + count));
			free(*(ptr->hash + count));
		}
	}
	if (ptr->content)
	{
		lst = ptr->content;
		free(lst->src);
		free(lst->name);
		free(lst);
	}
}

void	free_thash(t_thash *opt)
{
	size_t	cn;

	cn = -1;
	if (opt->content)
	{
		free_hash(opt->content);
		free(opt->content);
	}
	while (++cn < 256)
	{
		if (*(opt->hash + cn))
		{
			free_thash(*(opt->hash + cn));
			free((*(opt->hash + cn)));
		}
	}
}
