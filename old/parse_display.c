/*
** parse_display.c for � in /home/derome_k/Bureau/PSU_2015_42sh/bcat/src
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Sun Jun  5 22:01:43 2016 Kevin Derome
** Last update Sun Jul 16 16:05:01 2017 kevin
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "braille.h"

void	cleanStr(char **str)
{
  int	i;

  i = -1;
  if (*str)
    while ((*str)[++i])
      if ((*str)[i] < ' ' && (*str)[i] >= '\0')
	(*str)[i] = ' ';
}

char	*get_display(char *str, int size)
{
  static int	i = 0;
  char	*new;
  int	j;
  int	k;

  if (str == NULL || size == 0)
    return (i = 0, NULL);
  else if (my_strlen(str) == i)
    return (NULL);
  j = -1;
  k = i;
  while (str[i] != 0 && i <= (k + size - 1) && str[i] != '\n')
    ++i;
  if (! (new = malloc(sizeof(char) * (i - k + 2))))
    exit(-1);
  while (k < i)
    new[++j] = str[k++];
  new[++j] = 0;
  return (new);
}

char	**split_display(char *str, int size)
{
  int	j;
  float	tmp;
  int	tsize;
  char	**ctab;

  tmp = my_strlen(str) / size;
  j = -1;
  tsize = ((tmp - (int)tmp == 0) ? (int)tmp + 1 : (int)tmp);
  if (! (ctab = malloc(sizeof(char *) * (tsize + 1))))
    exit(-1);
  if (my_strlen(str) > size)
    while (++j < tsize)
      ctab[j] = get_display(str, size);
  else
    {
      if (! (ctab[++j] = my_strdup(str)))
	exit(-1);
      ++j;
    }
  ctab[j] = get_display(NULL, 0);
  return (ctab);
}

char	**extract_file(char *name)
{
  char	*tmp;
  char	**lines;
  int	l;
  int	fd;

  l = 0;
  if (name)
    {
      if ((fd = open(name, O_RDONLY)) == -1)
	exit(-1);
    }
  else
    fd = 0;
  while ((tmp = get_next_line(fd)) && ++l)
    free(tmp);
  lseek(fd, SEEK_SET, 0);
  if (! (lines = malloc(sizeof(char *) * (l + 1))))
    return (NULL);
  l = -1;
  while ((lines[++l] = get_next_line(fd)) != NULL);
  return (lines);
}

char	***convert_display(char **txt, int size)
{
  char	***display;
  int	i;

  i = -1;
  if (! (display = malloc(sizeof(char **) * (len_tab(txt) + 1))))
    exit(-1);
  while (txt[++i])
    display[i] = split_display(txt[i], size);
  display[i] = NULL;
  free_tab((void **)txt);
  return (display);
}
