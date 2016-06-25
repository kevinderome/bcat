/*
** my_strdup.c for  in /home/derome_k/rendu/my_42sh
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Mon May 30 09:53:33 2016 Kevin Derome
** Last update Wed Jun  8 03:09:12 2016 Kevin Derome
*/

#include <stdlib.h>
#include "braille.h"

int	my_strlen(char *str)
{
  char	*tmp;

  if (!str)
    return (0);
  tmp = str;
  while (*tmp)
    ++tmp;
  return (tmp - str);
}

int	len_tab(char **ctab)
{
  char	**tmp;

  if (!ctab)
    return (0);
  tmp = ctab;
  while (*tmp)
    ++tmp;
  return (tmp - ctab);
}

char	*my_strdup(char *str)
{
  int	i;
  char	*new;

  i = -1;
  if (! (new = malloc(sizeof(char) * (my_strlen(str) + 1))))
    return (NULL);
  while (str[++i])
    new[i] = str[i];
  new[i] = 0;
  return (new);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (s1[++i])
    if (s1[i] == s2[j])
      ++j;
  if (j == my_strlen(s1))
    return (1);
  return (0);
}
