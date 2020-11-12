#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int n;
	int *arr;

	n = 0;
	if (max <= min)
		return (0);
	arr = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		arr[n] = min;
		n++;
		min++;
	}
	return (arr);
}
