//
// BDevice.cpp for  in /home/kevin/Bureau/projet/bcat
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:02:20 2017 kevin
// Last update Sat Jul 29 22:36:46 2017 kevin
//

#include <brlapi.h>
#include <iostream>
#include "BDevice.hh"

BDevice::BDevice() : accessibilityMode(false), x(0), y(0)
{
  name.resize(BRLAPI_MAXNAMELENGTH + 1);
this->socket = brlapi_openConnection(NULL, NULL);
 std::cout << "socket=" << this->socket << std::endl;
  brlapi_getDisplaySize(&x, &y);
  brlapi_getDriverName(&name[0], BRLAPI_MAXNAMELENGTH + 1);
}

bool BDevice::enableAccessibilityMode()
{
  if (! this->accessibilityMode)
    if (brlapi_enterTtyMode(BRLAPI_TTY_DEFAULT, NULL) >= 0)
      this->accessibilityMode = true;
  return (this->accessibilityMode);
}

bool BDevice::disableAccessibilityMode()
{
  if (this->accessibilityMode)
    if (brlapi_leaveTtyMode() >= 0)
      this->accessibilityMode = false;
  return (this->accessibilityMode);
}

bool BDevice::writeDots(const dots *text)
{
  if (brlapi_writeDots(text) < 0)
    return (false);
  return (true);
}

bool BDevice::writeText(const std::wstring texte)
{
  if (brlapi_writeWText(0, texte.c_str()) < 0)
    return (false);
  return (true);
}

bool BDevice::writeText(const std::string texte)
{
  if (brlapi_writeText(0, texte.c_str()) < 0)
    return (false);
  return (true);
}

const std::string BDevice::getInfo() const
{
  std::string info;
  info.resize(128);
  sprintf(&info[0], "%s:cell=%u:Line=%u", name.c_str(), this->x, this->y);
  return (info);
}

BDevice::~BDevice()
{
  brlapi_closeConnection();
}
