/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xmlparser
*/

#include "xml.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

node *xmlparse(char *path)
{
    node *n = NULL;
    int fd = open(path, O_RDONLY);
    struct stat stats;
    char *nodestr;
    char *strconst;
    int count;

    if (fd < 0)
        return (NULL);
    fstat(fd, &stats);
    nodestr = malloc(stats.st_size);
    if (nodestr) {
        count = read(fd, nodestr, stats.st_size);
        if (count == stats.st_size) {
            strconst = nodestr;
            n = xml_parsenode(&nodestr);
        }
        free(strconst);
    }
    close(fd);
    return (n);
}