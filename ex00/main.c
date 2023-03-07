#include <unistd.h>
#include <fcntl.h>


int	ft_file_read(char *txt);
int ft_read_header(char *argv);

int	main(int argc, char *argv[])
{
	char	map_param[4];
	char	map[999];
	int i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			ft_read_header(argv[i++]);
		}
	}
}