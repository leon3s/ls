/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lverniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 22:05:31 by lverniss          #+#    #+#             */
/*   Updated: 2014/04/20 15:05:49 by lverniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *ptr, size_t len);
void	ft_error(char *str);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr(size_t nb);
size_t	ft_nblen(size_t nb);
void	*ft_memalloc(size_t size);

#endif
