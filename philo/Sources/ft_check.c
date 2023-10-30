/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 03:16:37 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 06:04:37 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static bool	ft_check_max_eat(t_program *program)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&program->check);
	while (i < program->parsing.ph_n)
	{
		if (program->philo[i].eat_n < program->parsing.eat_n)
		{
			pthread_mutex_unlock(&program->check);
			return (false);
		}
		i++;
	}
	program->is_finish = true;
	pthread_mutex_unlock(&program->check);
	return (true);
}

static bool	ft_p_is_finish(t_program *program)
{
	bool	is_finish;

	pthread_mutex_lock(&program->check);
	is_finish = program->is_finish;
	pthread_mutex_unlock(&program->check);
	return (is_finish);
}

static size_t	ft_p_get_ph(t_program *program)
{
	size_t	i;

	pthread_mutex_lock(&program->check);
	i = program->parsing.ph_n;
	pthread_mutex_unlock(&program->check);
	return (i);
}

static void	ft_launch_eat(t_program *program)
{
	pthread_mutex_lock(&program->check);
	if (program->parsing.have_eat_limit)
	{
		pthread_mutex_unlock(&program->check);
		if (ft_check_max_eat(program))
		{
			pthread_mutex_lock(&program->check);
			program->is_finish = true;
			pthread_mutex_unlock(&program->check);
		}
	}
	else
		pthread_mutex_unlock(&program->check);
}

void	ft_check(t_program *program)
{
	size_t	i;

	while (!ft_p_is_finish(program))
	{
		i = 0;
		ft_launch_eat(program);
		while (i < ft_p_get_ph(program) && !ft_p_is_finish(program))
		{
			pthread_mutex_lock(&program->check);
			if (ft_get_time() - program->philo[i].last_eat >= \
				program->parsing.die_t)
			{
				pthread_mutex_unlock(&program->check);
				ft_philo_print(&program->philo[i], DEAD);
				pthread_mutex_lock(&program->check);
				program->is_finish = true;
				pthread_mutex_unlock(&program->check);
				return ;
			}
			pthread_mutex_unlock(&program->check);
			i++;
		}
	}
}
