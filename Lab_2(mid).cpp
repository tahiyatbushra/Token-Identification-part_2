#include <iostream>
#include<fstream>
using namespace std;

// Function to check if a string is a keyword
bool isKeyword(string word) {
    // List of C++ keywords
    string keywords[] = {"if", "else", "while", "for", "int", "float", "char", "const"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; ++i) {
        if (word == keywords[i]) {
            return true;
        }
    }

    return false;
}

// Function to check if a string is an operator
bool isOperator(char ch) {
    char operators[] = {'+', '-', '*', '/', '=', '<', '>', '&', '|', '!'};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOperators; ++i) {
        if (ch == operators[i]) {
            return true;
        }
    }

    return false;
}

// Function to check if a string is a constant (integer or floating-point)
bool isConstant(string word) {
    bool hasDecimalPoint = false;

    for (char ch : word) {
        if (isdigit(ch)) {
            // Continue checking the next character
        } else if (ch == '.' && !hasDecimalPoint) {
            // Allow one decimal point
            hasDecimalPoint = true;
        } else {
            // Invalid character, not a constant
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inputFile;
    inputFile.open("example.txt");

    if (!inputFile) {
        cerr << "Error opening file\n";
        return 1;
    }


        string word;

        while (inputFile >> word) {
            if (isKeyword(word)) {
                cout << "Keyword: " << word << endl;
            } else if (isOperator(word[0])) {
                cout << "Operator: " << word << endl;
            } else if (isConstant(word)) {
                cout << "Constant: " << word << endl;
            } else {
                cout << "Identifier: " << word << endl;
            }
        }

    inputFile.close();
    return 0;
}
