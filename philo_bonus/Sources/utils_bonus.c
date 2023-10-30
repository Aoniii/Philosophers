/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:50:07 by snourry           #+#    #+#             */
/*   Updated: 2022/11/26 16:50:07 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/time.h>

size_t	atoul(const char *s)
{
	size_t	result;

	result = 0;
	while (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - 48);
	return (result);
}

int	ft_strlen(const char *s)
{
	int	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
