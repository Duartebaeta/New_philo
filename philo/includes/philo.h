/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:42:39 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 15:55:04 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include "../libft/libft.h"
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_rules
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	n_meals;
	int	is_dead;
	int	simulation_start;
	t_philo	*philos;
	pthread_t	*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	increment_lock;
	pthread_mutex_t	meals_lock;
} t_rules;

typedef struct s_philo
{
	int	id;
	int	meals_had;
	int	left_fork_id;
	int	right_fork_id;
	long	last_meal;
	long	last_sleep;
	pthread_t	thread_id;
} t_philo;


#endif