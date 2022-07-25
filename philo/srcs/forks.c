/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:56:45 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 18:09:28 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_taking_forks(t_rules *rules, t_philo *philo)
{
	if (check_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if ()
}

int	check_fork(t_rules *rules, t_philo *philo)
{
	if (rules->n_philo == 1 || get_time_since_last(philo, rules) > rules->time_die)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	take_first_fork(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&(philo->left_fork_id));
	
}