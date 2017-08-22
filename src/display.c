
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
  int	key;
  int	p[2];

  p[0] = 0;
  p[1] = 0;
  key = 0;
  while (key != 'x')
    {
      switch(key =   put_brl(text[p[0]][p[1]])) {
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_LNUP: move_up(text, p); break;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_LNDN: move_down(text, p); break;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_FWINLT: move_left(text, p); break;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_FWINRT: move_right(text, p); break;
      case 'n': get_nb_line(text, p); break;
      case 'c': begin_file(text, p); break;
      case ':': midle_file(text, p); break;
      case '-': end_file(text, p); break;
      default: break;
      }
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
