/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:12:06 by habernar          #+#    #+#             */
/*   Updated: 2024/06/13 21:55:51 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include "includes/libft.h"

# define PREFIXLOHEX "0x"
# define PREFIXUPHEX "0X"
# define SIZEPREFIX 2
# define BASE_LOHEX "0123456789abcdef"
# define BASE_UPHEX "0123456789ABCDEF"
# define BASE_DECI "0123456789"
# define STR_NULL "(null)"
# define ADDR_NIL "(nil)"

typedef enum e_type
{
	TYPE_CHAR,
	TYPE_STR,
	TYPE_ADDR,
	TYPE_DECI,
	TYPE_INT,
	TYPE_UINT,
	TYPE_LOHEX,
	TYPE_UPHEX,
	TYPE_MOD,
	TYPE_ERROR,
	TYPE_UNINIT
}	t_type;

typedef struct s_token
{
	bool			left;
	bool			zero_pad;
	bool			prefix;
	bool			blank;
	bool			sign;
	bool			precision;
	unsigned int	num_precision;
	unsigned int	width;
	unsigned int	count;
	t_type			type;
}	t_token;

int		ft_printf(const char *buffer, ...);
int		is_flags(char c);
int		is_valid_type(char c);
int		max(unsigned int a, unsigned int b);
void	reset_token(t_token *token);
void	scan_token(t_token *token, const char **buf);
void	parse_token(t_token *token, va_list params);
void	fill_format_uint(t_token *token, unsigned int u);
void	fill_format_str(t_token *token, char *str);
void	fill_format_int(t_token *token, int d);
void	fill_format_char(t_token *token, int c);
void	fill_format_addr(t_token *token, void *addr);
void	ft_putnstr(t_token *token, const char *str, unsigned int len);
void	ft_putnchar(t_token *token, char c, unsigned int n);
char	*ft_itoa_unknown_base(t_token *token, uint64_t num);

#endif
