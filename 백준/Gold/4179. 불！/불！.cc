#include<bits/stdc++.h>
using namespace std;

int r, c;
char a[1004][1004];
int fires[1004][1004]; // 불 확산 시간
int visited[1004][1004]; // 지훈 이동 시간
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<int, int>> fireQ, jihunQ; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> a[i];
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'F') {
                fireQ.push({ i, j });
                fires[i][j] = 1; // 불의 시작점
            }
            else if (a[i][j] == 'J') {
                jihunQ.push({ i, j });
                visited[i][j] = 1; // 지훈의 시작점
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

    while (!jihunQ.empty()) {
        int y = jihunQ.front().first;
        int x = jihunQ.front().second;
        jihunQ.pop();

        if (y == 0 || x == 0 || y == r - 1 || x == c - 1) {
            cout << visited[y][x]; // 최소 탈출 시간 출력
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (a[ny][nx] == '#' || visited[ny][nx]) continue; // 벽이거나 이미 방문한 경우

            if (!fires[ny][nx] || visited[y][x] + 1 < fires[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                jihunQ.push({ ny, nx });
            }
        }
    }

    cout << "IMPOSSIBLE"; // 탈출 불가
}
