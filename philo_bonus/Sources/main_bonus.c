/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:58:46 by snourry           #+#    #+#             */
/*   Updated: 2022/11/25 12:58:46 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	pid_t		*pid;
	t_parsing	parsing;

	parsing = parser(argc, argv);
	if (parsing.error)
		return (1);
	pid = malloc(sizeof(pid_t) * (parsing.philo + 1));
	if (!pid)
		return (1);
	start(parsing, pid);
	free(pid);
	pid = NULL;
	return (0);
}
