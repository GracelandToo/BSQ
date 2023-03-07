#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_read_header(char *argv)
{
    int file_id; // file descriptor
    char *header; // buffer to store data
	char *buffer;
    int n; // number of bytes read
    int size = 5; // initial size of buffer
	int i;

	i = 0;
    file_id = open(argv, O_RDONLY);
    header = malloc(size); // allocate memory for buffer
    while ((n = read(file_id, &header[i], 1)) > 0) // read one byte at a time until end of file
    {
		if (header[i] == '\n')
			break ;
        i++; // increment index
        if (i == size) // check if buffer is full
        {
            size *= 2; // double the size of buffer
			buffer = header;
            header = malloc(size); // resize the allocated memory
			header = buffer;
        }
    }
	write(1, header, i); // write to standard output
    free(header); // free allocated memory
    close(file_id); // close file
    return 0;
}


int ft_read_map(char *argv)
{
    int file_id; // file descriptor
    char *map; // buffer to store data
	char *buffer;
    int n; // number of bytes read
    int size = 5; // initial size of buffer
	int i;

	i = 0;
    file_id = open(argv, O_RDONLY);
    map = malloc(size); // allocate memory for buffer
    while ((n = read(file_id, &map[i], 1)) > 0) // read one byte at a time until end of file
    {
        i++; // increment index
        if (i == size) // check if buffer is full
        {
            size *= 2; // double the size of buffer
			buffer = map;
            map = malloc(size); // resize the allocated memory
			map = buffer;
        }
    }
	while (i != '\n')
		write(1, map, i); // write to standard output

    free(map); // free allocated memory

    close(file_id); // close file

    return 0;
}
