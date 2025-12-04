#include "huffman.h"
#include <queue>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman(){
    freeTree(root);
    root = nullptr;
}

void Huffman::freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

void Huffman::build(const std::string& text) {
    //clear old tree
    freeTree(root);
    root = nullptr;
    codes.clear();

    if(text.empty()) return;

    //1. count frequencies
    std::map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    //2. priority queue
    using PQNode = Node*;
    struct Cmp{
        bool operator()(PQNode a, PQNode b) const{
            return a->freq > b->freq;
        }
    };

    std::priority_queue<PQNode, std::vector<PQNode>, Cmp> pq;
    for (auto & kv: freq){
        pq.push (new Node(kv.first, kv.second));
    }

    if (pq.empty()) return;

    //handles special cases
    if (pq.size() == 1) {
        Node* only = pq.top(); pq.pop();
        root = new Node ('\0', only->freq, only, nullptr);
    } else {
        // 3 combine nodes until one is left
        while (pq.size() > 1) {
            Node* a = pq.top(); pq.pop();
            Node* b = pq.top(); pq.pop();
            Node* parent = new Node('\0', a->freq + b->freq, a, b);
            pq.push(parent);
        }
        root = pq.top();
    }

    //4 generate code by walking trees
    buildCodes(root,"");
}

void Huffman::buildCodes(Node* node, const std::string& prefix) {
    if (!node) return;

    // leaf node
    if (!node->left && !node->right) {
        codes[node->ch] = prefix.empty() ? "0" : prefix;
        return;
    }

    buildCodes(node->left,  prefix + "0");
    buildCodes(node->right, prefix + "1");
}

std::string Huffman::encode(const std::string& text) const {
    std::string bits;
    for (char c : text) {
        auto it = codes.find(c);
        if (it != codes.end()) {
            bits += it->second;
        }
        // If a char isn't in codes 
        // skip it.
    }
    return bits;
}

std::string Huffman::decode(const std::string& bits) const {
    std::string result;
    if (!root) return result;

    Node* cur = root;
    for (char bit : bits) {
        if (bit == '0') cur = cur->left;
        else            cur = cur->right;

        if (!cur) break;  // safety

        if (!cur->left && !cur->right) {
            result.push_back(cur->ch);
            cur = root;
        }
    }
    return result;
}

void Huffman::printCodes() const {
    for (const auto& kv : codes) {
        char ch = kv.first;
        const std::string& code = kv.second;

        if (ch == ' ')
            std::cout << " : " << code << "\n";
        else if (ch == '\n')
            std::cout << "\\n: " << code << "\n";
        else
            std::cout << ch << ": " << code << "\n";
    }
}

void Huffman::printStats(const std::string& text,
                         const std::string& bits) const {
    std::size_t originalBits   = text.size() * 8;   // ASCII 
    std::size_t compressedBits = bits.size();       // 1 char = 1 bit symbol

    std::cout << "Original size:   " << originalBits   << " bits\n";
    std::cout << "Compressed size: " << compressedBits << " bits\n";
    if (compressedBits > 0) {
        double ratio = static_cast<double>(originalBits) / compressedBits;
        std::cout << "Compression ratio: "
                  << std::fixed << std::setprecision(2)
                  << ratio << "\n";
    }
 }
                        