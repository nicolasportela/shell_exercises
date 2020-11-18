#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *_getenv(const char *name);
void p_path(char *line);

int main(void)
{
	p_path(_getenv("PATH"));
	return (0);
}

char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	size_t j;
	int ch;

	for (i = 0; environ[i] != 0; i++) /*loop through each element of environ*/
	{
		for (j = 0; environ[i][j] != '='; j++) /*loop through each char of that element*/
		{ /*count chars until reaches =*/
		}
		ch = strncmp(environ[i], name, j); /*compares each character of each string, until j size*/
		if (ch == 0) /*if the strings are equal, then...*/
		{
			strtok(environ[i], "="); /*separate in tokens the name of the variable and its value*/
			return (strtok(NULL, "=")); /*return the value instead of the name*/
		}
	}
	return (NULL); /*in case the function couldn't find the command, return NULL*/
} /*Use this function as a checker of the environ and functions*/

void p_path(char *line) /*get the return of _getenv*/
{
	char *ch;

	ch = strtok(line, ":"); /*tokenize the value of PATH*/
	while (ch != 0)
	{
		printf("%s\n", ch); /*print each token*/
		ch = strtok(NULL, ":"); /*move the token to next*/
	}
}
