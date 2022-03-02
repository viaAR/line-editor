#include "List.h"

List::~List() {
    Node* node = m_head;

    while (node != nullptr) {
        Node* temp = node;

        node = node->m_next;
        delete temp;
    }
}

void List::add(std::string line) {

    // Create a new node for the new line to be stored
    Node* new_node = new Node();

    // Assign it's new contents
    new_node->m_line = line;

    // Track the addition of every node
    ++m_size;
    new_node->m_index = m_size;

    // Determine placement in list
    if (m_head == nullptr) {

        m_head = new_node;
    }
    else {

        Node* node = m_head;
        Node* prev = nullptr;

        // Cycle through list until the end is reached
        while (node != nullptr) {

            prev = node;
            node = node->m_next;
        }

        // Attach the new node to the end of the list
        if (prev != nullptr) {

            prev->m_next = new_node;
        }
    }
}

void List::insert(std::string line, int pos) {

    Node* new_node = new Node();
    new_node->m_line = line;

    new_node->m_index = m_size;

    // Determine where to place the new node
    int cur_pos = 1;
    Node* node = m_head;
    Node* prev = nullptr;

    while (node != nullptr) {

        // Continue advancing nodes until we find desired position
        if (cur_pos++ == pos) {
            break;
        }

        prev = node;
        node = node->m_next;
    }

    if (node != nullptr) {

        // Insert node at the head
        if (prev == nullptr) {

            new_node->m_next = m_head;
            m_head = new_node;
        }
        // Insert somewhere after head
        else {

            new_node->m_next = prev->m_next;
            prev->m_next = new_node;
        }

        // Record the increase in size
        ++m_size;
    }
    else {

        // If position is invalid, add to end of the list
        std::cout << "Position not found -- appending to end of list." << std::endl;
        add(line);
    }
}

void List::remove(int pos) {

    // Determine which node needs to be removed
    int cur_pos = 1;
    Node* node = m_head;
    Node* prev = nullptr;

    while (node != nullptr) {
        // Continue advancing nodes until we find desired position
        if (cur_pos++ == pos) {
            break;
        }

        prev = node;
        node = node->m_next;
    }
    if (node != nullptr) {

        // Trying to delete the first element
        if (prev == nullptr) {

            m_head = node->m_next;
        }
        else {

            // Not deleting first element
            prev->m_next = node->m_next;
        }

        // Update the list size
        --m_size;

        delete node;
    }
    else {

        std::cout << "The node was not found in the list." << std::endl;
    }
}

void List::remove(int from, int to) {

    int timesToLoop = to - from;
    int target = from;

    // Parameters are invalid
    if (to < from) {

        std::cout << "Invalid range." << std::endl;
        return;
    }

    // Repeat until the range has been deleted
    while (timesToLoop >= 0) {

        Node* node = m_head;
        Node* prev = node;

        // Advance until we are at the correct index
        while (node && node->m_index != target) {

            prev = node;
            node = node->m_next;
        }

        // The node could not be found
        if (node == nullptr) {

            std::cout << "Out of range." << std::endl;
            return;
        }

        // Trying to delete the first element
        if (node == m_head) {

            m_head = node->m_next;
        }
        else {

            // Not deleting first element
            prev->m_next = node->m_next;
        }

        // Delete node and record list size adjustment
        --m_size;
        delete node;

        // Increment the target to delete the next node in the range
        ++target;
        --timesToLoop;
    }
}

int List::size() {
    return m_size;
}

void List::updateIndexNumber(List &list) {

    Node* node = list.m_head;
    int count = 1;

    while (node != nullptr) {
        node->m_index = count;

        ++count;

        node = node->m_next;
    }
}

void List::displayNode(List &list, int pos) {

    // Parameter validation
    if (pos > list.m_size) {

        std::cout << "Out of range. Please check your parameters." << std::endl;
        return;
    }
    else {

        Node* node = list.m_head;

        while (node != nullptr) {

            if (node->m_index == pos) {

                std::cout << node->m_index << ">" << node->m_line << std::endl;
            }

            node = node->m_next;
        }
    }
}

void List::displayNode(List &list, int from, int to) {

    // Parameter validation
    if (from > to || to > list.m_size) {

        std::cout << "Out of range. Please check your parameters." << std::endl;
        return;
    }
    else {

        Node* node = list.m_head;

        while (node != nullptr) {

            if (node->m_index == from) {

                for (int i = from; i <= to; i++) {

                    std::cout << node->m_index << ">" << node->m_line << std::endl;
                    node = node->m_next;
                }
            }
            else {

                node = node->m_next;
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, List &list) {

    Node* node = list.m_head;

    while (node != nullptr) {
        out << node->m_index << ">" << node->m_line << "\n";
        node = node->m_next;
    }

    return out;
}

Node* List::getHeadPointer() {
    return m_head;
}
