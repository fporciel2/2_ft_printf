/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:52:02 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/22 11:52:04 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(unsigned long long int n, char *hexa, int *i)
{
	if (n < 16)
	{
		handle_c(hexa[n]);
		*i = *i + 1;
	}
	else
	{
		print_hexa(n / 16, hexa, i);
		print_hexa(n % 16, hexa, i);
	}
}

int	handle_void(void *p)
{
	char						*hexa;
	unsigned long long int		number;
	int							i;

	i = 0;
	number = (unsigned long long int)p;
	hexa = "0123456789abcdef";
	write(1, "0x", 2);
	print_hexa(number, hexa, &i);
	return (i + 2);
}
