#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int dist[100002];
    fill(dist, dist+100002, -1);
    
    queue<int> Q;
    Q.push(n);
    dist[n] = 0;
    
    while (dist[k] == -1) {
        int cur = Q.front();
        Q.pop();
        
        for (auto next : {cur-1, cur+1, cur*2}) {
            if (next > 100000 || next < 0) continue;
            if (dist[next] != -1) continue;
            Q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }
    cout << dist[k] << '\n';
    
    return 0;
}