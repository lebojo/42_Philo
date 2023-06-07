/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:08:51 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/07 06:06:28 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	error(char *str)
{
	printf("\033[0;31m[ERROR] \033[0m%s\n", str);
	return (1);
}

int	info(char *str)
{
	printf("\e[0;32m[PHILO] \033[0m%s\n", str);
	return (1);
}

void	p_state(unsigned long int time, t_philo *p)
{
	int		id;
	char	*str;

	pthread_mutex_lock(p->l);
	id = p->id + 1;
	str = "\e[0;32m[PHILO] \033[0m";
	if (p->state == Thinking)
		printf("%s%lums %i is thinking\n", str, time, id);
	if (p->state == Eating)
		printf("%s%lums %i is Eating (%i)\n", str, time, id, p->nb_eat);
	if (p->state == Fork)
		printf("%s%lums %i take a fork\n", str, time, id);
	if (p->state == Sleeping)
		printf("%s%lums %i is sleeping\n", str, time, id);
	if (p->state == Dead)
		printf("%s%lums %i died\n", str, time, id);
	pthread_mutex_unlock(p->l);
}
