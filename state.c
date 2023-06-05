/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 22:55:28 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/05 06:25:01 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->fork);
	philo_state(get_now_rel(p), p->id, 'F', p->od);
	pthread_mutex_lock(p->next_fork);
	philo_state(get_now_rel(p), p->id, 'F', p->od);
	philo_state(get_now_rel(p), p->id, 'E', p->od);
	p->state = 'E';
	usleep(p->time->eat * 1000);
	p->last_eat = get_now_rel(p);
	p->state = 'S';
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(p->next_fork);
}

void	create_philo(t_data *data, t_philo *p, t_philo *n_p, int i)
{
	p->philo_start = get_now();
	p->id = i + 1;
	p->state = 'T';
	p->last_eat = get_now_rel(p);
	p->time = &data->time;
	p->max = &data->nb_philo;
	p->next_fork = &n_p->fork;
	p->od = data->one_die;
	p->die = &data->died;
	if (pthread_create(&p->tr, NULL, &routine, p)
		|| pthread_create(&p->gm, NULL, &dying, p))
	{
		error(add_str("Creating threads n°", zz_itoa(i), 2));
		exit(1);
	}
}
