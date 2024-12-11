//  In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, [].
// Write C++ program using stack to check whether given expression is well parenthesized or not.

#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    bool push(char c) {
        if (top >= MAX - 1) {
            cout << "Stack overflow.\n";
            return false;
        }
        arr[++top] = c;
        return true;
    }

    char pop() {
        if (top < 0) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top < 0) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isWellParenthesized(const string& expression) {
    Stack s;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), ch)) {
                return false;
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expression;

    cout << "Enter an expression to check if it is well-parenthesized: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized.\n";
    } else {
        cout << "The expression is not well-parenthesized.\n";
    }
    return 0;
}
