#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(void)
{
	char *command;
	size_t size = 0;
	char *tok;
	char **argv;
	int i;
	pid_t child_check;
	int status;
	int check;

	while (1)
	{
		write(1, "Enter full path command$ ", 25);
		command = malloc(sizeof(char) * 1024);
		argv = malloc(sizeof(char) * 1024);

		check = getline(&command, &size, stdin);
		if (check == -1)
		{
			if (check == EOF)
			{
				free(argv);
				free(command);
				write(1, "\n", 1);
				return (1);
			}
			perror("Error");
			free(argv);
			free(command);
			return (1);
		}

		for (i = 0; command[i] != 0; i++)
		{
		}
		command[i - 1] = '\0';

		tok = strtok(command, " ");

		for (i = 0; tok != 0; i++)
		{
			argv[i] = tok;
			tok = strtok(NULL, " ");
		}

		child_check = fork();
		if (child_check == -1)
		{
			perror("Error");
		}
		if (child_check == 0)
		{
			if(execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				free(argv);
				free(command);
				exit(98);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(argv);
	free(command);
	return (0);
}
