#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd; // file descriptor
    char *buffer; // buffer to store data
    int n; // number of bytes read
    int size = 100; // initial size of buffer

    fd = open("file.txt", O_RDONLY); // open file for reading
    if (fd == -1) // check for errors
    {
        perror("open");
        return 1;
    }

    buffer = malloc(size); // allocate memory for buffer
    if (buffer == NULL) // check for errors
    {
        perror("malloc");
        return 1;
    }

    int i = 0; // index of buffer
    while ((n = read(fd, &buffer[i], 1)) > 0) // read one byte at a time until end of file
    {
        i++; // increment index
        if (i == size) // check if buffer is full
        {
            size *= 2; // double the size of buffer
            buffer = realloc(buffer, size); // resize the allocated memory
            if (buffer == NULL) // check for errors
            {
                perror("realloc");
                return 1;
            }
        }
    }

    if (n == -1) // check for errors
    {
        perror("read");
        return 1;
    }

    write(1, buffer, i); // write to standard output

    free(buffer); // free allocated memory

    close(fd); // close file

    return 0;
}