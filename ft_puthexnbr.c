/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:18:05 by fporciel          #+#    #+#             */
/*   Updated: 2023/03/07 12:24:32 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "ft_printf.h"

static char	*ft_reverse_hex_str(char *hex_string, int hex_len)
{
	int		i;
	int		j;
	char	buff;

	i = 0;
	j = hex_len - 1;
	while (i < j)
	{
		buff = hex_string[i];
		hex_string[i] = hex_string[j];
		hex_string[j] = buff;
		i++;
		j--;
	}
	hex_string[hex_len] = 0;
	return (hex_string);
}

static int	ft_puthexaddress1(unsigned int ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	*hexstr;
	char	hex_string[20];

	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hex_string[counter] = remainder + 48;
		else
			hex_string[counter] = remainder - 10 + 65;
		counter++;
		ap = ap / 16;
	}
	hexstr = &(hex_string[0]);
	hexstr = ft_reverse_hex_str(hexstr, hex_len);
	return (ft_putstr(hexstr));
}

static int	ft_puthexaddress(unsigned int ap, int hex_len)
{
	int		remainder;
	int		counter;
	char	*hexstr;
	char	hex_string[20];

	counter = 0;
	while (ap > 0)
	{
		remainder = ap % 16;
		if (remainder < 10)
			hex_string[counter] = remainder + 48;
		else
			hex_string[counter] = remainder - 10 + 97;
		counter++;
		ap = ap / 16;
	}
	hexstr = &(hex_string[0]);
	hexstr = ft_reverse_hex_str(hexstr, hex_len);
	return (ft_putstr(hexstr));
}

int	ft_puthexnbr(unsigned int ap, char formati)
{
	unsigned int	ap1;
	int				hex_len;
	int				result;

	if (ap == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ap1 = ap;
	hex_len = 0;
	result = 0;
	while (ap1 > 0)
	{
		ap1 = ap1 / 16;
		hex_len++;
	}
	if (formati == 'x')
		result = result + ft_puthexaddress(ap, hex_len);
	else if (formati == 'X')
		result = result + ft_puthexaddress1(ap, hex_len);
	return (result);
}
