#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include "node.hpp"
using namespace std;
class Huffman {
public:
    Huffman(const string& text);
    
    string compress();
    string decompress();
    void print();
    void saveTree(const string& filename);
    void loadTree(const string& filename);

private:
    void calculateFrequency();
    Node* buildHuffmanTree();
    void generateCodes(Node* root, const string code);
    
    string text;  
    string compress_text="";
    unordered_map<char, int> frequencyMap;  
    unordered_map<char, string> codes;  
    Node* root;  
};

#endif // HUFFMAN_H
