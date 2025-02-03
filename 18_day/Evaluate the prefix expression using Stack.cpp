#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
int Stack[SIZE], top = -1;

// Function prototypes (assuming these are implemented elsewhere)
int isFull();
int isEmpty();
int push(int item);
int pop();

int evalPrefix(string exp) {
    int n = exp.length();
    
    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int operand1 = pop(); // First operand (popped first)
            int operand2 = pop(); // Second operand (popped second)

            int result;
            switch (exp[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = (int)pow(operand1, operand2); break;
                default: cout << "Invalid operator"; return -1;
            }
            push(result);
        }
    }
    return pop();
}

// Example implementation of push and pop using global variables
int isFull() { return top == SIZE - 1; }
int isEmpty() { return top == -1; }

int push(int item) {
    if (!isFull()) {
        Stack[++top] = item;
        return 1;
    }
    cout << "Stack Overflow\n";
    return 0;
}

int pop() {
    if (!isEmpty()) {
        return Stack[top--];
    }
    cout << "Stack Underflow\n";
    return -1;
}

// Driver function
int main() {
    string prefixExpr = "-+8*32/64"; // Example: "- + 8 * 3 2 / 6 4"
    cout << "Prefix Evaluation Result: " << evalPrefix(prefixExpr) << endl;
    return 0;
}


/*
int Stack[SIZE], top=-1;
int isFull();
int isEmpty();
int push(int item);
int pop();

Above variables are used for Stack, SIZE and top and all are global variables. Also above push and pop functions are provided. 
 #include<bits/stdc++.h>
int evalPrefix(char* exp)
{
  string s(exp); // Convert char* to string
    stack<int> st;
    int n = s.length();

    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            switch (s[i]) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1, operand2));
                    break;
            }
        }
    }
    return st.top();

}
*/