#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "../../include/utils.hpp"

FileHandler::FileHandler(std::string file) :
_file(file)
{
    std::ifstream fileStream(file);

    if (!fileStream.is_open()) {
        createFile();
        fileStream.open(file);
    }
    _fileContent = std::string((std::istreambuf_iterator<char>(fileStream)),
        std::istreambuf_iterator<char>());
    fileStream.close();
}

FileHandler::~FileHandler() {}

void FileHandler::saveFile()
{
    std::ofstream fileStream(_file);

    if (!fileStream.is_open())
        throw std::runtime_error("FileHandler: File not found");
    fileStream << _fileContent;
    fileStream.close();
}

void FileHandler::createFile()
{
    std::ofstream fileStream(_file);

    if (!fileStream.is_open())
        throw std::runtime_error("FileHandler: Cannot create file");
    fileStream.close();
}
