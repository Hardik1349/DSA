#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {

    if (ch == '+' || ch == '-') {
        return 1;
    }

    if (ch == '*' || ch == '/') {
        return 2;
    }

    return 0;
}

string infixToPostfix(string infix) {

    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        if (ch == ' ') {
            continue;
        }

        if (ch >= '0' && ch <= '9') {
            postfix += ch;
            postfix += ' ';
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            }
        }

        else if (isOperator(ch)) {

            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch)) {

                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int main() {

    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}