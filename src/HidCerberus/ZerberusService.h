#pragma once

#include "CoreClrHost.h"

#define POCO_NO_UNWINDOWS
#include <Poco/Util/ServerApplication.h>
#include <Poco/TaskManager.h>
#include <Poco/AutoPtr.h>

using Poco::TaskManager;
using Poco::AutoPtr;

class ZerberusService :
    public Poco::Util::ServerApplication
{
    TaskManager _taskManager;
    AutoPtr<CoreClrHost> _clrHost;

    void enumerateDeviceInterface(const std::string& name, const std::string& value);
    void help(const std::string& name, const std::string& value);
    void displayHelp() const;
    void onDeviceArrived(const void* pSender, std::string& name);
    void onDeviceRemoved(const void* pSender, std::string& name);

protected:
    void initialize(Application& self);
    int main(const std::vector<std::string>& args);
    void defineOptions(Poco::Util::OptionSet& options);
    void handleOption(const std::string& name, const std::string& value);
public:
    ZerberusService() {};
    ~ZerberusService() {};
};

