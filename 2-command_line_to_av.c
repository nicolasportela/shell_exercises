#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *str = malloc(sizeof(char) * 1024);
	char *ptr;
	char delim = ' ';
	int i;
	size_t size = 1024;

	write(STDOUT_FILENO, "$ ", 2);
	getline(&str, &size, stdin);
	ptr = strtok(str, &delim);
	while (ptr)
	{
		for (i = 0; ptr[i] != '\0'; i++)
		{
		}
		write(STDOUT_FILENO, ptr, i);
		ptr = strtok(NULL, &delim);
		if (ptr != NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	free(str);
	return (0);
}
