#include "main.h"

#define BUFF_SIZE 1024

char *my_getline(void)
{
	static char buff[BUFF_SIZE];
	static int buff_index = 0;
	static int buff_size = 0;
	char *line = NULL;
	int line_size = 0;
	int read_size;

	if (buff_index >= buff_size)
	{
		buff_size = read(STDIN_FILENO, buff, BUFF_SIZE);
		buff_index = 0;

		if (buff_size <= 0)
		{
			if (line == NULL)
				/* return NULL to indicate the end of input */
				return (NULL);
			else
				/* return the line if there is any data before the end of input */
				return (line);
		}
	}

	while (buff_index < buff_size)
	{
		if (buff[buff_index] == '\n')
		{
			buff[buff_index] = '\0';
			line = realloc(line, line_size + 1);
			line[line_size] = '\0';
			buff_index++;
			return (line);
		}

		line = realloc(line, line_size + 2);
		line[line_size] = buff[buff_index];
		buff_index++;
		line_size++;
	}

	return (line);
}
