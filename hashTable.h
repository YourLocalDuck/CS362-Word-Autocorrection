#include <iostream>
#include <list>
#include "TimeInterval.h"

class hashTable // Class for hash table implementation
{
private:
    int hashTableLength; // How long to make the hash table. Usually 26 for letters in alphabet

    TimeInterval timer; // Calculate microsec between each suggestion.

    std::list<std::string> *table; // Double pointer to array of string. Array of lists with each list representing a letter.

public:
    hashTable(int HTLength); // Constructor with hash table length given.
    char hashFunction(std::string word); // Small method to turn a string into a character by getting the first letter.
    void insertWord(std::string word); // Method given word, find out which letter and list it belongs in, and affix to the end.
    ~hashTable(); // Destructor to delete entirety of the hash table.
    void displayHash(void); // Unused method to output the entire hash table.
    void findWord(std::string word); // Try to find the given word. If unable to find, suggest words. (method below this one)
    void suggestWords(std::string word, bool wordFound); // Suggest words based on the first 2 letters of the word or mispelling. If wordFound is false, also call suggestFirstWord to ask "Did you mean *".
    bool suggestFirstWord(std::string word); // Suggests a word to the user. If the suggested word is right, print true, else print false.
};

hashTable::hashTable(int HTLength)
{
    this->hashTableLength = HTLength;
    table = new std::list<std::string>[hashTableLength];
    timer = TimeInterval();
}

char hashTable::hashFunction(std::string word)
{
    return word[0];
}

void hashTable::insertWord(std::string word)
{
    char hash = hashFunction(word);
    int index = std::tolower(hash) - 97;
    table[index].push_back(word);
}

hashTable::~hashTable()
{
    delete[] table;
}

void hashTable::displayHash(void)
{
    for (int i = 0; i < hashTableLength; i++)
    {
        std::cout << i;
        for (std::string x : table[i])
            std::cout << " >> " << x;
        std::cout << std::endl;
    }
}

void hashTable::findWord(std::string word)
{
    bool foundWord = false;
    char hash = hashFunction(word);
    int index = std::tolower(hash) - 97;
    for (std::string x : table[index])
    {
        if (x == word)
        {
            foundWord = true;
            std::cout << std::boolalpha;
            std::cout << foundWord << std::endl;
            suggestWords(word, true);
        }
    }
    if (!foundWord)
    {
        suggestWords(word, false);
    }
}

void hashTable::suggestWords(std::string word, bool wordFound)
{
    timer.start();
    char hash = hashFunction(word);
    int index = std::tolower(hash) - 97;
    bool foundSuggestion = false;
    bool firstSuggestion = wordFound;
    for (std::string x : table[index])
    {
        if (x.length() < 2)
        {
        }
        else if (word[1] == x[1])
        {
            if (!firstSuggestion)
            {
                foundSuggestion = suggestFirstWord(x);
                std::cout << std::boolalpha;
                std::cout << foundSuggestion << std::endl;
                /*if (!foundSuggestion)
                    return;*/ 
                firstSuggestion = true;
                timer.start();
            }
            timer.stop();
            std::cout << x << std::endl;
            std::cout << timer.GetInterval() <<  " micro-sec" << std::endl;
            timer.start();
        }
    }
    if (!firstSuggestion)
    {
        std::cout << std::boolalpha;
        std::cout << firstSuggestion << std::endl;
    }
}

bool hashTable::suggestFirstWord(std::string word)
{
    std::string yesno;
    bool foundSuggestion = false;

    std::cout << "Did you mean " << word << "? (yes/no)" << std::endl;
    std::getline(std::cin, yesno);
    if (yesno == "yes")
    {
        foundSuggestion = true;
    }
    else if (yesno == "no")
    {
        foundSuggestion = false;
    }
    else
    {
        std::cout << "Invalid response. Assuming no" << std::endl;
        foundSuggestion = false;
    }
    return foundSuggestion;
}