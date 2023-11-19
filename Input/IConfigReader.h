#ifndef I_CONFIG_READER_H
#define I_CONFIG_READER_H

#include <map>
#include <memory>

class ICommand;

class IConfigReader
{
public:
    virtual std::map<char, std::shared_ptr<ICommand>> readConfig() = 0;
};

#endif
