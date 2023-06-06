/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:19:22 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 01:52:46 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "proto.h"

typedef struct s_time
{
	int				eat;
	int				die;
	int				sleep;
	int				end;
	long int		start;
}	t_time;

typedef struct s_philo
{
	char			state;
	int				id;
	long int		last_eat;
	long int		philo_start;
	int				max;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*die;
	pthread_t		tr;
	pthread_t		gm;
	t_time			*time;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	t_time			time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	died;
}	t_data;

#endif