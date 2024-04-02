#include <stdlib.h>
#include <stdio.h>

int     ft_worcount(char *str)
{
    int i = 0;
    int wc = 0;
    while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
    return(wc);
}

char    *ft_strsplit(char *str, int *index)
{
    int i = &index;
}

char    **ft_split(char *str)
{
    int i = 0;
    int index = 0;
    int len = ft_worcount(str);
    char **arr = (char *)malloc(sizeof(char *) * (len + 1));
    if (!arr)
        return(NULL);
    while (i < len)
    {
        arr[i] = ft_strsplit(str, index);
        if (!arr)
        {
            return(NULL);
        }
        i++;
    }
    
}


int main()
{
    char str[] = " hey bro was gud ";
    int len = ft_worcount(str);
    printf("%d", len);
    return(0);
}