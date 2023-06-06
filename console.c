/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:24:12 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 00:40:08 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	error(char *str)
{
	printf("\033[0;31m[ERROR] \033[0m %s\n", str);
	return (1);
}

int	info(char *str)
{
	printf("\e[0;32m[PHILO] \033[0m%s\n", str);
	return (1);
}

void	philo_state(long int time, int philo, char type)
{
	char	*tmp;

	tmp = add_str(zz_itoa(time), " ", 1);
	tmp = add_str(tmp, zz_itoa(philo), 3);
	if (type == 'F')
		tmp = add_str(tmp, " has taken a fork", 1);
	else if (type == 'E')
		tmp = add_str(tmp, " is eating", 1);
	else if (type == 'S')
		tmp = add_str(tmp, " is sleeping", 1);
	else if (type == 'T')
		tmp = add_str(tmp, " is thinking", 1);
	else if (type == 'D')
		tmp = add_str(tmp, " died", 1);
	info(tmp);
	free(tmp);
}
