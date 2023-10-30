/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:44:22 by snourry           #+#    #+#             */
/*   Updated: 2022/12/07 13:31:04 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static t_philo	create(t_parsing parsing)
{
	t_philo	philo;

	philo.parsing = parsing;
	philo.start = get_time();
	philo.last_eat = philo.start;
	philo.eat_count = 0;
	sem_unlink("fork");
	sem_unlink("message");
	sem_unlink("eat");
	sem_unlink("count");
	sem_unlink("mutex");
	sem_unlink("stop");
	philo.fork = sem_open("fork", O_CREAT, 0644, parsing.philo);
	philo.message = sem_open("message", O_CREAT, 0644, 1);
	philo.eat = sem_open("eat", O_CREAT, 0644, 1);
	philo.count = sem_open("count", O_CREAT, 0644, 0);
	philo.mutex = sem_open("mutex", O_CREAT, 0644, 1);
	philo.stop = sem_open("stop", O_CREAT, 0644, 0);
	return (philo);
}

static void	routine(t_philo *philo)
{
	sem_wait(philo->eat);
	sem_wait(philo->fork);
	message(MESSAGE_FORK, philo);
	sem_wait(philo->fork);
	message(MESSAGE_FORK, philo);
	sem_post(philo->eat);
	message(MESSAGE_EAT, philo);
	sem_wait(philo->mutex);
	philo->last_eat = get_time();
	sem_post(philo->mutex);
	philo->eat_count++;
	if (philo->parsing.have_eat_limit && \
	philo->eat_count == philo->parsing.must_eat)
		sem_post(philo->count);
	usleep(philo->parsing.time_to_eat * 1000);
	sem_post(philo->fork);
	sem_post(philo->fork);
	message(MESSAGE_SLEEP, philo);
	usleep(philo->parsing.time_to_sleep * 1000);
	message(MESSAGE_THINK, philo);
}

static void	process(t_philo *philo, pid_t *pid, size_t index)
{
	pthread_t	thread;

	pid[index] = fork();
	if (pid[index] == -1)
		exit(EXIT_FAILURE);
	else if (pid[index] == 0)
	{
		philo->index = index + 1;
		pthread_create(&thread, NULL, check, philo);
		pthread_detach(thread);
		while (1)
			routine(philo);
	}
}

void	start(t_parsing parsing, pid_t *pid)
{
	t_philo	philo;
	size_t	index;

	philo = create(parsing);
	index = 0;
	while (index < parsing.philo)
	{
		process(&philo, pid, index);
		index++;
	}
	process_check_eat(pid, philo);
	sem_wait(philo.stop);
	index = 0;
	while (index <= parsing.philo)
	{
		kill(pid[index], SIGKILL);
		index++;
	}
	sem_close(philo.fork);
	sem_close(philo.message);
	sem_close(philo.eat);
	sem_close(philo.count);
	sem_close(philo.mutex);
	sem_close(philo.stop);
}
