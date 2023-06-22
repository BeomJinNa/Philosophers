/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:06:33 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 22:38:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include "s_stat.h"
# include "s_args.h"
# include "get_arguments.h"

int			init_data(t_stat *stat, t_args *args);
static int	wrong_arg_numbers(void);
static int	argument_error(int ga_errno);
static void	set_arguments(t_args *args, int *array);
#endif
