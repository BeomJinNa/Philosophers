/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:20:11 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 18:51:33 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destroy_mutexes.h"

int	destroy_mutexes(int index, t_stat *stat, int rt_errno)
{
	int	i;

	stat->terminate_threads = rt_errno;
	i = -1;
	while (++i < index)
		pthread_mutex_destroy(&stat->fork[i].mutex);
	return (rt_errno);
}
