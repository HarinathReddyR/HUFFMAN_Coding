#include "../include/huffman.hpp"
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;
auto comparator=[](Node* a,Node *b){ return a->frequency>b->frequency;};

Huffman::Huffman(const string& text) : text(text), root(nullptr) {
    calculateFrequency();
    root = buildHuffmanTree();
    generateCodes(root, "");
}


void printTree(Node* root,string prefix = ""){
    if (root == nullptr) 
        return;
    if (root->left == nullptr && root->right == nullptr) 
        cout << prefix << "Character: " << root->character << " Frequency: " << root->frequency << endl;
    else 
        cout << prefix << "Internal Node Frequency: " << root->frequency << endl;
    printTree(root->left, prefix + "    ");
    printTree(root->right, prefix + "    ");
}


void Huffman::print(){
    cout<<text<<'\n';
    // cout<<compress_text<<'\n';
    // printTree(root," ");

}


void Huffman::calculateFrequency(){
    for(char ch:text)
        frequencyMap[ch]++;
}

Node* Huffman::buildHuffmanTree(){
    priority_queue<Node*, vector<Node*>, decltype(comparator)> pq(comparator);
    for(auto l:frequencyMap){
        pq.push(new Node(l.first,l.second));
    }
    while(pq.size()!=1){
        // cout<<"in\n";
        Node *l= pq.top();
        pq.pop();
        Node *r=pq.top();
        pq.pop();

        Node *newNode = new Node(l->frequency+r->frequency,l,r);
        pq.push(newNode);
    }
    return pq.top();
}

void Huffman::generateCodes(Node* root,const string code){
    if(root==nullptr) return;
    if(root->left==NULL && root->right==NULL){
        // cout<<root->character<<" "<<code;
        codes[root->character]=code;
        return;
    }
    generateCodes(root->left,code+"0");
    generateCodes(root->right,code+"1");
}

string Huffman::compress(){
    for(char ch:text){
        compress_text+=codes[ch];
        // cout<<ch<<' '<<codes[ch]<<'\n';
    }
    return compress_text;
}

string Huffman::decompress(){
    if(compress_text=="")
        return "";
    string decompress="";
    Node* curr_node=root;
    for(char c : compress_text){
        curr_node = (c=='0')?curr_node->left:curr_node->right;
        if(curr_node->left==NULL && curr_node->right==NULL){
            // cout<<curr_node->character<<' ';
            decompress+=curr_node->character;
            curr_node=root;
        }
    }
    return decompress;
}