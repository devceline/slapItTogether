#include <utils/file.hpp>


void File::readFile(const char* path, char type){
    if(this->type == TEXT_FILE){
        readFileAsString(this->path);
    }
}

File::File(const char* path, char type)
    :path(path), type(type)
{
    readFile(path, type);
}

std::string* File::getStringContent() {
    return &this->stringContent;
}


void File::readFileAsString(const char* path){
    std::ifstream file;
    std::string current;
    std::vector<std::string> lines;

    int length = 0;
    file.open(path);

    while(std::getline(file, current)){
        lines.push_back(current);
        length += current.length();
    }

    std::string completeFileContents;
    completeFileContents.reserve(length);

    for(std::string line : lines){
        completeFileContents += line + '\n';
    }

    this->stringContent = completeFileContents;
    
}

