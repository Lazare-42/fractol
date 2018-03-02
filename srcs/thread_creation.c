#include <pthread.h>
#include <stdlib.h>

int pthread_create(pthread_t * pth, pthread_attr_t *att, void * (*function), void * arg);

pthread_t	**create_threads(void)
{
	static pthread_t		**thread_list = NULL;
	int						x;

	thread_list = NULL;
	x = 0;
	if 
	if (!(thread_list = malloc(sizeof(thread_list*) * Y_SIZE)))
		return (NULL);
	while (x < Y_SIZE)
	{
		if (pthread_create(thread_list[x], NULL, NULL, NULL))
			ft_myexit("Error in thread creation");
		x++;
	}
}
