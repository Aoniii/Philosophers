/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 03:02:18 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 05:29:41 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"
#include <stdio.h>

void	ft_philo_print(t_philo *philo, t_states states)
{
	size_t	t;

	pthread_mutex_lock(&philo->program->check);
	t = ft_get_time() - philo->program->time_start;
	if (!philo->program->is_finish)
	{
		if (states == FORK)
			printf("\e[92m%5li %3li has taken a fork.\e[0m\n", t, philo->position);
		else if (states == EAT)
			printf("\e[32m%5li %3li is eating.\e[0m\n", t, philo->position);
		else if (states == SLEEP)
			printf("\e[94m%5li %3li is sleeping.\e[0m\n", t, philo->position);
		else if (states == THINK)
			printf("\e[33m%5li %3li is thinking.\e[0m\n", t, philo->position);
		else if (states == DEAD)
			printf("\e[31m%5li %3li died.\e[0m\n", t, philo->position);
	}
	pthread_mutex_unlock(&philo->program->check);
}
