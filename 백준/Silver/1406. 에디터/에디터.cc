#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    string init;
    cin >> init;
    
    list<char> L;
    for (auto c : init) L.push_back(c);
    auto cursor = L.end();
    // cursor = 문자열 리스트의 마지막 노드 바로 다음의 가상 위치
    
    int M;
    cin >> M;
    while (M--) {
        char op;
        cin >> op;
        
        if (op == 'L') {
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') {
            if (cursor != L.end()) cursor++;
        }
        else if (op == 'B') {
            if (cursor != L.begin()) {
                cursor--;    // 커서 한칸 왼쪽으로 옮기고
                cursor = L.erase(cursor);
                // 왼쪽으로 한 칸 옮긴 커서가 가리키는 노드 지우고,
                // 리턴하는 다음 노드 주소를 cursor에 넣기
            }
        }
        else if (op == 'P') {
            char c;
            cin >> c;
            L.insert(cursor, c);
        }
    }
    
    for (auto c : L) cout << c;
    
    return 0;
}