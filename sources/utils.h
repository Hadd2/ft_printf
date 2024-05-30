/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habernar <habernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:26:36 by habernar          #+#    #+#             */
/*   Updated: 2024/05/30 21:11:15 by habernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../ft_printf.h"

void	ft_putnstr(t_token *token, const char *str, unsigned int len);
void	ft_putnchar(t_token *token, char c, unsigned int n);
int		max(unsigned int a, unsigned int b);

#endif
