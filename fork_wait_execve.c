#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;
	int status;
	int child_check;

	for (i = 0; i < 5; i++)
	{
		child_check = fork();
		if (child_check == -1)
		{
			perror("Error");
		}
		if (child_check == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
