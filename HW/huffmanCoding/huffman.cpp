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
}

void Huffman::build(const std::string& text) {
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
                        