/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:07:17 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 22:59:47 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_str.h"

static unsigned int	get_len(t_token *token, char *str)
{
	unsigned int	len;

	len = ft_strlen(str);
	if (token->precision && token->num_precision < len)
	{
		if (ft_strncmp(str, STR_NULL, ft_strlen(str)) == 0)
			len = 0;
		else
			len = token->num_precision;
	}
	return (len);
}

static unsigned int	get_size(t_token *token, unsigned int len)
{
	if (token->width > len)
		return (token->width);
	return (len);
}

static void	handle_null_ptr(t_token *token)
{
	unsigned int	len;
	unsigned int	size;

	len = get_len(token, STR_NULL);
	size = get_size(token, len);
	if (!token->left)
		ft_putnchar(token, ' ', size - len);
	ft_putnstr(token, STR_NULL, len);
	if (token->left)
		ft_putnchar(token, ' ', size - len);
}

void	fill_format_str(t_token *token, char *str)
{
	size_t	size;
	size_t	len;

	if (!str)
		return (handle_null_ptr(token));
	len = get_len(token, str);
	size = get_size(token, len);
	if (!token->left)
		ft_putnchar(token, ' ', size - len);
	ft_putnstr(token, str, len);
	if (token->left)
		ft_putnchar(token, ' ', size - len);
}
