/*
Alexis Vázquez
Compiladores
Analizador Léxico
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//Initialize vectors to be used
vector< string > productions;
vector< string > headers;
vector< string > terminals;

//Function to get non terminals or headers
void getHeaders(){
    for (int i = 0; i < productions.size(); i++){
        //split the vector into it's elements to obtain separate productions
        string head = productions[i].substr(0, productions[i].find(" "));
        //check if the first element in the production is already a header, if not, add it to the list
        if (count(headers.begin(), headers.end(), head)) {    
        } else {
            headers.push_back(head);
        }
    }
}

//Function to get terminals
void getTerminals(){
    //Initialize variables to help divide the vector
    size_t pos = 0;
    string token;
    string delimiter = " ";

    for (int i = 0; i < productions.size(); i++){
        //Split the vector into it's elements to obtain separate productions
        string s = productions[i];
        //Add a provitional space to help read the last element in the production
        s.append(" ");
        //Execute a while loop within the for to iterate over individual elements
        while ((pos = s.find(delimiter)) != string::npos) {
            //Set a token by splitting the vector into sepparate parts with spaces as delimiters
            token = s.substr(0, pos);
            //Check if element already in headers, in terminals or is a special character, if not, push to the vector
            if (count(headers.begin(), headers.end(), token)) {}
            else if (count(terminals.begin(), terminals.end(), token)) {}
            else if (token == "->" || token == "'"){}
            else {
                terminals.push_back(token);
            }
            //Remove the first element to keep iterationg over the production
            s.erase(0, pos + delimiter.length());
        }
    }
}
//Function to receive the productions from an input if option 2 is selected
void lexicalAnalyzerConsoleCMD(){
    int amount;
    cout << "How many productions are? " << endl;
    
    cin >> amount;
    cin.ignore();

    cout << endl;
    string s;
    //Appending the input to the productions while reading them
    for (int i = 0; i < amount; i++)
    {
        getline(cin, s);
        productions.push_back(s);
    }
}

//Function to receive an input file if the option number 1 is selected
void lexicalAnalyzerConsoleFile(){
    string filename = "";
    cout << endl << "Filename: "; 
    cin >> filename;
    //use ifstream to read file
    ifstream file(filename);
    string str; 
    string str2 = "";
    //read line and save in string
    while (getline(file, str))
    {
        str2 += str;
        str2.push_back('\n');
    }
    //convert string into array with the productions
    size_t pos = 0;
    string token;
    char delimiter = '\n';
    str2.append(" ");
    while ((pos = str2.find(delimiter)) != string::npos) {
        token = str2.substr(0, pos);
        productions.push_back(token);
        str2.erase(0, pos + 1);
    }
}

//Execute Main function
int main() {
    int option;
    //Usage options
    cout << "Lexical Analyzer" << endl << endl;
    cout << "There are two ways of using the analyzer, from file and from command line" << endl;
    cout << "Select the option: (1. From file, 2. From command line.)" << endl;
    
    cin >> option;

    if (option == 1)
    {
        lexicalAnalyzerConsoleFile();
    }else{
        lexicalAnalyzerConsoleCMD();
    }

    //Execute the functions to find elements
    getHeaders();
    getTerminals();
    cout << endl << "Terminal: ";
    for (int i = 0; i < terminals.size(); i++)
    {
        cout << terminals[i];
        if (i < terminals.size() - 1) cout << ", ";
    }

    cout << endl << "Non Terminal: ";
    for (int i = 0; i < headers.size(); i++)
    {
        cout << headers[i];
        if (i < headers.size() - 1) cout << ", ";
    }
    cout << endl;
    
    return 0;
}