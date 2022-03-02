#include "Parser.h"

std::string Parser::gatherInput() {

    std::string input;

    std::cout << ">";
    getline(std::cin, input);

    return input;
}

void Parser::parseInput(std::string &input, List &list) {

    // Access the input through a vector
    std::stringstream ss(input);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> strVec(begin, end);

    std::string command;
    std::vector<int> commandArgs;

    // Gather the arguments for the command
    commandArgs = parseArgs(input);

    for (int i = 0; i < 1; i++) {

        // I command
        if (strVec[0] == "I" && strVec.size() == 1) {

            list.insert(gatherInput(), list.size());
        }
        else if (strVec[0] == "I" && isNumber(strVec[1]) && strVec.size() == 2) {

            list.insert(gatherInput(), commandArgs[0]);
        }
        // D command
        else if (strVec[0] == "D" && strVec.size() == 1) {

            list.remove(list.size());
        }
        else if (strVec[0] == "D" && isNumber(strVec[1]) && strVec.size() == 2) {

            list.remove(commandArgs[0]);
        }
        else if (strVec[0] == "D" && isNumber(strVec[1]) && isNumber(strVec[2]) && strVec.size() == 3) {

            list.remove(commandArgs[0], commandArgs[1]);
            list.updateIndexNumber(list);
        }
        // L command
        else if (strVec[0] == "L" && strVec.size() == 1) {

            list.updateIndexNumber(list);
            std::cout << list;
        }
        else if (strVec[0] == "L" && isNumber(strVec[1]) && strVec.size() == 2) {

            list.updateIndexNumber(list);
            list.displayNode(list, commandArgs[0]);
        }
        else if (strVec[0] == "L" && isNumber(strVec[1]) && isNumber(strVec[2]) && strVec.size() == 3) {

            list.updateIndexNumber(list);
            list.displayNode(list, commandArgs[0], commandArgs[1]);
        }
        // Regular input
        else {

            // Don't write "E" command into the file
            if (strVec[0] == "E" && strVec.size() == 1) {

                std::cout << "Goodbye!" << std::endl;
            }
            else {

                list.add(input);
            }
        }
    }
}

bool Parser::isNumber(std::string &s) {

    // Return true if the string can be converted to a digit, false otherwise
    return !s.empty() && std::find_if(s.begin(),s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

std::vector<int> Parser::parseArgs(std::string &input) {

    // From the input provided, parse the ints as the arguments
    std::stringstream ss(input);
    std::vector<int> ivec;
    int arg;
    std::string temp;

    while (!ss.eof()) {

        ss >> temp;

        if (std::stringstream(temp) >> arg) {

            ivec.push_back(arg);
        }

        temp = "";
    }

    return ivec;
}
