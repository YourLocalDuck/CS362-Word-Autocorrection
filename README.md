# Project Introduction

This program implements a hash table for word autocorrection. It reads all the entries from `Dictionary.txt` and stores them in a hash table. The program then uses this hash table to check the validity of user-inputted words.

# How to Compile

To compile the program, execute the following command:
```sh
make
```
This will create an executable named `TP`.

# How to Run

To compile and run the program in one step, use the following command:
```sh
make run
```

Alternatively, after compiling the program with make, you can run it by executing:
```sh
./TP
```

# Input/Output

### Input

The program expects a single word/string as input from the user.

### Output

- If the word is found in `Dictionary.txt`, the program returns `True`.
- If the word is not found, the program suggests a similar word and asks if this is what the user meant:
    - If the user confirms, the program returns `True`.
    - If the user denies, the program returns `False`.
- If no similar word is found, the program returns `False`.
- After returning `True` or `False`, the program prints out all the similar words it found and the time taken in microseconds to find each of those words.

# Team
This project was created by a signle developer as a term project for CS362.
