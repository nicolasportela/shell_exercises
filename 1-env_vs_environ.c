#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av, char **env)
{
	extern char **environ;

	(void)ac;
	(void)av;

	printf("env address: %p\n", (void *)&env);
	printf("environ address: %p\n", (void *)&environ);

	return (0);
}
