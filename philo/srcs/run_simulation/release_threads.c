/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:20:11 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 23:25:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "release_threads.h"

int	release_threads(int index, t_stat *stat, int rt_errno)
{
	int	i;

	stat->terminate_threads = rt_errno;
	i = -1;
	while (++i < index)
		pthread_detach(stat->philo[index].tid);
	return (rt_errno);
}
