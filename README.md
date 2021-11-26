# Lexical Analyzer

For this partial, here are delivered two different programs that work as a lexical analyzer, the first one is in c++ and the second one is in python, showing that even to just review the syntax, both approaches do the trick.

## C++
For the first one, I developed a program in this language mainly because it's efficiency being a compiled language. It is faster in it's execution time but way more complex to debug and to maintain.

To execute the program, first we have to compile it, with the command 
> `g++ -o exe lexicalAnalyzer.cpp`

then to execute it just run
> `./exe`

## Python
For the second one, I developed a program in a language that works different being interpreted. This language uses less lines of code and it was easier to implement. Also it was slower than c++ in execution but easier to maintain. 

To execute the program, we can run it with the command 
> `python3 lexicalAnalyzer.py`

## Usage
Both approaches work the same, they let you decide between reading a file or entering data directly from console. 

It starts with a message
> Lexical Analyzer

> There are two ways of using the analyzer, from file and from command line
Select the option: (1. From file, 2. From command line.)

and then we can chose an option. If we select option 1, it will ask for a file name
> filename: 

and if we select option 2 it will ask for the amount of productions and then it will let us enter them
> How many productions are?