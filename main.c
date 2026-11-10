/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:20:31 by username          #+#    #+#             */
/*   Updated: 2026/11/06 12:15:38 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*path;
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;

	fd1 = 0;
	if (argc > 1)
	{
		path = argv[1];
		fd1 = open(path, O_RDONLY);
		if (fd1 == -1)
			return (EXIT_FAILURE);
	}
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd1);
	}
	close(fd1);
	fd2 = open("sample2.txt", O_RDONLY);
	if (fd2 == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd2);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd2);
	}
	close(fd2);
	fd3 = open("sample3.txt", O_RDONLY);
	if (fd3 == -1)
		return (EXIT_FAILURE);
	line = get_next_line(fd3);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd3);
	}
	close(fd3);
	return (0);
}
