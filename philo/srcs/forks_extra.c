/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:16:35 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/09/05 19:17:26 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	release_fork_singular(t_rules *rules, int fork_id)
{
	if (pthread_mutex_unlock(&rules->forks[fork_id]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	rules->forks_bool[fork_id] = 0;
	return (EXIT_SUCCESS);
}

int	release_forks(t_rules *rules, t_philo *philo)
{
	if (release_fork_singular(rules, philo->left_fork_id) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (release_fork_singular(rules, philo->right_fork_id) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	rules->forks_bool[philo->left_fork_id] = 0;
	rules->forks_bool[philo->right_fork_id] = 0;
	return (EXIT_SUCCESS);
}
