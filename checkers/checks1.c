/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dide-alm <dide-alm@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:26:40 by dide-alm          #+#    #+#             */
/*   Updated: 2025/12/22 12:38:27 by dide-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		return (0);
	}
	return (1);
}

int	ft_check_mapextension(char *name)
{
	char	*start;

	start = ft_strnstr(name, ".ber", ft_strlen(name));
	if (start == 0 || start[4] != 0)
	{
		ft_printf("Error\nInvalid map extension\n");
		return (0);
	}
	return (1);
}

int	ft_check_mapexist(char *name, t_map_man *map_man)
{
	int	isopen;

	isopen = open(name, O_RDONLY);
	if (isopen == -1)
	{
		ft_printf("Error\nFile doesn't exist\n");
		return (0);
	}
	map_man->map_name = name;
	map_man->map_fd = isopen;
	return (isopen);
}

int	ft_check_mapshape(t_map_man *map_man)
{
	size_t  cnt;

        cnt = 0;
        if (ft_setmap_check(map_man) == 0)
                return (0);
        while (cnt < map_man->y_size - 1)
        {
                if ((ft_strlen(map_man->map[cnt]) - 2) != map_man->x_size)
                {
                        ft_printf("Error\nMap shape is not a rectangle\n");
                        return (0);
                }
                cnt++;
        }
        if (ft_strlen(map_man->map[cnt]) != map_man->x_size)
        {
                ft_printf("Error\nMap shape is not a rectangle\n");
                return (0);
        }
        return (1);
}

int	ft_checkwalls(t_map_man *man)
{
	size_t	cs;
	size_t	cc;

	cs = 0;
	cc = 0;
	while (cc < man->x_size)
	{
		if (man->map[cs][cc] != '1' || man->map[man->y_size - 1][cc] != '1')
		{
			ft_printf("Error\nMap is not closed\n");
			return (0);
		}
		cc++;
	}
	cc--;
	while (cs < man->y_size - 1)
	{
		if (man->map[cs][0] != '1' || man->map[cs][cc] != '1')
		{
			ft_printf("Error\nMap is not closed\n");
			return (0);
		}
		cs++;
	}
	return (1);
}
