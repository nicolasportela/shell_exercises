#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


char *_getenv(const char *name);
list_t *add_node_end(list_t **head, const char *str);
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
	list_t *head = NULL;

	if (line == NULL)
	{
		return;
	}
	ch = strtok(line, ":"); /*tokenize the value of PATH*/
	while (ch != NULL)
	{
		printf("%s\n", ch); /*print each token*/
		add_node_end(&head, ch);
		printf("node created");
		ch = strtok(NULL, ":"); /*move the token to next*/
	}
}

/* create node*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *newnode, *temp;

	temp = *head;

	if (str == NULL)
	{
		return (0);
	}

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		return (0);
	}

	(*newnode).str = strdup(str);
	(*newnode).next = NULL;

	if (*head == NULL)
	{
		(*head) = newnode;
		return (newnode);
	}

	while ((*temp).next)
	{
		temp = (*temp).next;
	}

	(*temp).next = newnode;
	return (newnode);
}
