/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:33:40 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 00:46:08 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "format_addr.h"
#include "format_int.h"
#include "format_str.h"
#include "format_char.h"
#include "format_uint.h"

void	parse_token(t_token *token, va_list params)
{
	if (token->type == TYPE_CHAR)
		fill_format_char(token, va_arg(params, int));
	else if (token->type == TYPE_STR)
		fill_format_str(token, va_arg(params, char *));
	else if (token->type == TYPE_UINT || token->type == TYPE_LOHEX
		|| token->type == TYPE_UPHEX)
		fill_format_uint(token, va_arg(params, unsigned int));
	else if (token->type == TYPE_DECI || token->type == TYPE_INT)
		fill_format_int(token, va_arg(params, int));
	else if (token->type == TYPE_ADDR)
		fill_format_addr(token, va_arg(params, void *));
	else if (token->type == TYPE_MOD)
		fill_format_char(token, '%');
}
