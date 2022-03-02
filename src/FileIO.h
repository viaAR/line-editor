#ifndef ASSIGNMENT_1_FILEIO_H
#define ASSIGNMENT_1_FILEIO_H

#include <fstream>
#include "List.h"

class FileIO {
public:
    FileIO(){};
    ~FileIO();

    void readInFileContents(List&, std::string&);
    void writeToFile(List&, std::string&);
    bool validateFileType(std::string filename);
    void failedParse(std::string);
};


#endif