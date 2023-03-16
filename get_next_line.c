#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
char	  *get_next_line(int fd)
{
	int ret;
	int i;
	char c;
	char *buff;

	buff = malloc(10000);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff);
		return (NULL);
	}
	while((ret = read(fd, &c, 1)) > 0)
	{
		buff[i] = c;
		i++;
		if (c == '\n')
			break;
	}
	if (ret == -1 || (!buff[i - 1] && !ret))
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	return (buff);
}
*/
char *get_next_line(int fd)
{
    int     i = 0;
    int     rd = 0;
    char    character;
    char     *buffer = malloc(10000);

    if (BUFFER_SIZE <= 0)
		return (free(buffer), NULL);
    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
    {
        buffer[i++] = character;
        if (character == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}

int main(int ac, char **av)
{
	char *str;
	int fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((str = get_next_line(fd)))
		{
			printf("%s\n", str);
			free(str);
		}
	}
	return (0);
}
