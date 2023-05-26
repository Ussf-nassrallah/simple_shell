#include "main.h"

/**
 * _ptenv - prints environment
 * @argv: arguments victor
 */
void _ptenv(char **argv __attribute__ ((unused)))
{

	int index = 0;

	for (; environ[index]; index++)
	{
		_puts(environ[index]);
	}

}
