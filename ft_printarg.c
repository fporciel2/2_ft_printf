/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:47:28 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/11 17:34:16 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This function is meant to print the variadic arguments in the right order.
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

static int  ft_printstr(char *str)
{
    if (str)
        return ((int)write(1, str, ft_strlen(str)));
    else
        return (-1);
}

int ft_printarg(char **s, char **s1, int num, va_list *ap)
{
    *s1 += 2;
    *s = *s1;
    if (*(s1 - 1) == 99)
        return ((int)write(1, va_arg(*ap, char), 1));
    else if (*(s1 - 1) == 115)
        return (ft_printstr(va_arg(*ap, char *)));
    else if (*(s1 - 1) == 112)
        return (ft_printstr(ft_voidtoa(va_arg(*ap, void *))));
    else if ((*(s1 - 1) == 100) || (*(s1 - 1) == 105))
        return (ft_printstr(ft_itoa(va_arg(*ap, int))));
    else if (*(s1 - 1) == 117)
        return (ft_printstr(ft_uitoa(va_arg(*ap, unsigned int))));
    else if (*(s1 - 1) == 120)
        return (ft_printstr(ft_hextoa(va_arg(*ap, unsigned int))));
    else if (*(s1 - 1) == 88)
        return (ft_printstr(ft_capitalhextoa(*ap, unsigned int)));
}
