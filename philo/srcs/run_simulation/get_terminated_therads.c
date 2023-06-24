/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminated_therads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:58:04 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 20:01:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_terminated_threads.h"

int	get_terminated_threads(t_stat *stat)
{
	int	output;

	pthread_mutex_lock(&stat->termination);
	output = stat->terminate_threads;
	pthread_mutex_unlock(&stat->termination);
	return (output);
}
