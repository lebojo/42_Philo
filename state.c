/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:55:28 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 05:19:59 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	can_eat(t_philo *p)
{
	pthread_mutex_lock(&p->fork);
	philo_state(get_now(), p->id, 'F');
	pthread_mutex_lock(p->next_fork);
	philo_state(get_now(), p->id, 'E');
	p->state = 'E';
	usleep(p->time->eat / 1000);
	p->last_eat = get_now();
	p->state = 'S';
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(p->next_fork);
}

void	dying(t_philo *p)
{
	if (get_now() - p->last_eat >= p->time->die)
		p->state = 'D';
}

void	create_philo(t_data *data, t_philo *p, t_philo *n_p, int i)
{
	p->id = i;
	p->state = 'T';
	p->last_eat = 0;
	p->time = &data->time;
	p->max = &data->nb_philo;
	pthread_mutex_init(&p->fork, NULL);
	pthread_mutex_init(&n_p->fork, NULL);
	p->next_fork = &n_p->fork;
	pthread_create(&p->tr, NULL, &routine, p);
}
