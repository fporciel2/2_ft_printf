/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:50:15 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/11 16:45:24 by fporciel         ###   ########.fr       */
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

static int  ft_endprint(const char *s, const char *s1, int num)
{
    int swap_num;

    if (s1 - s)
        swap_num = (int)write(1, s, (size_t)(s1 - s));
    if (swap_num < 0)
        return (-1);
    num += swap_num;
    return (num);
}

static int  ft_slideformat(char **s1)
{
    while (**s1 && (**s1 != 37))
        (*s1)++;
    if (**s1 == 0)
        return (1);
    else
        return (0);
}

static void ft_handlepercent(char **s, char **s1, int *swap_num)
{
    if (*(*s1 + 1) == 37)
    {
        *swap_num = (int)write(1, (*s1 + 1), 1);
        *s1 += 2;
        *s = *s1;
    }
    else
    {
        *swap_num = 0;
        (*s1)++;
        *s = *s1;
    }
}

static int  ft_handle_spec(const char *s, const char *s1, va_list ap, int num)
{
    int swap_num;

    while (*s1)
    {
        swap_num = 0;
        if (s1 - s)
            swap_num = (int)write(1, s, (size_t)(s1 - s));
        if (swap_num < 0)
            return (-1);
        num += swap_num;
        swap_num = ft_isfspec(s1 + 1);
        if (swap_num == -1)
            ft_handlepercent(&s, &s1, &swap_num);
        else
            swap_num = ft_printarg(&s, &s1, swap_num, &ap);
        if (swap_num < 0)
            return (-1);
        num += swap_num;
        if (ft_slideformat(&s1))
            break ;
    }
    return (ft_endprintf(s, s1, num));
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
    va_start(args, format);
    result = ft_handle_spec(format, index, args, result);
    va_end(args);
    return (result);
}
