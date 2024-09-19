/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoroz <vmoroz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:00:06 by vmoroz            #+#    #+#             */
/*   Updated: 2024/02/17 14:24:35 by vmoroz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_read_to_next_str(int fd, char *next_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(next_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		next_str = ft_strjoin(next_str, buff);
	}
	free(buff);
	return (next_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*next_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_str[fd] = ft_read_to_next_str(fd, next_str[fd]);
	if (!next_str[fd])
		return (NULL);
	str = ft_get_line(next_str[fd]);
	next_str[fd] = ft_new_next_str(next_str[fd]);
	return (str);
}

// int	main(int argc, char *argv[])
// {
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	i = 1;
// 	if (argc < 2)
// 	{
// 		printf("Do like this dude: %s <file1> [file2 file3 ...]\n", argv[0]);
// 		return (1);
// 	}
// 	while (i < argc)
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			printf("%s", "Error opening file");
// 			break ;
// 		}
// 		while ((line = get_next_line(fd)) != NULL)
// 		{
// 			printf("Line: %s\n", line);
// 			free(line);
// 		}
// 		close(fd);
// 		i++;
// 	}
// 	return (0);
// }
