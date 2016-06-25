/*
** special_key.c for  in /home/derome_k/Bureau/bcat
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Fri Jun 10 00:43:53 2016 Kevin Derome
** Last update Sun Jun 12 00:07:47 2016 Kevin Derome
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "braille.h"

void	get_nb_line(char ***txt, int *p)
{
  char	info[50];
  int	l;

  l = -1;
  while (txt[++l]);
  sprintf(info, "%d/%d", (p[0] + 1), l);
  put_brl(info);
}

void	begin_file(char ***txt, int *p)
{
  (void)txt;
  p[0] = 0;
  p[1] = 0;
}

void	midle_file(char ***txt, int *p)
{
  int	l;

  l = -1;
  while (txt[++l]);
  p[0] = (--l / 2);
  p[1] = 0;
}

void	end_file(char ***txt, int *p)
{
  (void)txt;
  int	l;

  l = -1;
  while (txt[++l]);
  p[0] = --l;
  p[1] = 0;
}
