/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:49:28 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/22 11:49:33 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

int		ft_printf(const char *str, ...);
void	handle_c(char c);
int		handle_str(char *str);
int		handle_void(void *p);
int		handle_decimal(int n);
int		handle_unsdec10(unsigned int n);
int		handle_hexupper(unsigned int p);
int		handle_hexlower(unsigned int p);

#endif
