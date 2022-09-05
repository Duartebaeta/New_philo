/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 19:34:26 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/09/05 19:36:21 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	still_has_time(t_rules *rules, t_philo *philo)
{
	if (get_time_since_last(philo, rules) > rules->time_die)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_for_deaths(t_rules *rules, t_philo *philo)
{
	if (rules->is_dead != 0)
		return (EXIT_FAILURE);
	if (get_time_since_last(philo, rules) > rules->time_die)
	{
		send_to_die(rules, philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
