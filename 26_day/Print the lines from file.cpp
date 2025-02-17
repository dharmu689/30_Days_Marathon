
#include <bits/stdc++.h>

// Include headers as needed

using namespace std;

int main()
{
    // Write your code here

    string filePath;

    cin >> filePath;

    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    vector<string> oddLines;
    vector<string> evenLines;
    string line;
    int lineNumber = 1;

    while (getline(file, line))
    {
        if (lineNumber % 2 != 0)
        {
            oddLines.push_back(line);
        }
        else
        {
            evenLines.push_back(line);
        }
        lineNumber++;
    }

    file.close();

    for (const auto &oddLine : oddLines)
    {
        cout << oddLine << endl;
    }

    for (const auto &evenLine : evenLines)
    {
        cout << evenLine << endl;
    }

    // Return 0 to indicate normal termination
    return 0;
}
