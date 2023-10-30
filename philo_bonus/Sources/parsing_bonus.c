/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:50 by snourry           #+#    #+#             */
/*   Updated: 2022/11/25 13:05:50 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static char	**reformed(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' && ft_strlen(argv[i]) > 1)
			j++;
		while (argv[i][j] == '0')
			j++;
		if (j != '0')
			argv[i] = &argv[i][j];
	}
	return (argv);
}

static bool	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	argv = reformed(argc, argv);
	i = 0;
	while (++i < argc)
		if (ft_strlen(argv[i]) > 9)
			return (false);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (false);
	}
	return (true);
}

static bool	ft_check_global(int argc, char **argv)
{
	if (!ft_check_argv(argc, argv))
		printf(ERROR_ARGUMENT);
	else
		printf(ERROR_USAGE);
	return (false);
}

static bool	ft_parsing(int argc, char **argv, t_parsing *parsing)
{
	if (argc < 5 || argc > 6 || !ft_check_argv(argc, argv))
		if (!ft_check_global(argc, argv))
			return (false);
	parsing->have_eat_limit = false;
	parsing->philo = atoul(argv[1]);
	if (parsing->philo < 1)
	{
		printf(ERROR_NPHILO);
		return (false);
	}
	parsing->time_to_die = atoul(argv[2]);
	parsing->time_to_eat = atoul(argv[3]);
	parsing->time_to_sleep = atoul(argv[4]);
	if (argc == 6)
	{
		parsing->have_eat_limit = true;
		parsing->must_eat = atoul(argv[5]);
	}
	if (parsing->time_to_die == 0 || parsing->time_to_eat == 0 \
	|| parsing->time_to_sleep == 0 || (argc == 6 && parsing->must_eat == 0))
	{
		printf(ERROR_VALUE);
		return (false);
	}
	return (true);
}

t_parsing	parser(int argc, char **argv)
{
	t_parsing	parsing;

	parsing.error = !ft_parsing(argc, argv, &parsing);
	return (parsing);
}
