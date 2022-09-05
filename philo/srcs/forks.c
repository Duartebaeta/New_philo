/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:56:45 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/09/05 19:17:00 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_taking_forks(t_rules *rules, t_philo *philo)
{
	if (check_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (take_first_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (rules->n_philo == 1)
	{
		send_to_die(rules, philo);
		release_fork_singular(rules, philo->left_fork_id);
		return (EXIT_FAILURE);
	}
	else if (take_second_fork(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_fork(t_rules *rules, t_philo *philo)
{
	if (get_time_since_last(philo, rules) >= rules->time_die)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	take_first_fork(t_rules *rules, t_philo *philo)
{
	if (rules->forks_bool[philo->right_fork_id] == 1
		|| rules->forks_bool[philo->left_fork_id] == 1)
	{
		if (get_time_since_last(philo, rules) + rules->time_eat
			> rules->time_die)
		{
			send_to_die(rules, philo);
			return (EXIT_FAILURE);
		}
		while (rules->forks_bool[philo->right_fork_id] == 1
			|| rules->forks_bool[philo->left_fork_id] == 1)
		{
			if (check_for_deaths(rules, philo) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	pthread_mutex_lock(&rules->forks[philo->left_fork_id]);
	rules->forks_bool[philo->left_fork_id] = 1;
	if (print_status(rules, philo, "has taken a fork") == EXIT_FAILURE)
	{
		release_fork_singular(rules, philo->left_fork_id);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	take_second_fork(t_rules *rules, t_philo *philo)
{
	if (rules->forks_bool[philo->right_fork_id] == 1)
	{
		if (get_time_since_last(philo, rules) + rules->time_eat
			> rules->time_die)
		{
			send_to_die(rules, philo);
			return (EXIT_FAILURE);
		}
		while (rules->forks_bool[philo->right_fork_id] == 1)
		{
			if (check_for_deaths(rules, philo) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	pthread_mutex_lock(&rules->forks[philo->right_fork_id]);
	rules->forks_bool[philo->right_fork_id] = 1;
	if (print_status(rules, philo, "has taken a fork") == EXIT_FAILURE)
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
