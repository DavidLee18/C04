/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:23:14 by jaehylee          #+#    #+#             */
/*   Updated: 2024/08/22 15:23:14 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(STDOUT_FILENO, "-2147483648", 11);
	else if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		c = '0' + n;
		write(STDOUT_FILENO, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		c = '0' + n % 10;
		write(STDOUT_FILENO, &c, 1);
	}
}
