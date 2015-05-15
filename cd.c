#include "minishell.h"

int     b_cd(const char **cmd)
{
	char	*path[2];
	char	buf[256];

	chdir(cmd[0]);
	path[1] = getcwd(buf, 256);
	path[0] = ft_strdup("PWD");
	b_setenv((const char**)path);
	free(path[0]);
	return (0);
}

int     b_env(const char **cmd)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i + 1])
	{
		ft_putstr(environ[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int     b_setenv(const char **cmd)
{
	char	*tmp;
	extern char	**environ;
	int			i;
	char	*buf;

	i = 0;
	if (!(tmp = ft_getenv(cmd[0])))
	{
		while (environ[i])
			i++;
		buf = (char*)malloc(ft_strlen(cmd[0]) + ft_strlen(cmd[1]) + 1);
		ft_strcpy(buf, cmd[0]);
		ft_strcat(buf, "=");
		ft_strcat(buf, cmd[1]);
		environ[i] = buf;
	}
	else
	{
		ft_memset(tmp, '\0', ft_strlen(tmp));
		ft_strcpy(tmp, cmd[1]);
	}
	return (0);
}

int     b_unsetenv(const char **cmd)
{
    ft_putstr("unsetenv\n");
	return (0);
}
