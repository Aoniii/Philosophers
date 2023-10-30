/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:59:22 by snourry           #+#    #+#             */
/*   Updated: 2022/11/25 12:59:22 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# define ERROR_USAGE "[\e[31mERROR\e[39m] Usage: ./philo \
<number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat] !\n"
# define ERROR_ARGUMENT "[\e[31mERROR\e[39m] The argument isn't correct !\n"
# define ERROR_NPHILO "[\e[31mERROR\e[39m] You need at least 1 Philosopher !\n"
# define ERROR_VALUE "[\e[31mERROR\e[39m] They values can't equals 0 !\n"

# define MESSAGE_DIE "\e[31m%5li %3li died.\e[0m\n"
# define MESSAGE_FORK "\e[92m%5li %3li has taken a fork.\e[0m\n"
# define MESSAGE_EAT "\e[32m%5li %3li is eating.\e[0m\n"
# define MESSAGE_SLEEP "\e[94m%5li %3li is sleeping.\e[0m\n"
# define MESSAGE_THINK "\e[33m%5li %3li is thinking.\e[0m\n"

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <pthread.h>

typedef struct s_parsing
{
	size_t	philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	must_eat;
	bool	have_eat_limit;
	bool	error;
}			t_parsing;

typedef struct s_philo
{
	sem_t		*fork;
	sem_t		*message;
	sem_t		*eat;
	sem_t		*count;
	sem_t		*mutex;
	sem_t		*stop;
	t_parsing	parsing;
	size_t		index;
	size_t		start;
	size_t		last_eat;
	size_t		eat_count;
}				t_philo;

/**
 *		Philosophers Functions
 */
t_parsing	parser(int argc, char **argv);
void		start(t_parsing parsing, pid_t *pid);
void		message(const char *str, t_philo *philo);
void		*check(void *data);
void		process_check_eat(pid_t *pid, t_philo philo);

/**
 *		Utils Functions
 */
size_t		atoul(const char *s);
int			ft_strlen(const char *s);
size_t		get_time(void);
int			ft_isdigit(int c);

#endif