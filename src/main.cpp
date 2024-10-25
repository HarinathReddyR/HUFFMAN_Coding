#include<iostream>
#include<fstream>
#include <string>
#include <bitset>
#include "../include/Huffman.hpp"

using namespace std;
string convert_to_bytes(string bits){
    string bytes,temp="";
    int t;
    int len = bits.size();
    if(len%8!=0){
        int pad=8-(len)%8;
        t=pad;
        while(pad--){
            temp="0"+temp;
        }
    }
    bits=temp+bits;
    for(int i=0;i<8;i++){
        if(i==t-1)
            bits="1"+bits;
        else    
            bits ="0"+bits;
    }
    return bits;
}


void writeCompressedData(const string& bits, const string& filename) {
    ofstream file(filename, ios::binary);

    if (!file) { 
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    for (size_t i = 0; i < bits.length(); i += 8) {
        string byteString = bits.substr(i, 8);
        bitset<8> byte(byteString);
        char byteChar = static_cast<char>(byte.to_ulong());
        file.put(byteChar);
    }
    
    file.close(); 
}

void writefile(const string& data, const string& filename){
    ofstream file(filename, ios::binary);
    if (!file) { 
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    file << data;
    file.close();
}


double fileSize(const string& fileName){
    ifstream file(fileName);
    if (!file) {
        cerr << "Unable to open file: " << fileName << endl;
        return -1;
    }
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg(); 
    file.seekg(0);
    file.close();
    double sizeInMB = static_cast<double>(size) / (1024 * 1024);
    return sizeInMB;
}

int main(){
    string input_file="input.txt";
    ifstream file(input_file);
    if (!file) {
        cerr << "Unable to open file: " << input_file << endl;
        return 1;
    }

    string content;
    char ch;
    while (file.get(ch)) {
        content += ch;     
    }
    file.close();
    cout<<"oringinal input.txt size:"<<fileSize(input_file)<<'\n';
    Huffman* h= new Huffman(content);
    string compress =h->compress();
    string bytes_with_padding=convert_to_bytes(compress);

    // cout<<"com:"<<compress<<'\n';
    // cout<<bytes_with_padding;

    string output_com_file="compressed_input.txt";
    writeCompressedData(bytes_with_padding, output_com_file);
    cout<<"compressed input file size:"<<fileSize(output_com_file)<<'\n';

    string decompress= h->decompress();
    writefile(decompress,"decompressed_input.txt");
    // cout<<"decom:"<<decompress;
    cout<<"decompressed input file size:"<<fileSize("decompressed_input.txt")<<'\n';
    if(decompress==content)
        cout<<"Success! The data has been accurately decompressed back to its original form.";


    delete h;
    return 0;
}
