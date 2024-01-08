#ifndef CHECKER_H
# define CHECKER_H

# define NA 0
# define FD_STDOUT 0
# define BUFFER_SIZE 1
# define KO 0
# define OK 1
# define FORMAT_ERROR 2

# include "inc_stdlib.h"
# include "instruction.h"
# include "stack.h"

typedef struct i_list
{
	char			*data;
	struct i_list	*next;
}	t_ins;

int	main(int argc, char **argv);

#endif
