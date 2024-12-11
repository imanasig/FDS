//  A palindrome is a string of character that's the same forward and backward. Typically, punctuation, capitalization, and spaces are ignored. For example, "Poor Dan is in a droop" is a palindrome, as can be seen
// by examining the characters "poor danisina droop" and observing that they are the same forward and backward One way to check for a palindrome is to reverse the characters in the string and then compare with them 
// the original-in a palindrome, the sequence will be identical. Write C++ program with functions
// a) To print original string followed by reversed string using stack
// b) To check whether given string is palindrome or not

#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;

class STACK {
private:
    char a[MAX];
    int top;

public:
    STACK() {
        top = -1;
    }

    void push(char c) {
        if (top >= MAX - 1) {
            cout << "\nStack overflow, cannot push more characters.";
            return;
        }
        top++;
        a[top] = c;
        a[top + 1] = '\0';
        cout << c << " is pushed onto the stack...\n";
    }

    void reverse() const {
        cout << "\nReversed string is: ";
        for (int i = top; i >= 0; i--) {
            cout << a[i];
        }
        cout << endl;
    }

    void convert(char str[]) {
        int k = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            if (isalnum(str[j])) { // Check if character is alphanumeric
                str[k] = tolower(str[j]); // Convert to lowercase
                k++;
            }
        }
        str[k] = '\0';
        cout << "\nConverted String: " << str << endl;
    }

    void palindrome() const {
        char reversed[MAX];
        int j = 0;

        for (int i = top; i >= 0; i--, j++) {
            reversed[j] = a[i];
        }
        reversed[j] = '\0';

        if (strcmp(reversed, a) == 0) {
            cout << "\nString is a palindrome...\n";
        } else {
            cout << "\nString is not a palindrome...\n";
        }
    }
};

int main() {
    STACK stack;
    char str[MAX];

    cout << "Enter a string to check if it is a palindrome: ";
    cin.getline(str, MAX);

    stack.convert(str);

    for (int i = 0; str[i] != '\0'; i++) {
        stack.push(str[i]);
    }

    stack.palindrome();
    stack.reverse();

    return 0;
}



