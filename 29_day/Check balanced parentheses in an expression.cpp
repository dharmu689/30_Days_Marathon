#include <iostream>
#include <stack>
using namespace std;

bool areBracketsBalanced(char exp[])
{
    stack<char> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        // If it's a closing bracket, check for a match
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
            s.pop();
        }
    }

    // If stack is empty, brackets are balanced
    return s.empty();
}

int main()
{
    char exp[100];
    cout << "Enter an expression: ";
    cin >> exp;

    if (areBracketsBalanced(exp))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

/*
bool areBracketsBalanced(char exp[]) {
 // Write your code here
   stack<char> s;
   for (int i = 0; exp[i] != '\0'; i++) {
       char ch = exp[i];

       if (ch == '(' || ch == '{' || ch == '[') {
           s.push(ch);
       }

       else if (ch == ')' || ch == '}' || ch == ']') {
           if (s.empty()) return false;
           char top = s.top();
           if ((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[')) {
               return false;
           }
           s.pop();
       }
   }

   return s.empty();

}

*/