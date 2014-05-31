/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 14:42:30 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 14:44:05 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myls.h"

char	is_hidden_file(const char *str)
{
	if ((*(str) == '.' && *(str + 1) == '.' && !(*(str + 2)))
			|| (*(str) == '.' && !(*(str + 1))))
		return (0);
	return (1);
}
