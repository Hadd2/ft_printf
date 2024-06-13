/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:22:34 by habernar          #+#    #+#             */
/*   Updated: 2024/06/13 21:52:20 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnstr(t_token *token, const char *str, unsigned int len)
{
	while (*str && len--)
		token->count += write(1, str++, 1);
}

void	ft_putnchar(t_token *token, char c, unsigned int n)
{
	while (n--)
		token->count += write(1, &c, 1);
}

int	max(unsigned int a, unsigned int b)
{
	if (a < b)
		return (b);
	return (a);
}
