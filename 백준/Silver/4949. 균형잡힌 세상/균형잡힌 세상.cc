#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (1) {
        string S;
        bool ok = 1;
        stack<char> st;
        getline(cin, S);
        if (S == ".") break;
        
        for (char c : S) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = 0;
                    break;
                }
                else st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = 0;
                    break;
                }
                else st.pop();
            }
        }
        if (ok == 1 && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}