#ifndef ASSIGNMENT_1_NODE_H
#define ASSIGNMENT_1_NODE_H

#include <string>

class Node {
public:
    std::string m_line { "" };

    // Track each index
    int m_index { 0 };

    Node* m_next { nullptr };
};

#endif
