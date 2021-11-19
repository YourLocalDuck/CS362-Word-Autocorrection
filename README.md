# Term Project
Hash Table

This program pulls all the entries in `Dictionary.txt` and puts it all into a hash table implementation. It will use this hash table implementation to check whatever word you input in.

To compile the program execute `make` and the executable will be named `TP`. Executing `make run` will also compile the program but in addition it will also run the program.

The program will begin by asking you for an input. The input that it expects is a word/string. After you enter the word, if it finds a matching entry in the file `Dictionary.txt`, It will return `True`. If it does not, It will most likely ask you `Did you mean` and then a similar word. If yes, the program will return true, and if not, it will return `False`. If it does not find any similar word, it will return `False` and exit. After returning true or false, before exitting, it will print out all of the similar words that it finds and how long in microseconds it took to find each of those words. The program will then exit.