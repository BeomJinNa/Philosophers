/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:20:11 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:23:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void	set_simulation_status(t_stat *stat, int value);

int	destroy_mutexes(int index, t_stat *stat, int rt_errno)
{
	int	i;

	set_simulation_status(stat, rt_errno);
	i = -1;
	while (++i < index)
		pthread_mutex_destroy(&stat->fork[i].mutex);
	return (rt_errno);
}
