#include "includes/fdf.h"

static size_t		ft_strlenc(const char *s)
{
	size_t	ret;

	ret = 0;
	if (s)
		while (ft_isdigit(s[ret]))
			++ret;
	return (ret);
}

static char			*ft_strcpyc(char *dst, const char *src)
{
	char	*tsrc;
	char	*tdst;

	tdst = dst;
	tsrc = (char*)src;
	if (tsrc && tdst)
	{
		while (ft_isdigit(*tsrc))
			*tdst++ = *tsrc++;
		*tdst = 0;
	}
	return (dst);
}

static char			*ft_strdupc(const char *s1)
{
	char	*ret;

	ret = NULL;
	if (s1)
	{
		if ((ret = (char*)malloc(ft_strlenc(s1) + 1)) == NULL)
			return (NULL);
		ft_strcpyc(ret, s1);
	}
	return (ret);
}

static int			ft_splitstr(char **tab, char *s, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		while (!ft_isdigit(*s) && *s)
			++s;
		if ((tab[i] = ft_strdupc(s)) == NULL)
			return (0);
		while (ft_isdigit(*s) && *s)
			++s;
		++i;
	}
	tab[i] = 0;
	return (1);
}

static unsigned int	ft_split_count(char *s)
{
	unsigned int	ret;
	ret = 0;
	while (!ft_isdigit(*s))
		++s;
	while (*s)
	{
		while (ft_isdigit(*s) && *s)
			++s;
		while (!ft_isdigit(*s) && *s)
			++s;
		++ret;
	}
	s[ret] = '\0';
	return (ret);
}

char				**ft_strsplit_fdf(char const *s)
{
	char			**ret;
	unsigned int	len;

	ret = NULL;
	if (s)
	{
		len = ft_split_count((char*)s);
		if ((ret = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
			return (NULL);
		if (ft_splitstr(ret, (char*)s, len))
			return (ret);
		else
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);
}