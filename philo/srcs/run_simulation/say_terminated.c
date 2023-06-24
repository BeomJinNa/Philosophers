/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   say_terminated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:04:32 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:16:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

void	say_terminated(t_stat *stat)
{
	pthread_mutex_lock(&stat->mutex_termination);
	stat->terminated_num++;
	pthread_mutex_unlock(&stat->mutex_termination);
}
