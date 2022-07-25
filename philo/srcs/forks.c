/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:56:45 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 19:21:08 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_taking_forks(t_rules *rules, t_philo *philo)
{
	if (check_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (take_first_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (take_second_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_fork(t_rules *rules, t_philo *philo)
{
	if (rules->n_philo == 1 || get_time_since_last(philo, rules) > rules->time_die)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	take_first_fork(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->left_fork_id]);
	if (print_status(rules, philo, "has taken a fork") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	take_second_fork(t_rules *rules, t_philo *philo)
{
	if (pthread_mutex_lock(&rules->forks[philo->left_fork_id]) == EXIT_FAILURE)
	{
		release_fork_singular(rules, philo->left_fork_id);
		return (EXIT_FAILURE);
	}
	if (print_status(rules, philo, "has taken a fork") == EXIT_FAILURE)
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	release_fork_singular(t_rules *rules, int fork_id)
{
	if (pthread_mutex_unlock(&rules->forks[fork_id]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	release_forks(t_rules *rules, t_philo *philo)
{
	if (release_fork_singular(rules, philo->left_fork_id) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (release_fork_singular(rules, philo->right_fork_id) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}