/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:30:36 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/07/25 19:24:03 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_simulation(void *r)
{
	t_rules *rules;
	t_philo	*philo;
	static int	counter = 0;

	rules = (t_rules *) r;
	pthread_mutex_lock(&(rules->increment_lock));
	philo = &rules->philos[counter++];
	pthread_mutex_unlock(&(rules->increment_lock));
	while (1)
	{
		if (start_taking_forks(rules, philo) == EXIT_FAILURE)
			break ;
	}
	return (EXIT_SUCCESS);
}

int	init_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_create(&(rules->threads[i]), NULL, start_simulation, (void *)rules);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_philo)
	{
		pthread_join(rules->threads[i], NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	simulator(t_rules *rules)
{
	rules->simulation_start = get_time();
	init_threads(rules);
	join_threads(rules);
	return (EXIT_SUCCESS);
}