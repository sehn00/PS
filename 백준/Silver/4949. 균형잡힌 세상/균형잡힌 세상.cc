#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (1) {
        stack<int> st;
        bool ok = 1;
        string S;
        getline(cin, S);
        if (S == ".") break;
        
        for (char c : S) {
            if (c == '(' || c == '[')
                st.push(c);    // 여는 괄호는 스택에 저장
            else if (c == ')') {
                if (st.empty() || st.top() != '(') {
                    ok = 0;
                    break;      // 닫는 괄호 들어왔는데
                }               // 스택 비거나, 짝이 안맞으면 break
                else st.pop();  // 짝 맞으면 pop()
            }
            else if (c == ']') {
                if (st.empty() || st.top() != '[') {
                    ok = 0;
                    break;      // 마찬가지
                }
                else st.pop();
            }
        }
        if (!st.empty()) ok = 0;
        // 문자열 끝까지 돌았는데 스택 안비었으면 0

        if (ok == 0) cout << "no\n";
        else cout << "yes\n";
    }
    return 0;
}