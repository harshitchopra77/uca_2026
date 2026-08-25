#include <bits/stdc++.h>
using namespace std;

int postfixEval(string& s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == ' ')
            continue;

        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0');
        }
        else {
            int fir = st.top();
            st.pop();

            int sec = st.top();
            st.pop();

            if (ch == '+') {
                st.push(sec + fir);
            }
            else if (ch == '-') {
                st.push(sec - fir);
            }
            else if (ch == '*') {
                st.push(sec * fir);
            }
            else if (ch == '/') {
                st.push(sec / fir);
            }
        }
    }

    return st.top();
}

int main() {
    string s;
    getline(cin, s);

    int res = postfixEval(s);
    cout << res;

    return 0;
}