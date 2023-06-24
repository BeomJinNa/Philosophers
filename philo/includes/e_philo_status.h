/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_philo_status.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:25:33 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 21:52:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_PHILO_STATUS_H
# define E_PHILO_STATUS_H

enum e_philo_status
{
	M_PHILO_STAT_THINKING = 0,
	M_PHILO_STAT_1FORK = 1,
	M_PHILO_STAT_EATING = 2,
	M_PHILO_STAT_SLEEPING = 3
};
#endif
