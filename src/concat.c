/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 06:33:26 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:36:56 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	*concat_slash(char *path, char *name)
{
	size_t	len;
	char	*new;
	size_t	count;

	len = ft_strlen(path) + ft_strlen(name);
	if (!(new = malloc(sizeof(*new) * (len + 2))))
		return (0);
	len = -1;
	count = -1;
	while (*(path + ++count))
		*(new + ++len) = *(path + count);
	*(new + ++len) = '/';
	count = -1;
	while (*(name + ++count))
		*(new + ++len) = *(name + count);
	*(new + ++len) = 0;
	return (new);
}

char	*concat_string(char *path, char *name)
{
	size_t	len;
	char	*new;
	size_t	count;

	len = ft_strlen(path) + ft_strlen(name);
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		return (0);
	len = -1;
	count = -1;
	while (*(path + ++count))
		*(new + ++len) = *(path + count);
	count = -1;
	while (*(name + ++count))
		*(new + ++len) = *(name + count);
	*(new + ++len) = 0;
	return (new);
}

char	concat_t(char *path, t_file *ret, struct dirent *dir)
{
	if (*path == '/' && *(path + ft_strlen(path) - 1) == '/')
	{
		if (!(ret->src = concat_string(path, dir->d_name)))
			return (0);
	}
	else
	{
		if (!(ret->src = concat_slash(path, dir->d_name)))
			return (0);
	}
	return (1);
}
