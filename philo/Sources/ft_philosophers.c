/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:43:50 by snourry           #+#    #+#             */
/*   Updated: 2022/11/27 10:56:37 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static bool	ft_is_alone(t_philo *philo)
{
	bool	is_alone;

	is_alone = false;
	pthread_mutex_lock(&philo->program->check);
	if (philo->program->parsing.ph_n == 1)
		is_alone = true;
	pthread_mutex_unlock(&philo->program->check);
	return (is_alone);
}

bool	ft_is_finish(t_philo *philo)
{
	bool	is_finish;

	pthread_mutex_lock(&philo->program->check);
	is_finish = philo->program->is_finish;
	pthread_mutex_unlock(&philo->program->check);
	return (is_finish);
}

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->position % 2 == 0)
		usleep(1000);
	while (!ft_is_finish(philo))
	{
		if (!ft_is_finish(philo))
			ft_take_fork(philo);
		if (!ft_is_alone(philo))
			ft_eating(philo);
		if (!ft_is_finish(philo))
			ft_sleeping(philo);
		if (!ft_is_finish(philo))
			ft_philo_print(philo, THINK);
	}
	return (NULL);
}

void	ft_start(t_program *program)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = program->parsing.ph_n;
	program->time_start = ft_get_time();
	while (i < program->parsing.ph_n)
	{
		pthread_create(&program->thread[i], NULL, ft_philo, &program->philo[i]);
		i++;
	}
	ft_check(program);
	i = 0;
	while (i < j)
	{
		pthread_join(program->thread[i], NULL);
		i++;
	}
}
