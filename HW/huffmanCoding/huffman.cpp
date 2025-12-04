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
}

std::string Huffman::encode(const std::string& text) const {
}

std::string Huffman::decode(const std::string& bits) const {
}

void Huffman::printCodes() const {
}

void Huffman::printStats(const std::string& text,
                         const std::string& bits) const {
                         }
                        