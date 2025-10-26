#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

bool isOperand(char c) {
    return !(c=='+' || c=='-' || c=='*' || c=='/');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for(char c : infix) {
        if(isOperand(c)) {
            postfix += c;
        }
        else {
            while(!st.empty() && prec(st.top()) >= prec(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*c+d-e/f";
    string postfix = infixToPostfix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}