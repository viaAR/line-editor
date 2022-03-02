#ifndef ASSIGNMENT_1_LIST_H
#define ASSIGNMENT_1_LIST_H

#include <iostream>
#include <fstream>
#include "Node.h"

class List {
private:
    Node* m_head { nullptr };
    int m_size = 0;

public:
    List(){};
    virtual ~List();

    void add(std::string);
    void insert(std::string, int);
    void remove(int);
    void remove(int, int);
    int size();
    void updateIndexNumber(List &list);
    void displayNode(List&, int);
    void displayNode(List&, int, int);
    Node* getHeadPointer();

    friend std::ostream& operator<<(std::ostream& out, List& list);
};

#endif