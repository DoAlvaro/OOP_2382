#ifndef FILE_h
#define FILE_h
#include <iostream>
#include <string.h>
#include <fstream>
class FileManager{
    std::string& input_file;
    std::ifstream& reader;
    public:
        FileManager(const std::string& filename);
        std::ifstream read();
        ~FileManager();
};
#endif 