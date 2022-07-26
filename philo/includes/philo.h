/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:42:39 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/09/05 19:39:11 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_rules
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_meals;
	int				is_dead;
	long			simulation_start;
	struct s_philo	*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	int				*forks_bool;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	increment_lock;
	pthread_mutex_t	meals_lock;
}	t_rules;

typedef struct s_philo
{
	int			id;
	int			meals_had;
	int			left_fork_id;
	int			right_fork_id;
	long		last_meal;
	long		last_sleep;
	pthread_t	thread_id;
}	t_philo;

// util functions
int		arg_checker(int argc, char **argv);
long	get_time_until_death(t_rules *rules, t_philo *philo);
long	get_time_since_last(t_philo *philo, t_rules *rules);
long	get_time(void);
long	get_simu_time(t_rules *rules);
int		print_status(t_rules *rules, t_philo *philo, char *message);
int		check_print(t_rules *rules);
int		enough_meals(t_rules *rules);
int		still_has_time(t_rules *rules, t_philo *philo);
int		check_for_deaths(t_rules *rules, t_philo *philo);

//init struct params
int		init_all(char **argv, t_rules *rules);
int		init_philo(t_rules *rules);
int		init_mut(t_rules *rules);
int		init_aloc(t_rules *rules);

//simulation
int		simulator(t_rules *rules);
void	*start_simulation(void *rules);

//threads
int		join_threads(t_rules *rules);
int		init_threads(t_rules *rules);

//taking and releasing forks
int		start_taking_forks(t_rules *rules, t_philo *philo);
int		check_fork(t_rules *rules, t_philo *philo);
int		take_first_fork(t_rules *rules, t_philo *philo);
int		take_second_fork(t_rules *rules, t_philo *philo);
int		release_fork_singular(t_rules *rules, int fork_id);
int		release_forks(t_rules *rules, t_philo *philo);

//life actions
int		send_to_die(t_rules *rules, t_philo *philo);
int		start_eating(t_rules *rules, t_philo *philo);
int		eating_extra(t_rules *rules, t_philo *philo);
int		start_sleeping(t_rules *rules, t_philo *philo);
int		start_thinking(t_rules *rules, t_philo *philo);

#endif