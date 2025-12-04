#pragma once
#include <string>
#include <map>

class Huffman {
public:
    Huffman();
    ~Huffman();

    //Build trees
    void build(const std::string& text);

    //encode and decode
    std::string encode(const std::string & text) const;
    std::string decode(const std::string & bits) const;

    //print code + stats
    void printCodes() const;
    void printStats(const std::string& text, 
                    const std:: string& bits) const;


private:
};