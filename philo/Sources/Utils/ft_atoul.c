/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:50:58 by snourry           #+#    #+#             */
/*   Updated: 2022/09/15 23:50:58 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_atoul(char *s)
{
	size_t	result;

	result = 0;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - 48);
	return (result);
}
