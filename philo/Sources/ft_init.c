/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:22:50 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 06:05:22 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

t_program	*ft_init_program(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (!program)
		return (NULL);
	program->is_finish = false;
	pthread_mutex_init(&program->check, NULL);
	return (program);
}

static void	ft_init_thread(t_program *program)
{
	program->thread = malloc(sizeof(pthread_t) * program->parsing.ph_n);
	if (!program->thread)
	{
		ft_destroy_mutex(program);
		ft_free(program, false);
		return ;
	}
}

t_philo	*ft_create_philo(t_program *program)
{
	t_philo	*philo;
	size_t	i;

	philo = malloc(sizeof(t_philo) * program->parsing.ph_n);
	if (!philo)
	{
		free(program);
		program = NULL;
		return (NULL);
	}
	i = -1;
	while (++i < program->parsing.ph_n)
	{
		philo[i].program = program;
		pthread_mutex_init(&philo[i].right_fork, NULL);
		philo[i].position = i + 1;
		philo[i].eat_n = 0;
		philo[i].last_eat = ft_get_time();
		if (i > 0)
			philo[i].left_fork = &philo[i - 1].right_fork;
	}
	if (program->parsing.ph_n != 1)
		philo[0].left_fork = &philo[i - 1].right_fork;
	ft_init_thread(program);
	return (philo);
}
