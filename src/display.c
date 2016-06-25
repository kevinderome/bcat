/*
** put_brl.c for  in /home/derome_k/rendu/functions_library
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Wed Nov 11 02:23:44 2015 Kevin Derome
** Last update Wed Jun 22 00:44:06 2016 Kevin Derome
*/

#include <brlapi.h>
#include <unistd.h>
#include <stdlib.h>
#include "braille.h"

int	get_display_size(unsigned int *x)
{
  unsigned int	tmp;
  brlapi_getDisplaySize(x, &tmp);
  return (0);
}

int	put_brl(char *str)
{
  brlapi_keyCode_t key;

  if (brlapi_writeText(0, str) < 0)
    return (printf("bcat: faille to write on the braille display\n"), -3);
  if (brlapi_readKey(8, &key) < 0)
    return (printf("bcat: get keys failled\n"), -4);
  return (key);
}

void	virtual_reading(char ***text)
{
  int	l;
  int	nav_k[8];
  int	key;
  void	(*nav_func[8])();
  int	p[2];

  nav_function(nav_func);
  p[0] = 0;
  p[1] = 0;
  nav_k[0] = LEFT_DISPLAY;
  nav_k[1] = RIGHT_DISPLAY;
  nav_k[2] = UP_DISPLAY;
  nav_k[3] = DOWN_DISPLAY;
  nav_k[4] = LINE_KEY;
  nav_k[5] = BEGIN_FILE;
  nav_k[6] = MIDLE_FILE;
  nav_k[7] = END_FILE;
  key = 0;
  while (key != 'x')
    {
      l = -1;
      while (++l < 8)
	if (key == nav_k[l])
	  nav_func[l](text, p);
      if ((key = put_brl(text[p[0]][p[1]])) < 0)
	exit(-2);
    }
}

void	print(char ***txt)
{
  int	i;
  int	j;

  j = -1;
  while (txt[++j])
    {
      i = -1;
      while (txt[j][++i])
	write(1, txt[j][i], my_strlen(txt[j][i]));
      write(1, "\n", 1);
    }
}
