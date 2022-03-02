#ifndef ASSIGNMENT_1_PARSER_H
#define ASSIGNMENT_1_PARSER_H

#include "List.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

class Parser {
public:
    Parser(){};
    ~Parser(){};

    std::string gatherInput();
    void parseInput(std::string&, List&);
    bool isNumber(std::string&);
    std::vector<int>parseArgs(std::string&);
};

#endif