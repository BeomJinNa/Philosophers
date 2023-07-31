/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:20:11 by bena              #+#    #+#             */
/*   Updated: 2023/07/31 19:03:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void	set_simulation_status(t_stat *stat, int value);

int	release_threads(int index, t_stat *stat, int rt_errno)
{
	int	i;

	set_simulation_status(stat, rt_errno);
	i = -1;
	while (++i < index)
		pthread_detach(stat->philo[i].tid);
	return (rt_errno);
}
