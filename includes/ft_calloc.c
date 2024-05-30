/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:54:52 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 22:38:30 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;	
	void	*head;	
	size_t	bytes;

	bytes = size * nmemb;
	ret = (void *)malloc(bytes);
	if (!ret)
		return (0);
	head = ret;
	while (bytes--)
		*(unsigned char *)ret++ = 0;
	return (head);
}
