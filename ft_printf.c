/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:50:15 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/05 06:03:42 by fporciel         ###   ########.fr       */
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

static int ft_calculate_output(va_list args, char **index)
{
    const char  *start = *index;

    while (**index)
    {
        if (ft_is_format_specifier(*index))
            output = ft_print_specified_argument(&start, index, args, output);
        else if (*((*index) + 1) == 37)
            output = ft_print_percent_symbol(&start, index, output);
        else
        {
            *index++;
            start++;
            while (**index && (**index != 37))
                (*index)++;
        }
    }
}

int ft_printf(const char *format, ...)
{
    va_list     args;
    const char  *index = format;
    int         output;

    output = 0;
    while (*index && (*index != 37))
        index++;
    if (*index == 37)
    {
        if ((index - format) > 0)
            output = (int)write(1, format, (size_t)(index - format));
        if (output < 0)
            return (output);
        va_start(args, format);
        output = ft_calculate_output(args, &index, output);
        va_end(args);
    }
    else
        return ((int)write(1, format, (size_t)(index - format)));
    return (output);
}
