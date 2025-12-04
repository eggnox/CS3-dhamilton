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
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;
        Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
            : ch(c), freq(f), left(l), right(r) {}
    };

    Node* root;                             //root
    std::map<char, std::string> codes;      //char 

    void freeTree(Node* node);
    void buildCodes(Node* node, const std::string& prefix);

    Huffman(const Huffman&) = delete;
    Huffman& operator=(const Huffman&) = delete;
};