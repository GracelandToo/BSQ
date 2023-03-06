#include <unistd.h>
#include <fcntl.h>


int	ft_file_read(char *txt);

int	main(int argc, char *argv[])
{
	char	map_param[4];
	char	map[999];

	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_file_read(argv[1]);

}