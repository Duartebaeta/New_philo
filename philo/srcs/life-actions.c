/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life-actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:45:55 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/26 01:51:53 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start_eating(t_rules *rules, t_philo *philo)
{
	int	time_eating;

	philo->last_meal = get_simu_time(rules);
	if (get_time_since_last(philo, rules) > rules->time_die)
	{
		send_to_die(rules, philo);
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (print_status(rules, philo, "is eating") == EXIT_FAILURE)
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (rules->time_eat > rules->time_die)
	{
		send_to_die(rules, philo);
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	pthread_mutex_lock(&rules->meals_lock);
	philo->meals_had++;
	pthread_mutex_unlock(&rules->meals_lock);
	time_eating = get_simu_time(rules) + rules->time_eat;
	while (get_simu_time(rules) < time_eating)
	{
		if (rules->is_dead != 0)
		{
			release_forks(rules, philo);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	start_sleeping(t_rules *rules, t_philo *philo)
{
	long	time_to_sleep;

	time_to_sleep = get_simu_time(rules) + rules->time_sleep;
	if (get_time_since_last(philo, rules) > rules->time_die)
	{
		send_to_die(rules, philo);
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (print_status(rules, philo, "is sleeping") == EXIT_FAILURE)
	{
		release_forks(rules, philo);
		return (EXIT_FAILURE);
	}
	if (release_forks(rules, philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if(get_time_until_death(rules, philo) < rules->time_sleep)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	while (get_simu_time(rules) < time_to_sleep)
	{
		if (rules->is_dead != 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	start_thinking(t_rules *rules, t_philo *philo)
{
	if (get_time_since_last(philo, rules) >= rules->time_die)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	if (print_status(rules, philo, "is thinking") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}