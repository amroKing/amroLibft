#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int count_words(char const *s, char c)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (count);
}

char *fill_shit(char const *s, char c)
{
	int i = 0;
	char *fuck;

	while (s[i] != c && s[i])
		i++;
	fuck = (char *)malloc(i + 1);
	if (!fuck)
		return NULL;
	strlcpy(fuck, s, i + 1);
	return fuck;
}

void free_shit(char **s)
{
	int i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char **ft_split(char const *s, char c)
{
	char **spl;
	int  i;
	int j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	spl = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!spl)
		return (NULL);
	while (s[i] && j < count_words(s, c))
	{
		while(s[i] == c && s[i])
			i++;
		spl[j] = fill_shit(s + i, c);
		if (!spl[j])
			free_shit(spl);
		i += strlen(spl[j]);
		j++;
	}
	spl[j] = NULL;
	return spl;
}


int main()
{
	char *str = NULL;
	char c = ';';
	char **s = ft_split(str, c);
	int i = 0;
	printf("%s",(char *)ft_split(str, c));
	if (s){while (s[i])
	{
		printf("%s\n", s[i]);
		i++;
	}}
}
