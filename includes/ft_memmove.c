/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 22:48:09 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 22:39:55 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*head;

	if (!dest && !src)
		return (0);
	head = dest;
	if (dest < src)
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	else
	{
		while (n--)
		{
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
		}
	}
	return (head);
}
