/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:42:16 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 22:46:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_thread.h"

#include <stdio.h>//TEST
void	*run_thread(void *arg)
{
	t_philo	*info = (t_philo *)arg;

	printf("thread created, index : %d, time stamp : %d\n", info->index, get_elapsed_time(0));
	while (1)
	{
		usleep(100000);
		printf("philo %d time stamp %d\n", info->index, get_elapsed_time(0));
	}
	return (NULL);
}
