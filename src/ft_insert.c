/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 03:29:39 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 16:27:48 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	ft_insert_elm(t_cast *name, t_file *ret, t_hash *opt)
{
	if (!(*name))
	{
		opt->content = ret;
		return (1);
	}
	if (!(*(opt->hash + (*name - 1))))
	{
		if (!(*(opt->hash + (*name - 1)) = malloc(sizeof(**opt->hash))))
			return (0);
		ft_bzero(*(opt->hash + (*name - 1)), sizeof(**opt->hash));
	}
	return (ft_insert_elm(name + 1, ret, *(opt->hash + (*name - 1))));
}

char	ft_insert_telm(time_t time, t_file *ret, t_thash *opt
												, const size_t pow)
{
	if (!pow)
	{
		if (!(*(opt->hash + (time % 256))))
		{
			if (!(MOVEA(time, pow) = malloc(sizeof(**opt->hash))))
				return (0);
			ft_bzero(MOVEA(time, pow), sizeof(**opt->hash));
		}
		if (!((*(opt->hash + (time % 256)))->content))
		{
			if (!(MOVEC(time, pow) = malloc(sizeof(*opt->content))))
				return (0);
			ft_bzero(MOVEC(time, pow), sizeof(*opt->content));
		}
		return (ft_insert_elm((t_cast *)ret->name, ret, MOVEC(time, pow)));
	}
	if (!(MOVEA(time, pow)))
	{
		if (!(MOVEA(time, pow) = malloc(sizeof(**opt->hash))))
			return (0);
		ft_bzero(MOVEA(time, pow), sizeof(**opt->hash));
	}
	return ((ft_insert_telm(time, ret, MOVEA(time, pow), pow - 1)));
}
