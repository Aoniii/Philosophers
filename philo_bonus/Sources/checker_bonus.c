/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:36:17 by snourry           #+#    #+#             */
/*   Updated: 2022/12/03 18:36:17 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		sem_wait(philo->mutex);
		if (philo->last_eat + philo->parsing.time_to_die < get_time())
			break ;
		sem_post(philo->mutex);
		usleep(1000);
	}
	message(MESSAGE_DIE, philo);
	sem_post(philo->stop);
	return (NULL);
}

void	process_check_eat(pid_t *pid, t_philo philo)
{
	size_t	i;

	pid[philo.parsing.philo] = fork();
	i = 0;
	if (pid[philo.parsing.philo] == -1)
		exit(EXIT_FAILURE);
	else if (pid[philo.parsing.philo] == 0)
	{
		while (1)
		{
			sem_wait(philo.count);
			i++;
			if (i == philo.parsing.philo)
				break ;
		}
		sem_wait(philo.message);
		sem_post(philo.stop);
		usleep(10000);
	}
}
