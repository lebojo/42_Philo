/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:19:22 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/31 05:22:23 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "proto.h"

typedef	struct s_time
{
	int		eat;
	int		die;
	int		sleep;
	int		end;
}	t_time;

typedef	struct s_philo
{
	char		state; //E == Eate, T == penser
	int			has_fork;
	int			id;
	pthread_t	tr;
	t_time		*time;
}	t_philo;

typedef	struct s_data
{
	int		nb_philo;
	t_philo	*philo;
}	t_data;

#endif