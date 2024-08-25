/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:59:43 by jaehylee          #+#    #+#             */
/*   Updated: 2024/08/22 15:59:43 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	elem(char c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}

void	ft_putnbr_base(int n, char *base);

void	putneg(int n, char *base)
{
	if (n == -2147483648)
	{
	}
	write(STDOUT_FILENO, "-", 1);
	ft_putnbr_base(-n, base);
}

void	ft_putnbr_base(int n, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		if (elem(base[i], base) > 1)
			return ;
		i++;
	}
	if (i == 0 || i == 1)
		return ;
	if (n < 0)
		putneg(n, base);
	else if (n < i)
		write(STDOUT_FILENO, base + n, 1);
	else
	{
		ft_putnbr_base(n / i, base);
		write(STDOUT_FILENO, base + (n % i), 1);
	}
}
