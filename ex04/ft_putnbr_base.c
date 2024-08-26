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

void	putnbr_base(long n, char *base, long len);

void	putneg(long n, char *base, long l)
{
	write(STDOUT_FILENO, "-", 1);
	putnbr_base(-n, base, l);
}

void	putnbr_base(long n, char *base, long len)
{
	if (n < 0)
		putneg(n, base, len);
	else if (n < len)
		write(STDOUT_FILENO, base + n, 1);
	else
	{
		putnbr_base(n / len, base, len);
		write(STDOUT_FILENO, base + (n % len), 1);
	}
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
	putnbr_base(n, base, i);
}
