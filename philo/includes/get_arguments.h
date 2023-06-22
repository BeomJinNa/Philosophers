/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:06:33 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 16:06:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ARGUMENTS_H
# define GET_ARGUMENTS_H

int		get_arguments(int *output_array, int output_array_size,
			int ac, char **av);
char	*ga_strerr(int code);
#endif
