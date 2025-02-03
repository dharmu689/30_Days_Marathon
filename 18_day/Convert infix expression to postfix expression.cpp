#include <bits/stdc++.h>
using namespace std;

#define SIZE 100
int Stack[SIZE], top = -1;

// Function prototypes
int isFull();
int isEmpty();
int push(int item);
int pop();

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Infix to Postfix conversion using the global stack
void infixToPostfix(char exp[], char output[]) {
    string infix(exp);
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;  // Operand, add to output
        } 
        else if (c == '(') {
            push(c);  // Push '(' onto stack
        } 
        else if (c == ')') {
            while (!isEmpty() && Stack[top] != '(') {
                postfix += (char)pop();
            }
            pop();  // Remove '('
        } 
        else {  // Operator
            while (!isEmpty() && precedence(c) <= precedence(Stack[top])) {
                postfix += (char)pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (!isEmpty()) {
        postfix += (char)pop();
    }

    // Remove spaces and copy to output
    postfix.erase(remove(postfix.begin(), postfix.end(), ' '), postfix.end());
    strcpy(output, postfix.c_str());
}

// Global Stack Operations
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
    char infixExp[] = "A+B*(C^D-E)^(F+G*H)-I";
    char postfixExp[SIZE];

    infixToPostfix(infixExp, postfixExp);

    cout << "Postfix Expression: " << postfixExp << endl;

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

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
    
int infixToPostfix(char exp[], char output[])
{
 string infix(exp);
    string postfix = "";
    stack<char> operators;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the '('
        } else if (ispunct(c)) { // If it's an operator
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    postfix.erase(std::remove(postfix.begin(), postfix.end(), ' '), postfix.end());
    strcpy(output, postfix.c_str());
}
*/