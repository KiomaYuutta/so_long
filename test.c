#include "so_long.h"

int	main(void)
{
	int	fd;
	char	*str;

	fd = open("map3.ber", O_RDONLY);
	str = get_next_line(fd);
	ft_printf("%d\n", ft_strlen(str));
	close(fd);
	free(str);
}