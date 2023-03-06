#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int	ft_file_read(char *txt)
{
	int	file_no;
	char first_line[5];
	int i = 0;

	file_no = open(txt, O_RDONLY);
	if (file_no < 0)
	{
		printf("dd");
		return (0);
	}
	if (read(file_no, first_line, 5) < 0)
	{
		printf("mierda");
		return (0);
	}
	while (first_line[i] != '\0')
		printf("%c", first_line[i++]);
	/*
	if (read(file_no, dictionary, 998) < 0)
	{
		return (0);
	}*/
	return (1);
}