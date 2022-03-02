#include <iostream>
#include "List.h"
#include "FileIO.h"
#include "Parser.h"

int main(int argc, char** argv) {

    // Handle file
    FileIO file;
    std::string filename;

    // Handle input
    List list;
    Parser parser;
    std::string input;

    if (argc > 1) {
        filename = argv[1];

        if (file.validateFileType(filename)) {

            // Open a file / create new file and read into the node
            file.readInFileContents(list, filename);

            while (input != "E") {

                // Get input from the user
                std::cout << list.size()+1 << ">";
                getline(std::cin, input);
                parser.parseInput(input, list);
            }

            // Write back to the file before exit
            file.writeToFile(list, filename);
        }
        else {

            file.failedParse(filename);
        }
    }
    else {

        file.failedParse(filename);
    }
    return 0;
}