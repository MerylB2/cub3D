#include "../../includes/cub3d.h"

#define BUFFER_SIZE 42

static char *ft_strjoin_gnl(char *s1, char *s2)
{
    char    *join;
    int     i;
    int     j;
    
    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    
    join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!join)
        return (NULL);
    
    i = -1;
    while (s1[++i])
        join[i] = s1[i];
    j = 0;
    while (s2[j])
        join[i++] = s2[j++];
    join[i] = '\0';
    
    free(s1);
    return (join);
}

static char *ft_strchr_gnl(char *s, int c)
{
    if (!s)
        return (NULL);
    
    while (*s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }
    
    if ((char)c == '\0')
        return (s);
    
    return (NULL);
}

static char *extract_line(char *storage)
{
    char    *line;
    int     i;
    
    i = 0;
    if (!storage[i])
        return (NULL);
    
    while (storage[i] && storage[i] != '\n')
        i++;
    
    line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return (NULL);
    
    i = 0;
    while (storage[i] && storage[i] != '\n')
    {
        line[i] = storage[i];
        i++;
    }
    
    if (storage[i] == '\n')
    {
        line[i] = storage[i];
        i++;
    }
    line[i] = '\0';
    
    return (line);
}

static char *clean_storage(char *storage)
{
    char    *new_storage;
    int     i;
    int     j;
    
    i = 0;
    while (storage[i] && storage[i] != '\n')
        i++;
    
    if (!storage[i])
    {
        free(storage);
        return (NULL);
    }
    
    new_storage = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
    if (!new_storage)
        return (NULL);
    
    i++;
    j = 0;
    while (storage[i])
        new_storage[j++] = storage[i++];
    new_storage[j] = '\0';
    
    free(storage);
    return (new_storage);
}

char *get_next_line(int fd)
{
    static char *storage;
    char        *buffer;
    char        *line;
    int         bytes_read;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    
    bytes_read = 1;
    while (!ft_strchr_gnl(storage, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free(storage);
            storage = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        storage = ft_strjoin_gnl(storage, buffer);
    }
    
    free(buffer);
    line = extract_line(storage);
    storage = clean_storage(storage);
    
    return (line);
}
