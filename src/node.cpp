#include "../include/node.hpp"

Node::Node(char character, int frequency) 
    : character(character), frequency(frequency), left(nullptr), right(nullptr) {}

Node::Node(int frequency, Node* left, Node* right) 
    : character(0), frequency(frequency), left(left), right(right) {}

Node::~Node() {
    delete left;
    delete right;
}
