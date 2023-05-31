/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:09:58 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/31 02:32:22 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

static int	ft_abs(int d)
{
	if (d < 0)
		d *= -1;
	return (d);
}

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}

char	*zz_itoa(int n)
{
	int		nbzero;
	int		n2;
	char	*res;
	int		i;

	nbzero = 1;
	n2 = n;
	i = 0;
	if (n == -2147483648 && nbzero++)
		n2 = n / 10;
	while (ft_abs(n2) > 9 && nbzero++)
		n2 = n2 / 10;
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_calloc(sizeof(char) * nbzero + 2, sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[i++] = '-';
	while (--nbzero >= 0)
	{
		res[i++] = ft_abs((n / ft_power(10, nbzero))) + 48;
		n = n - ((n / ft_power(10, nbzero)) * ft_power(10, nbzero));
	}
	return (res);
}

int	zz_atoi(char *str)
{
	char	*l;
	int		neg;
	long	res;
	int		i;

	l = (char *)str;
	neg = 1;
	res = 0;
	i = 0;
	while (l[i] == ' ' || l[i] == '\n' || l[i] == '\t' || l[i] == '\v'
		|| l[i] == '\f' || l[i] == '\r')
		i++;
	if (l[i] == '-' || l[i] == '+')
	{
		if (l[i] == '-')
			neg *= -1;
		i++;
	}
	while (l[i] >= 48 && l[i] <= 57)
	{
		res = res * 10 + (l[i] - 48);
		l++;
	}
	return (res * neg);
}
