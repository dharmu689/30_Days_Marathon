#include<bits/stdc++.h>

using namespace std;

int main() {
    string filename;
    cin >> filename; // Read filename

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file\n";
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    for (int i = lines.size() - 1; i >= 0; --i) {
        istringstream iss(lines[i]);
        vector<string> words;
        string word;

        while (iss >> word) {
            words.push_back(word);
        }

        for (int j = words.size() - 1; j >= 0; --j) {
            cout << words[j];
            if (j > 0) cout << " ";
        }
        cout << endl;
    }

    return 0;
}