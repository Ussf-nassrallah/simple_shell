#include "main.h"

#define BUFF_SIZE 1024

/**
 * my_getline - Read a line from standard input
 *
 * Return: A pointer to the line read, or NULL if there is no more input
 */
char *my_getline(void)
{
	static char buff[BUFF_SIZE];
	static int buff_index;
	static int buff_size;
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
