#include "libft.h"
#include <stdlib.h>

static int		wrd(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i++] != '\0')
	{
		if (s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			num++;
		if (s[i] == '\0')
			break ;
	}
	return (num);
}

static int		wordlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s || !(table = (char**)malloc(sizeof(char*) * (wrd(s, c) + 1))))
		return (NULL);
	while (n < wrd(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		table[n] = ft_strsub(s, i, wordlen(s + i, c));
		while (s[i] != c && s[i] != '\0')
			i++;
		n++;
	}
	table[n] = NULL;
	free(table[n]);
	return (table);
}
