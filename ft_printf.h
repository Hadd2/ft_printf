/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:12:06 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 22:57:29 by habernar         ###   ########.fr       */
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

int	ft_printf(const char *buffer, ...);

#endif
