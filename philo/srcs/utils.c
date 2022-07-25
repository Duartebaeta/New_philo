/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:00:02 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 18:01:40 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time_until_death(t_rules *rules, t_philo *philo)
{
	long	time_elapsed;

	time_elapsed = get_simu_time(rules) - philo->last_meal;
	return (rules->time_die - time_elapsed);
}

long	get_time_since_last(t_philo *philo, t_rules *rules)
{
	if (philo->last_meal != 0)
		return (get_simu_time(rules) - philo->last_meal);
	else
		return (get_simu_time(rules) - rules->simulation_start);
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