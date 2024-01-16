#pragma once

#include <string>

class FileHandler
{
public:
    FileHandler(std::string file);
    ~FileHandler();
    void saveFile();
    void createFile();
    std::string getFileContent();

private:
    std::string _fileContent;
    stf::string _file;
};
