#include "FIle.h"
#include <fstream>
FileManager::FileManager(const std::string& filename){
    this->input_file = filename;
}
std::ifstream FileManager::read_ifstrean(){
    std::ifstream inputing(this->input_file);
    this->reader = inputing;
    return inputing;
}
FileManager::~FileManager(){
    this->reader.close();
}