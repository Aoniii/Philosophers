/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:49:03 by snourry           #+#    #+#             */
/*   Updated: 2022/12/03 18:31:25 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	message(const char *str, t_philo *philo)
{
	sem_wait(philo->message);
	printf(str, get_time() - philo->start, philo->index);
	if (str[3] != '1')
		sem_post(philo->message);
}
