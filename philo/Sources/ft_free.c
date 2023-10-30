/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:30:57 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 02:41:00 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include <stdlib.h>

void	ft_free(t_program *program, bool thread)
{
	free(program->philo);
	program->philo = NULL;
	if (thread)
	{
		free(program->thread);
		program->thread = NULL;
	}
	free(program);
	program = NULL;
}

void	ft_destroy_mutex(t_program *program)
{
	size_t	i;

	i = 0;
	while (i < program->parsing.ph_n)
	{
		pthread_mutex_destroy(&program->philo[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&program->check);
}
