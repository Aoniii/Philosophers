/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 03:00:04 by snourry           #+#    #+#             */
/*   Updated: 2022/12/07 15:39:23 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h" 
#include <stdio.h>

static bool	ft_one_philo(t_philo *philo)
{
	bool	is_finish;

	pthread_mutex_lock(&philo->program->check);
	is_finish = philo->program->is_finish;
	pthread_mutex_unlock(&philo->program->check);
	return (is_finish);
}

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork);
	ft_philo_print(philo, FORK);
	pthread_mutex_lock(&philo->program->check);
	if (philo->program->parsing.ph_n == 1)
	{
		pthread_mutex_unlock(&philo->program->check);
		pthread_mutex_unlock(&philo->right_fork);
		while (!ft_one_philo(philo))
			usleep(10);
		return ;
	}
	pthread_mutex_unlock(&philo->program->check);
	pthread_mutex_lock(philo->left_fork);
	ft_philo_print(philo, FORK);
}

void	ft_eating(t_philo *philo)
{
	size_t	time;

	time = 0;
	ft_philo_print(philo, EAT);
	if (!ft_is_finish(philo))
	{
		pthread_mutex_lock(&philo->program->check);
		philo->eat_n++;
		philo->last_eat = ft_get_time();
		time = philo->program->parsing.eat_t * 1000;
		pthread_mutex_unlock(&philo->program->check);
		usleep(time);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
}

void	ft_sleeping(t_philo *philo)
{
	size_t	time;

	time = 0;
	ft_philo_print(philo, SLEEP);
	if (!ft_is_finish(philo))
	{
		pthread_mutex_lock(&philo->program->check);
		time = philo->program->parsing.sleep_t * 1000;
		pthread_mutex_unlock(&philo->program->check);
		usleep(time);
	}
}
