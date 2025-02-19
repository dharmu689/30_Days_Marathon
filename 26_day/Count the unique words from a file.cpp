#include <bits/stdc++.h>
 
using namespace std;

int countUniqueWords(const string& filename) {
    ifstream file(filename); // Open the file
    if (!file) {
        return 0; // Return 0 if the file is not found
    }

    set<string> uniqueWords;
    string line, word;

    while (getline(file, line)) { // Read the file line by line
        stringstream ss(line);
        while (ss >> word) {
            string cleanWord = "";
            // Remove punctuation from the word
            for (char c : word) {
                if (isalnum(c)) {
                    cleanWord += tolower(c); // Convert to lowercase for uniformity
                }
            }
            if (!cleanWord.empty()) {
                uniqueWords.insert(cleanWord); // Add the cleaned word to the set
            }
        }
    }

    file.close(); // Close the file
    return uniqueWords.size(); // Return the count of unique words
}