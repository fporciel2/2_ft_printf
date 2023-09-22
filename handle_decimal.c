/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:50:21 by fporciel          #+#    #+#             */
/*   Updated: 2023/09/22 11:50:24 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decimal(int n, char *dec, int *i)
{
	if (n < 0)
	{
		handle_c('-');
		*i = *i + 1;
		if (n == -2147483648)
		{
			handle_c('2');
			*i = *i + 1;
			n = 147483648;
		}
		else
			n = -n;
	}
	if (n < 10)
	{
		handle_c(dec[n]);
		*i = *i + 1;
	}
	else
	{
		print_decimal(n / 10, dec, i);
		print_decimal(n % 10, dec, i);
	}
}

int	handle_decimal(int n)
{
	char	*dec;
	int		i;

	i = 0;
	dec = "0123456789";
	print_decimal(n, dec, &i);
	return (i);
}
