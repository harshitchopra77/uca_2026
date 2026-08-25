#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) {
                return false;
            }

            char top = st.top();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }

            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string expression;
    cin >> expression;

    cout << isBalanced(expression);

    return 0;
}