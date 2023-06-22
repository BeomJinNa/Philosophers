/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:01:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ga_does_input_error_exist(char *str);
int			ga_is_this_space(int c);
int			ga_isdigit(int c);
int			ga_strlen(const char *s);
int			ga_get_array_from_input(int *array, int number_of_args, char *ptr);
int			ga_does_any_overflow_occur(const char *ptr);
static int	does_empty_arg_exist(int ac, char **av);
static char	*get_linked_input_string(int ac, char **av);
static int	get_number_of_parameters(const char *str);
static int	return_error(int code, char *buffer);

int	get_arguments(int *output_array, int output_array_size, int ac, char **av)
{
	char	*linked_string;
	int		number_of_args;

	if (ac == 1)
		return (0);
	if (output_array == NULL || output_array_size <= 0)
		return (-1);
	if (does_empty_arg_exist(ac, av))
		return (-2);
	linked_string = get_linked_input_string(ac, av);
	if (linked_string == NULL)
		return (-3);
	number_of_args = get_number_of_parameters(linked_string);
	if (ga_does_input_error_exist(linked_string))
		return (return_error(-2, linked_string));
	if (number_of_args > output_array_size)
		return (return_error(-4, linked_string));
	if (ga_does_any_overflow_occur(linked_string))
		return (return_error(-5, linked_string));
	if (ga_get_array_from_input(output_array, number_of_args, linked_string))
		return (return_error(-5, linked_string));
	free(linked_string);
	return (number_of_args);
}

static int	does_empty_arg_exist(int ac, char **av)
{
	char	*ptr;

	while (--ac > 0)
	{
		ptr = av[ac];
		while (*ptr)
		{
			if (ga_isdigit(*ptr))
				break ;
			ptr++;
		}
		if (*ptr == '\0')
			return (1);
	}
	return (0);
}

static char	*get_linked_input_string(int ac, char **av)
{
	char	*linked_string;
	int		counter;
	int		length;
	char	*ptr_to;
	char	*ptr_from;

	length = 0;
	counter = ac;
	while (--counter > 0)
		length += ga_strlen(av[counter]) + 1;
	linked_string = (char *)malloc(sizeof(char) * length);
	if (linked_string == NULL)
		return (NULL);
	ptr_to = linked_string;
	while (++counter < ac)
	{
		ptr_from = av[counter];
		while (*ptr_from)
			*ptr_to++ = *ptr_from++;
		*ptr_to++ = ' ';
	}
	*--ptr_to = '\0';
	return (linked_string);
}

static int	get_number_of_parameters(const char *str)
{
	int			number_of_parameters;
	const char	*ptr;

	number_of_parameters = 0;
	ptr = str;
	while (ga_is_this_space(*ptr))
		ptr++;
	while (*ptr)
	{
		number_of_parameters++;
		while (*ptr && ga_is_this_space(*ptr) == 0)
			ptr++;
		while (ga_is_this_space(*ptr))
			ptr++;
	}
	return (number_of_parameters);
}

static int	return_error(int code, char *buffer)
{
	if (buffer != NULL)
		free(buffer);
	return (code);
}
