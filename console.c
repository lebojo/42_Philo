/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:08:51 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 12:07:53 by jordan           ###   ########.fr       */
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

void	p_state(unsigned long int time, t_philo *p)
{
	p->id++;
	printf("\e[0;32m[PHILO] \033[0m");
	if (p->state == Thinking)
		printf("%lums %i is thinking\n", time, p->id);
	if (p->state == Eating)
		printf("%lums %i is Eating\n", time, p->id);
	if (p->state == Fork)
		printf("%lums %i take a fork\n", time, p->id);
	if (p->state == Sleeping)
		printf("%lums %i is sleeping\n", time, p->id);
	if (p->state == Dead)
		printf("%lums %i died\n", time, p->id);
}
