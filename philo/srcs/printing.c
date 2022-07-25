/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:09:41 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 23:23:20 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	print_status(t_rules *rules, t_philo *philo, char *message)
{
	pthread_mutex_lock(&rules->death_lock);
	pthread_mutex_lock(&rules->meals_lock);
	if (check_print(rules) == EXIT_FAILURE)
	{
		pthread_mutex_unlock(&rules->death_lock);
		pthread_mutex_unlock(&rules->meals_lock);
		return (EXIT_FAILURE);
	}
	printf("%ld %d %s\n", get_simu_time(rules), philo->id + 1, message);
	pthread_mutex_unlock(&rules->death_lock);
	pthread_mutex_unlock(&rules->meals_lock);
	return (EXIT_SUCCESS);
}

int	check_print(t_rules *rules)
{
	if (rules->is_dead != 0)
		return (EXIT_FAILURE);
	else if (enough_meals(rules) == EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	enough_meals(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		if (rules->philos[i++].meals_had != rules->n_meals)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}