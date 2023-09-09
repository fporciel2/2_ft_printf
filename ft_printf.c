/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:50:15 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/09 12:56:50 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This is the ft_printf function. It takes a formatted string followed by
* variadic arguments, it prints on screen the formatted string. The variadic
* arguments are used to pass to the function the values corresponding to the
* format specifiers.
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

static int  ft_handle_spec(const char *s, const char *s1, va_list ap, int num)
{
    (void)format;
    (void)index;
    (void)args;
    (void)result;
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list     args;
    const char  *index = format;
    int         result;

    if (format == NULL)
        return (-1);
    while (*index && (*index != 37))
        index++;
    result = 0;
    if (!(*index))
        return ((int)write(1, format, (size_t)(index - format)));
    if (index - format)
    {
        result = (int)write(1, format, (size_t)(index - format));
        if (result < 0)
            return (result);
    }
    va_start(args, format);
    result = ft_handle_spec(format, index, args, result);
    va_end(args);
    return (result);
}
