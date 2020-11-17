#include <stdio.h>
#include <unistd.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		
