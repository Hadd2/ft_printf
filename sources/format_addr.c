/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:02:53 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 21:28:59 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_addr.h"
#include "numbers.h"
#include "utils.h"

static void	left_fill_addr(t_token *token, char *p, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(p);
	ft_putnstr(token, "0x", 2);
	ft_putnstr(token, p, len);
	ft_putnchar(token, ' ', size - len - 2);
}

static void	right_fill_addr(t_token *token, char *p, unsigned int size)
{
	unsigned int	len;

	len = ft_strlen(p);
	ft_putnchar(token, ' ', size - len - 2);
	ft_putnstr(token, "0x", 2);
	ft_putnstr(token, p, ft_strlen(p));
}

static void	handle_nil_addr(t_token *token)
{
	unsigned int	len;
	unsigned int	size;

	len = ft_strlen("(nil)");
	size = len;
	if (len < token->width)
		size = token->width;
	if (!token->left)
		ft_putnchar(token, ' ', size - len);
	ft_putnstr(token, "(nil)", len);
	if (token->left)
		ft_putnchar(token, ' ', size - len);
}

void	fill_format_addr(t_token *token, void *addr)
{
	char			*p;
	unsigned int	size;
	unsigned int	len;

	if (!addr)
		return (handle_nil_addr(token));
	p = ft_itoa_unknown_base(token, (uint64_t)addr);
	if (p)
	{
		len = ft_strlen(p);
		size = len + 2;
		if (token->width > size)
			size = token->width;
		if (token->left)
			left_fill_addr(token, p, size);
		else
			right_fill_addr(token, p, size);
		free(p);
	}
}
