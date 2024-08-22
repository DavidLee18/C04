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

int	elem(char c, char *str);

void	ft_putnbr_base(int n, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return;
		if (elem(base[i], base) > 1)
			return;
		i++;
	}
	if (i == 0 || i == 1)
		return;
	if (n < 0)
	{
		write(STDOUT_FILENO, "-", 1);
		ft_putnbr_base(-n, base);
	}
	else if (n < i)
		write(STDOUT_FILENO, base + n, 1);
	else
	{
	}
}
