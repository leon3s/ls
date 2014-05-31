/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:40:20 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 21:51:19 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	push_dirs(t_file *ret, int *len)
{
	if (((lstat(ret->src, &ret->info)) == -1))
	{
		perror(ret->src);
		return (1);
	}
	if (!(ret->uid = getpwuid(ret->info.st_uid)))
	{
		ret->acces = 1;
		return (1);
	}
	if (!(ret->grp = getgrgid(ret->info.st_gid)))
	{
		ret->acces = 1;
		return (1);
	}
	biglen(ret, len);
	return (1);
}

char	map_hash(char mask, t_thash *topt, t_hash *opt, t_file *ret)
{
	if (OPTION_T(mask))
	{
		if (!(ft_insert_telm(ret->info.st_mtime, ret, topt
						, sizeof(ret->info.st_mtime) - 1)))
			return (0);
	}
	else if (!(ft_insert_elm((const unsigned char *)ret->name, ret, opt)))
		return (0);
	return (1);
}
