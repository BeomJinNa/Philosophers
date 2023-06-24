/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminated_therads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:58:04 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:10:02 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stat.h"

int	get_terminated_threads(t_stat *stat)
{
	int	output;

	pthread_mutex_lock(&stat->mutex_termination);
	output = stat->terminated_num;
	pthread_mutex_unlock(&stat->mutex_termination);
	return (output);
}
