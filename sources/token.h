/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:42:36 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 19:17:39 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "../ft_printf.h"

void	reset_token(t_token *token);
int		is_valid_type(char c);
int		is_flags(char c);

#endif
