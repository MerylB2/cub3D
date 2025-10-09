#include "../../includes/cub3d.h"

int ft_strlen(const char *s)
{
    int i;
    
    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    
    i = 0;
    while (i < n && (s1[i] || s2[i]))
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        i++;
    }
    return (0);
}

char *ft_strdup(const char *s)
{
    char    *dup;
    int     i;
    
    if (!s)
        return (NULL);
    dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;
    
    i = 0;
    sign = 1;
    result = 0;
    
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return (result * sign);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  i;
    size_t  s_len;
    
    if (!s)
        return (NULL);
    
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    
    if (len > s_len - start)
        len = s_len - start;
    
    sub = malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    
    i = 0;
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    
    return (sub);
}
