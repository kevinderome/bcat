/*
** get_next_line.c for  in /home/maison_f/Epitech/rendu/CPE_2015_getnextline
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Thu Mar 10 03:54:00 2016 Maisonnave Florian
** Last update Wed May 11 17:41:32 2016 Kevin Derome
*/

#include "get_next_line.h"

char	*realloc_stock(char *buff, char *stock, int size)
{
  char	*str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((str = malloc(size + 1)) == NULL)
    return (NULL);
  while (i <= size)
    str[i++] = 0;
  i = -1;
  if (stock != NULL)
    while (stock[++i] != 0)
	str[i] = stock[i];
      free(stock);
  i = 0;
  k = 0;
  while (str[i] != 0)
    i++;
  while ((buff[k]) && (buff[k] != '\n'))
    str[i++] = buff[k++];
  return (str);
}

char	*empty_after_buff(char *buff)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  while ((buff[i] != '\n'))
    i++;
  i++;
  while (buff[i] != '\0')
    {
      buff[k] = buff[i];
      i++;
      k++;
    }
  buff[k] = '\0';
  return (buff);
}

char	*check(char *buff, char *stock, int nb)
{
  if (check_buff_lines(buff, nb) <= 0)
    return (NULL);
  buff = empty_after_buff(buff);
  if ((stock = realloc_stock(buff, stock, READ_SIZE)) == NULL)
    return (NULL);
  if (check_buff_lines(buff, nb))
    return (stock);
  else
    return (stock);
}

int	check_buff_lines(char *str, int nb)
{
  int	i;
  int	k;

  i = 0;
  k = 0;
  if (nb == 1)
    {
      while (str[i] != '\0')
	i++;
      return (i);
    }
  if (nb == 2)
    {
      while (str[i] != '\0')
      {
        if (str[i] == '\n')
          k++;
        i++;
      }
      return (k);
    }
  return (-1);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  char		*stock;
  int		rd;
  int		size_malloc;
  int		nb;

  stock = NULL;
  size_malloc = 0;
  nb = 2;
  stock = check(buff, stock, nb);
  if (check_buff_lines(buff, nb))
    return (stock);
  while ((rd = read(fd, &buff, READ_SIZE)))
    {
      size_malloc += rd + READ_SIZE;
      buff[rd] = '\0';
      stock = realloc_stock(buff, stock, size_malloc);
      if (check_buff_lines(buff, nb))
	return (stock);
    }
  if (buff[0])
    return (stock);
  free(stock);
  return (NULL);
}
