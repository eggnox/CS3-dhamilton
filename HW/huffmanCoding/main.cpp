#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "huffman.h"

int main() {
    int choice;
    std::cout << "Huffman Coding\n";
    std::cout << "1) Load from file\n"
              << "2) Enter a string\n> ";
    std::cin >> choice;


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string text;

    if (choice == 1) {
        std::string path;
        std::cout << "Enter file path: ";
        std::getline(std::cin, path);

        std::ifstream fin(path);
        if (!fin) {
            std::cerr << "Failed to open file.\n";
            return 1;
        }
        text.assign((std::istreambuf_iterator<char>(fin)),
                    std::istreambuf_iterator<char>());
    } else {
        std::cout << "Enter text: ";
        std::getline(std::cin, text);
    }

    if (text.empty()) {
        std::cout << "No input provided.\n";
        return 0;
    }

    Huffman hf;
    hf.build(text);

    std::cout << "\nHuffman Codes:\n";
    hf.printCodes();

    std::string encoded = hf.encode(text);
    std::string decoded = hf.decode(encoded);

    std::cout << "\nEncoded String:\n" << encoded << "\n";
    std::cout << "\nDecoded String:\n" << decoded << "\n\n";


    std::cout << "\nCompression stats:\n";
    int originalBits  = text.size() * 8;
    int compressedBits = encoded.size();

    std::cout << "Compression Ratio:\n";
    std::cout << "Original size: "   << originalBits   << " bits\n";
    std::cout << "Compressed size: " << compressedBits << " bits\n";
    std::cout << "Compression ratio: "
            << static_cast<double>(originalBits) / compressedBits << "\n";

    return 0;
}