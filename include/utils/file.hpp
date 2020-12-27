#ifndef FILE_ABSTRACTION
#define FILE_ABSTRACTION

#include <fstream>
#include <string>
#include <vector>

#define TEXT_FILE 's'


class File {
    private:
        std::ofstream fileStream;
        char type;
        const char* path;
        std::string stringContent;
        std::vector<unsigned char> byteContent;
        void readFile(const char* path, char type);
        void readFileAsString(const char* path);

    public:
        File(const char* path, char type);
        std::string* getStringContent();
        void openFile(const char* path, char type);
};


#endif /* ifndef FILE_ABSTRACTION */
