/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehylee <jaehylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:08:48 by jaehylee          #+#    #+#             */
/*   Updated: 2024/08/25 12:08:48 by jaehylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	base_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		if (base[i] >= 9 && base[i] <= 13)
			return (0);
		if (elem(base[i], base) > 1)
			return (0);
		i++;
	}
	return (i);
}

char	*pre_str(char *str, int *s)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*s *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	sign;
	int	result;

	i = base_len(base);
	j = 0;
	sign = 1;
	result = 0;
	if (i == 0 || i == 1)
		return (0);
	str = pre_str(str, &sign);
	while (elem(str[j], base) == 1)
	{
		result = result * j + str[j] - base[0];
		j++;
	}
	return (result * sign);
}
