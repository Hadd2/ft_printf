/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:47:55 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 22:41:09 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	i++;
	s--;
	while (i--)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s--;
	}
	return ((char *)0);
}
