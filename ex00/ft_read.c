#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int file_id; // file descriptor
    char *map; // buffer to store data
	char *buffer;
    int n; // number of bytes read
    int size = 5; // initial size of buffer

    file_id = open("example_file", O_RDONLY); // open file for reading
    if (file_id == -1) // check for errors
    {
        write(2, "open", 4);
        return 1;
    }

    map = malloc(size); // allocate memory for buffer
    if (map == NULL) // check for errors
    {
        write(2, "malloc", 4);
        return 1;
    }

    int i = 0; // index of buffer
    while ((n = read(file_id, &map[i], 1)) > 0) // read one byte at a time until end of file
    {
        i++; // increment index
        if (i == size) // check if buffer is full
        {
            size *= 2; // double the size of buffer
			buffer = map;
            map = malloc(size); // resize the allocated memory
			map = buffer;
			//free(buffer);
            if (map == NULL) // check for errors
            {
        		write(2, "realloc", 6);
                return 1;
            }
        }
    }

    if (n == -1) // check for errors
    {
        perror("read");
        return 1;
    }

    write(1, map, i); // write to standard output

    free(map); // free allocated memory

    close(file_id); // close file

    return 0;
}
