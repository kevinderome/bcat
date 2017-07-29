//
// BDevice.hh for  in /home/kevin/Bureau/projet/bcat/include
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:04:45 2017 kevin
// Last update Sat Jul 29 22:35:30 2017 kevin
//

#ifndef _BDEVICE_HH_
#define _BDEVICE_HH_

#include <string>

using dots = unsigned char;

class BDevice
{
public:
  BDevice();
  bool enableAccessibilityMode();
  bool disableAccessibilityMode();
  bool writeText(const std::wstring texte);
  bool writeText(const std::string texte);
  bool writeDots(const dots *text);
  const std::string getInfo() const;
  ~BDevice();
private:
  bool accessibilityMode;
  unsigned  int	x;
  unsigned  int	y;
  std::string name;
  int socket;
  
};

#endif
