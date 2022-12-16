NAME = push_swap

NAME_B = checker

SRCS = main.c\
		sort_bit.c\
		sort_tab.c\
		sort_tab2.c\
		sort_util.c\
		util1.c\
		util2.c\
		util3.c\
		instruct1.c\
		instruct2.c\
		get_next_line_utils.c\
		get_next_line.c\

SRCS_B = cheker.c\
		sort_bit.c\
		sort_tab.c\
		sort_tab2.c\
		sort_util.c\
		util1.c\
		util2.c\
		util3.c\
		instruct1.c\
		instruct2.c\
		get_next_line_utils.c\
		get_next_line.c\

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS = -g -Wall -Wextra -Werror

CC = cc

RM = /bin/rm -f

all: ${NAME} 

$(NAME):	${OBJS}
	${CC} ${CFLAGS}	-o ${NAME} ${OBJS} 

bonus: ${NAME_B}

$(NAME_B):	${OBJS_B}
	${CC} ${CFLAGS}	-o ${NAME_B} ${OBJS_B} 
	
clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME} ${NAME_B}

re:	fclean all

.O_PHONY: fclean clean all re bonus