#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

bool capitalizeWords(const char* source, const char* dest) {
    ifstream inputFile(source);
    ofstream outputFile(dest);

    if (!inputFile) {
        cerr << "Error: Unable to open input file: " << source << endl;
        return false;
    }
    if (!outputFile) {
        cerr << "Error: Unable to open output file: " << dest << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line)) {
        bool newWord = true;
        for (char &ch : line) {
            if (isspace(ch)) {
                newWord = true; // If space, the next character is a new word
            } else if (newWord) {
                ch = toupper(ch); // Capitalize first letter of each word
                newWord = false;
            }
        }
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();
    return true;
}

int main() {
    const char* inputFile = "input.txt";
    const char* outputFile = "output.txt";

    if (capitalizeWords(inputFile, outputFile)) {
        cout << "File processed successfully! Check " << outputFile << endl;
    } else {
        cout << "File processing failed!" << endl;
    }

    return 0;
}


/*
void capitalizeWords(char source[20], char dest[20]) {
    ifstream inputFile(source);
    ofstream outputFile(dest);

    if (!inputFile || !outputFile) {
        return; 
    }

    string line;
    while (getline(inputFile, line)) {
        bool newWord = true;
        for (char &ch : line) {
            if (isspace(ch)) {
                newWord = true;
            } else if (newWord && islower(ch)) {
                ch = toupper(ch);
                newWord = false;
            } else {
                newWord = false;
            }
        }
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();
}
*/