/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:08:28 by snourry           #+#    #+#             */
/*   Updated: 2022/11/25 13:03:41 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

# include <stddef.h>
# include <stdbool.h>
# include <pthread.h>

typedef enum e_states
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_states;

typedef struct s_parsing
{
	size_t	ph_n;
	size_t	die_t;
	size_t	eat_t;
	size_t	sleep_t;
	size_t	eat_n;
	bool	have_eat_limit;
}			t_parsing;

typedef struct s_philo
{
	struct s_program	*program;
	pthread_mutex_t		right_fork;
	pthread_mutex_t		*left_fork;
	size_t				position;
	size_t				eat_n;
	size_t				last_eat;
}						t_philo;

typedef struct s_program
{
	t_parsing		parsing;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	check;
	size_t			time_start;
	bool			is_finish;
}					t_program;

#endif
