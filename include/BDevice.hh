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
  bool writeText(const std::wstring& texte);
  bool writeText(const std::string& texte);
  bool writeDots(const dots *text);
  const std::string getInfo() const;
  int	readKey();
  ~BDevice();
private:
  bool accessibilityMode;
  unsigned  int	x;
  unsigned  int	y;
  std::string name;
  int socket;
  
};

#endif
