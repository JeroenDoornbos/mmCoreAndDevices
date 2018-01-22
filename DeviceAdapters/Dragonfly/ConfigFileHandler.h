///////////////////////////////////////////////////////////////////////////////
// FILE:          ConfigFileHandler.h
// PROJECT:       Micro-Manager
// SUBSYSTEM:     DeviceAdapters
//-----------------------------------------------------------------------------
#ifndef _CONFIGFILEHANDLER_H_
#define _CONFIGFILEHANDLER_H_

#include <map>
#include "Property.h"
#include "ConfigFileHandlerInterface.h"

class CDragonfly;

class CConfigFileHandler : public IConfigFileHandler
{
public:
  CConfigFileHandler( CDragonfly* MMDragonfly );
  ~CConfigFileHandler();

  int LoadConfig();

  int OnConfigFileChange( MM::PropertyBase* Prop, MM::ActionType Act );
  typedef MM::Action<CConfigFileHandler> CPropertyAction;

  void SetFileName( const std::string& FileName );
  int UpdateFileName();
  int UpdateFileName(const std::string& FileName);
  int TestFileName( const std::string& FileName ) const;
  std::string GetFileName() const { return FileName_; }

  virtual bool LoadPropertyValue( const std::string& PropertyName, std::string& PropertyValue );
  virtual void SavePropertyValue( const std::string& PropertyName, const std::string& PropertyValue );

private:
  std::string FileName_;
  std::string RequestedFileName_;
  std::map<std::string, std::string> Config_;
  CDragonfly* MMDragonfly_;

  void SaveConfig();
};
#endif