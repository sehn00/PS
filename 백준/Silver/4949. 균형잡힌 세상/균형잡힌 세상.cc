#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    string S;
    
    while (1) {
        stack<char> st;
        string ok = "yes";
        getline(cin, S);
        if (S == ".") break;
        
        for (char c : S) {
            if (c == '(' || c == '[')
                st.push(c);
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = "no";
                    break;
                }
                st.pop();
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = "no";
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty()) ok = "no";
        
        cout << ok << '\n';
    }
    return 0;
}