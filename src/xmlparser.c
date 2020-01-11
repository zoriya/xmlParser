/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** xmlparser
*/

#include "my.h"
#include "xml.h"
#include "xml_internal.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>

int xml_handle_prolog(char **nodestr)
{
    char *strconst = *nodestr;

    if (my_strstr(*nodestr, "<?xml") == *nodestr) {
        *nodestr = my_strstr(*nodestr, "?>");
        if (!*nodestr) {
            free(strconst);
            return (-1);
        }
        *nodestr += 2;
    }
    return (0);
}

bool is_charvalid(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        return (false);
    if (c == '"' || c == '\'')
        return (false);
    if (c == '=')
        return (false);
    if (c == '>' || c == '<' || c == '/')
        return (false);
    return (true);
}

bool is_space_usefull(char *nodestr, int i)
{
    if (i == 0 || (!is_charvalid(nodestr[i - 1]) && nodestr[i - 1] != '"'))
        return (false);
    if (i + 1 == my_strlen(nodestr) || !is_charvalid(nodestr[i + 1]))
        return (false);
    return (true);
}

node *xml_parsestr(char *nodestr)
{
    node *n;
    char *strconst = nodestr;

    if (xml_handle_prolog(&nodestr) < 0)
        return (NULL);
    for (int i = 0; nodestr[i]; i++) {
        if (nodestr[i] == ' ' && !is_space_usefull(nodestr, i))
            nodestr[i] = '\t';
    }
    nodestr = trimstr(nodestr);
    free(strconst);
    strconst = nodestr;
    n = xml_parsenode(&nodestr);
    free(strconst);
    return (n);
}

node *xml_parse(const char *path)
{
    node *n = NULL;
    int fd = open(path, O_RDONLY);
    struct stat stats;
    char *nodestr;
    int count;

    if (fd < 0)
        return (NULL);
    fstat(fd, &stats);
    nodestr = malloc(stats.st_size + 1);
    if (nodestr) {
        count = read(fd, nodestr, stats.st_size);
        nodestr[stats.st_size] = '\0';
        if (count == stats.st_size)
            n = xml_parsestr(nodestr);
    }
    close(fd);
    return (n);
}