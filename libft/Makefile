FILES = ft_atoi.c \
		ft_strncmp.c

FLAGS = -Wall -Werror -Wextra
OBS = ft_atoi.o ft_strncmp.o # $(patsubst %.c, %.o, $(FILES)) 

all:
	gcc $(FILES) -c
	ar r libft.a $(OBS)