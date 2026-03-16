#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102] = {};
int dist[102][102] = {};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    string S;
    for (int i=0; i<N; i++) {
        cin >> S;
        for (int j=0; j<M; j++) {
            board[i][j] = S[j] - '0';
        }
    }
    
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0] = 1;
    
    while (!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if (board[nx][ny] == 0 || dist[nx][ny] != 0) continue;
            
            Q.push({nx,ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    cout << dist[N-1][M-1] << '\n';
    
    return 0;
}