/*
** get_next_line.h for  in /home/maison_f/Epitech/rendu/CPE_2015_getnextline
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Thu Mar 10 03:54:11 2016 Maisonnave Florian
** Last update Wed Jun  7 11:45:05 2017 kevin
*/

# ifndef GET_NEXT_LINE_H_
# ifndef READ_SIZE
# define READ_SIZE (42)

# endif /* !READ_SIZE */

# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

char	*empty_after_buff(char*);
char	*check(char*, char*, int);
int	check_buff_lines(char*, int);
char	*realloc_stock(char*, char*, int);
char	*get_next_line(const int);
void	cleanStr(char **str);

# endif /* !GET_NEXT_LINE_H_ */
