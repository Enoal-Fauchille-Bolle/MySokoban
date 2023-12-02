/*
** EPITECH PROJECT, 2023
** my_read_file
** File description:
** Reads the content of a file and returns a string
*/

#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

static int file_length(char *filepath)
{
    struct stat *statbuf = malloc(sizeof(struct stat));

    stat(filepath, statbuf);
    return statbuf->st_size;
}

char *my_read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int length = file_length(filepath);
    char *buffer = malloc(sizeof(char) * length);

    if (fd == -1) {
        write(2, "Error while reading file\n", 25);
        exit(84);
    }
    read(fd, buffer, length);
    close(fd);
    return buffer;
}
