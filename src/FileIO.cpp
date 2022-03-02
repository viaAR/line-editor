#include "FileIO.h"

FileIO::~FileIO() {}

void FileIO::readInFileContents(List &list, std::string &filename) {

    std::ifstream ifs;

    // Reading from a file with contents already in it
    ifs.open(filename, std::ifstream::in);

    if (ifs.is_open()) {

        std::string line;

        while (getline(ifs, line)) {

            list.add(line);
        }

        ifs.close();
    }
    else {

        // Valid filename but does not exist
        std::cout << "File does not exist! Creating a file." << std::endl;
    }
}

void FileIO::writeToFile(List &list, std::string &filename) {

    // Write the contents back to the file
    std::ofstream ofs(filename);

    if (ofs.is_open()) {

        Node* node = list.getHeadPointer();
        std::string line;

        while (node != nullptr) {
            line = node->m_line;

            ofs << line << "\n";

            node = node->m_next;
        }

        ofs.close();
    }
}

bool FileIO::validateFileType(std::string filename) {

    // Parse the string for the extension type
    if (filename.substr(filename.find_last_of(".") + 1 ) == "txt") {
        return true;
    }
    else {
        return false;
    }
}

void FileIO::failedParse(std::string filename) {
    if (filename.empty()) {

        std::cout << "Missing file name." << std::endl;
        std::cout << "Format: EDIT <filename.txt>" << std::endl;
    }
    else {

        std::cout << "Incorrect file type! You provided: " << filename << std::endl;
        std::cout << "Format: EDIT <filename.txt>" << std::endl;
    }
}


