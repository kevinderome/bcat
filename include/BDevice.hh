//
// BDevice.hh for  in /home/kevin/Bureau/projet/bcat/include
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:04:45 2017 kevin
// Last update Sat Jul 22 01:28:24 2017 kevin
//

#ifndef _BDEVICE_HH_
#define _BDEVICE_HH_

#include <string>

class BDevice
{
public:
  BDevice();
  ~BDevice();
  bool writeText(std::wstring texte);
  bool writeText(std::string texte);
  bool writeDots(const unsigned char *dots);
private:
  unsigned  int	x;
  unsigned  int	y;
  std::string name;
  
};

#endif
