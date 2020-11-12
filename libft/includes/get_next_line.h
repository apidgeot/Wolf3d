#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

typedef	struct		s_gnl
{
	int				fd;
	char			*remainer;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
