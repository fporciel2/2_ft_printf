/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:42:01 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/09 18:12:07 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This file is meant to evaluate the part of string after the percent symbol. It
* checks if the percent symbol represents a format specifier or not, and then it
* returns the number of increments to assign to the pointer that indexes the 
* formatted string to point to the byte following the format specifier.
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

int ft_isfspec(const char *s1)
{
    if ((*s1 == 99) || (*s1 == 115) || (*s1 == 112) || (*s1 == 100)
            || (*s1 == 105) || (*s1 == 117) || (*s1 == 120) || (*s1 == 88))
        return (2);
    else
        return (-1);
}
