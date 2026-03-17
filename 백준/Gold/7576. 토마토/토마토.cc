#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1002][1002] = {};
int day[1002][1002] = {};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int M, N, mx = -1;
    cin >> M >> N;
    
    queue<pair<int,int>> Q;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == 1) Q.push({i,j});
                // BFS는 시간/거리 layer 순으로 탐색한다!
                // 여러 시작점이 있으면, 그 시작점들이 queue의 앞에 들어가고
                // 시작점 각각의 dx[dir] 탐색 결과는 queue의 뒤에 들어가기 때문
            if (board[i][j] == 0) day[i][j] = -1;
        }
    }

    while (!Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
                
        for (int dir=0; dir<4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx<0 || nx>=N || ny<0 || ny>=M) continue;
            if (day[nx][ny] >= 0) continue;
            day[nx][ny] = day[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            mx = max(mx, day[i][j]);
            if (day[i][j] == -1) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << mx << '\n';
    
    return 0;
}