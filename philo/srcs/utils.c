/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:00:02 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/26 02:24:16 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_until_death(t_rules *rules, t_philo *philo)
{
	long	time_elapsed;

	time_elapsed = get_simu_time(rules) - philo->last_meal;
	if (time_elapsed < get_time_since_last(philo, rules))
		return (rules->time_die - time_elapsed);
	else
		return (0);
}

long	get_time_since_last(t_philo *philo, t_rules *rules)
{
	if (philo->last_meal != 0)
		return (get_simu_time(rules) - philo->last_meal);
	else
		return (get_time() - rules->simulation_start);
}

long	get_time()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	get_simu_time(t_rules *rules)
{
	return (get_time() - rules->simulation_start);
}

int	still_has_time(t_rules *rules, t_philo *philo)
{
	if (get_time_since_last(philo, rules) >= rules->time_die)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}