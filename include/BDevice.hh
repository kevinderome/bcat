//
// BDevice.hh for  in /home/kevin/Bureau/projet/bcat/include
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:04:45 2017 kevin
// Last update Fri Jul 21 21:13:24 2017 kevin
//

#ifndef _BDEVICE_HH_
#define _BDEVICE_HH_

#include <string>

class BDevice
{
  BDevice();
  ~BDevice();
  bool writeText(const std::string &str);
private:
  int	x;
  int	y;
  std::string name;
  
};

#endif
