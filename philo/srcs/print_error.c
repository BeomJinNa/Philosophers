/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:33:39 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 21:13:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "e_private_errors.h"
#include "s_stat.h"

static char	*private_strerr(int code);

int	print_error(int private_errno, t_stat *stat)
{
	const char *const	str = private_strerr(private_errno);
	const char			*ptr;

	if (stat->philo != NULL)
		free(stat->philo);
	if (stat->fork != NULL)
		free(stat->fork);
	if (str == NULL)
		return (private_errno);
	ptr = str;
	while (*ptr)
		ptr++;
	write(2, "Error: ", 7);
	write(2, str, ptr - str);
	write(2, "\n", 1);
	return (private_errno);
}

static char	*private_strerr(int code)
{
	if (code == M_ERROR_DATA_INIT)
		return ("Error: Data initialization failed\n");
	else if (code == M_ERROR_THREAD_ALLOC)
		return ("Thread allocation failed\n");
	return ((void *)0);
}
