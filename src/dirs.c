/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:45:10 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/21 03:54:26 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

DIR		*open_dirs(char *path, char mask, int is)
{
	DIR				*ptr;
	struct stat		tmp;

	if (((lstat(path, &tmp)) == -1))
	{
		perror(path);
		return (0);
	}
	if (!(S_ISDIR(tmp.st_mode)))
	{
		write(1, path, ft_strlen(path));
		return (0);
	}
	if ((path != NULL && OPTION_RR(mask)) || is > 0)
	{
		write(1, path, ft_strlen(path));
		write(1, " :\n", 3);
	}
	if (!(ptr = opendir(path)))
	{
		perror(path);
		return (0);
	}
	return (ptr);
}

char	is_end(char mask, t_thash *topt, t_hash *opt, int *len)
{
	if (OPTION_T(mask))
	{
		if (!(print_thash(topt, mask, len)))
			return (0);
	}
	else if (!(print_hash(opt, mask, len)))
		return (0);
	if (OPTION_RR(mask))
	{
		if (OPTION_T(mask))
		{
			if (!(recur_t(topt, mask)))
				return (0);
		}
		else if (!(recur(opt, mask)))
			return (0);
	}
	if (OPTION_T(mask))
		free_thash(topt);
	else
		free_hash(opt);
	free(len);
	return (1);
}

char	load_dir(char *path, char mask, int is)
{
	t_val	op;

	if (!(op.len = init_value(op.len, &op.topt, &op.opt)))
		return (0);
	if (!(op.ptr = open_dirs(path, mask, is)))
		return (1);
	while ((op.dir = readdir(op.ptr)))
	{
		if (!(op.ret = ft_memalloc(sizeof(*op.ret))))
			return (0);
		if (!(op.ret->name = ft_strdup(op.dir->d_name)))
			return (0);
		if (!(concat_t(path, op.ret, op.dir)))
			return (0);
#if _macosx		
		op.ret->len = op.dir->d_namlen;
#else
		op.ret->len = ft_strlen(op.ret->name);
#endif
		if (!(push_dirs(op.ret, op.len)))
			return (0);
		if (!(map_hash(mask, &op.topt, &op.opt, op.ret)))
			return (0);
	}
	closedir(op.ptr);
	if (!(is_end(mask, &op.topt, &op.opt, op.len)))
		return (0);
	return (1);
}
