#include "BDevice.hh"

#include <brlapi.h>
#include <iostream>
#include <stdio.h>

BDevice::BDevice() : accessibilityMode(false), x(0), y(0)
{
  name.resize(BRLAPI_MAXNAMELENGTH + 1);
  this->socket = brlapi_openConnection(NULL, NULL);
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

bool BDevice::writeText(const std::wstring& texte)
{
  if (brlapi_writeWText(0, texte.c_str()) < 0)
    return (false);
  return (true);
}

bool BDevice::writeText(const std::string& texte)
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

int	BDevice::readKey()
{
  brlapi_keyCode_t	key;
  
  brlapi_readKey(8, &key);
  
      switch(key) {
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_LNUP: return 1;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_LNDN: return 2;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_FWINLT: return 3;
      case BRLAPI_KEY_TYPE_CMD|BRLAPI_KEY_CMD_FWINRT: return 4;
      case 'n': return 5;
      case 'c': return 6;
      case ':': return 7;
      case '-': return 8;
      case 'x': return 9; break;
      }
  return (key);
}

BDevice::~BDevice()
{
  brlapi_closeConnection();
}
