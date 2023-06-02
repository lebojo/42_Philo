/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:55:28 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 02:00:15 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	can_eat(t_philo *p)
{
	while (p->state != 'E' && get_now(p->time) - p->last_eat < p->time->die)
	{
		pthread_mutex_lock(p->lock);
		take_forks(&p->state, p->forks, p->id, *p->max);
		pthread_mutex_unlock(p->lock);
	}
	if (p->state == 'E')
	{
		philo_state(get_now(p->time), p->id, 'E');
		usleep(p->time->eat);
		p->forks[p->id] = 1;
		p->forks[p->id + 1] = 1;
		p->last_eat = get_now(p->time);
		p->state = 'S';
	}
	else
	{
		philo_state(get_now(p->time), p->id, 'D');
		exit(info("DIED"));
	}
}

void	dying(t_philo *p)
{
	if (get_now(p->time) - p->last_eat >= p->time->die)
		p->state = 'D';
}
