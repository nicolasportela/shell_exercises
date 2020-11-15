#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *buffer = malloc(sizeof(char) *1024);
	int c;
	int i;
	size_t cbytes = 1024;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		c = getline(&buffer, &cbytes, stdin);
		if (c == -1)
		{
			if (c == EOF)
			{
				break;
			}
			perror("Error");
		}
		for (i = 0; buffer[i] != '\0'; i++)
		{
		}
		buffer[i - 1] = '\0';
		write(STDOUT_FILENO, buffer, cbytes);
	}
	free(buffer);
	return (0);
}
