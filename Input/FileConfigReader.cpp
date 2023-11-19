#include "FileConfigReader.h"
#include "../Command/ExitCommand.h"
#include "../Command/MoveCommand.h"
#include <sstream>
#include <algorithm>

void FileConfigReader::tokenizeLine(const std::string &line, std::vector<std::string> &out)
{
    std::istringstream iss(line);
    std::string token;
    while(std::getline(iss, token, CONFIG_DELIM))
        out.push_back(token);
}

std::shared_ptr<ICommand> FileConfigReader::convertToCommand(const std::string &str)
{
    if (str == "MVUP") {
        return std::make_shared<MoveCommand>(Direction::up);
    } else if (str == "MVDOWN") {
        return std::make_shared<MoveCommand>(Direction::down);
    } else if (str == "MVLEFT") {
        return std::make_shared<MoveCommand>(Direction::left);
    } else if (str == "MVRIGHT") {
        return std::make_shared<MoveCommand>(Direction::right);
    } else if (str == "EXIT") {
        return std::make_shared<ExitCommand>();
    } else {
        throw std::invalid_argument("Invalid config: undefined action or incorrect formatting");
    }
}

FileConfigReader::FileConfigReader(const std::string &filename): file{filename}
{
    if (!file.is_open()) 
        throw std::runtime_error("Could not open file " + filename);
}

FileConfigReader::~FileConfigReader()
{
    file.close();
}

std::map<char, std::shared_ptr<ICommand>> FileConfigReader::readConfig()
{
    std::map<char, std::shared_ptr<ICommand>> key_map;
    std::string line;
    while(std::getline(file, line)) {
        std::vector<std::string> tokenized;
        tokenizeLine(line, tokenized);
        if (tokenized.size() != 2 || tokenized[0].length() != 1)
            throw std::invalid_argument("Invalid config formatting");

        char key = std::toupper(*(tokenized[0].c_str()));
        if (key_map.count(key) != 0)
            throw std::invalid_argument(std::string("Invalid config: repeated key ") + key);
        
        std::transform(tokenized[1].begin(), tokenized[1].end(), tokenized[1].begin(), ::toupper);
        if (assigned_actions.count(tokenized[1])!= 0)
            throw std::invalid_argument("Invalid config: repeated action");
        assigned_actions.insert(tokenized[1]);
        if (tokenized[1].size() > 0)
            key_map[std::toupper(key)] = convertToCommand(tokenized[1]);
    }
    if (key_map.size() != static_cast<int>(Command::COUNT))
        throw std::invalid_argument("Invalid config: incorrect amount of commands");
        
    return key_map;
}
