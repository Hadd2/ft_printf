/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:28:11 by habernar          #+#    #+#             */
/*   Updated: 2024/06/13 21:51:55 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	reset_token(t_token *token)
{
	token->left = 0;
	token->zero_pad = 0;
	token->prefix = 0;
	token->blank = 0;
	token->sign = 0;
	token->precision = 0;
	token->num_precision = 0;
	token->width = 0;
	token->count = 0;
	token->type = TYPE_UNINIT;
}

int	is_valid_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%')
		return (1);
	return (0);
}

int	is_flags(char c)
{
	if (c == '0' || c == '#' || c == ' '
		|| c == '+' || c == '-')
		return (1);
	return (0);
}
