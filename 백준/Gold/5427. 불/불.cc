#include<bits/stdc++.h>
using namespace std;
int n;
int r, c;
char a[1004][1004];
int fires[1004][1004]; 
int visited[1004][1004]; 
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<int, int>> fireQ, sangQ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> c >> r;
        memset(visited, 0, sizeof(visited));
        memset(fires, 0, sizeof(fires));
        while (!fireQ.empty()) fireQ.pop();
        while (!sangQ.empty()) sangQ.pop();
        bool exit = false;
        for (int i = 0; i < r; i++) {
            cin >> a[i];
            for (int j = 0; j < c; j++) {
                if (a[i][j] == '*') {
                    fireQ.push({ i, j });
                    fires[i][j] = 1;
                }
                else if (a[i][j] == '@') {
                    sangQ.push({ i, j });
                    visited[i][j] = 1;
                }
            }
        }

        while (!fireQ.empty()) {
            int y = fireQ.front().first;
            int x = fireQ.front().second;
            fireQ.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (a[ny][nx] == '#' || fires[ny][nx]) continue;
                fires[ny][nx] = fires[y][x] + 1;
                fireQ.push({ ny, nx });
            }
        }

        while (!sangQ.empty()) {
            int y = sangQ.front().first;
            int x = sangQ.front().second;
            sangQ.pop();

            if (y == 0 || x == 0 || y == r - 1 || x == c - 1) {
                cout << visited[y][x]<<"\n"; // 최소 탈출 시간 출력
                exit = true; break;
            }

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                if (a[ny][nx] == '#' || visited[ny][nx]) continue; // 벽이거나 이미 방문한 경우

                if (!fires[ny][nx] || visited[y][x] + 1 < fires[ny][nx]) {
                    visited[ny][nx] = visited[y][x] + 1;
                    sangQ.push({ ny, nx });
                }
            }
        }
        if(!exit) cout << "IMPOSSIBLE\n"; // 탈출 불가
    }
    
}
