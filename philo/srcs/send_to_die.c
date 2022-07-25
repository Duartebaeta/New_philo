/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:50:27 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 23:12:57 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	send_to_die(t_rules *rules, t_philo *philo)
{
	long	time_left;

	time_left = get_time_until_death(rules, philo) + get_simu_time(rules);
	while (get_simu_time(rules) < time_left);
	if (print_status(rules, philo, "is dead") == EXIT_FAILURE)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&rules->death_lock);
	rules->is_dead = 1;
	pthread_mutex_unlock(&rules->death_lock);
	return (EXIT_SUCCESS);
}