#parameters====================================================================

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= philo
INCLUDE	= includes/

#sources=======================================================================

SRCS	= srcs/main.c \
		  srcs/get_arguments.c \
		  srcs/get_arguments/check_input_data.c \
		  srcs/get_arguments/compare_character.c \
		  srcs/get_arguments/ga_errors.c \
		  srcs/get_arguments/get_array_from_input.c \
		  srcs/init_data.c \
		  srcs/print_error.c \
		  srcs/run_simulation.c \
		  srcs/run_simulation/init_threads.c \
		  srcs/run_simulation/release_threads.c \
		  srcs/run_simulation/run_loop.c \
		  srcs/run_simulation/run_thread.c \
		  srcs/utils/get_elapsed_time.c

OBJS	= $(SRCS:.c=.o)

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $@ $(OBJS)

#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
