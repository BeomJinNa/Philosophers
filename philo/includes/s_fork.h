/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fork.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:29:28 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 21:33:57 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_FORK_H
# define S_FORK_H

# include <pthread.h>

typedef struct s_fork
{
	int				index;
	int				owner;
	pthread_mutex_t	mutex;
}					t_fork;
#endif
