#include "hashTable.h"
#include <iostream>
#include <fstream>

#define tableSize 5;

// Use file IO to read from "Dictionary.txt" and insert every entry into given hashTable H.
void inputDictionary(hashTable &H)
{
    std::string currentLine;
    std::ifstream dictionary("Dictionary.txt");

    if (dictionary.is_open())
    {
        while (std::getline(dictionary, currentLine))
        {
            H.insertWord(currentLine);
        }
        dictionary.close();
    }
    else
    {
        std::cout << "File Doesn't Exist" << std::endl;
    }
}

int main(int argc, char *argv[])
{
    // New hash table
    hashTable h(26);

    // FileIO to hashtable
    inputDictionary(h);

    std::string userInput;
    std::cout << "user enters: " << std::endl;
    std::getline(std::cin, userInput);
    std::cout << "the program responds: " << std::endl;
    h.findWord(userInput); // Algorithm

    return 0;
}