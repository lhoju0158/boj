#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int visited[100][100];
int n;
int Min = 100;
int Max = 0;
int ret = 0;
int tem = 0;
int ny, nx;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
void go(int y, int x, int h) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || a[ny][nx] <= h) continue;
        if (visited[ny][nx]) continue;
        go(ny, nx, h);
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[j][i];
            Min = min(Min, a[j][i]);
            Max = max(Max, a[j][i]);
        }
    }
    // 입력 후
    // connected component 찾기
    for (int h = Min-1; h < Max + 1; h++) {
        // height
        tem = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j][i] > h && !visited[j][i]) {
                    go(j, i, h);
                    tem++;
                }
            }
        }
        // 0
        ret = max(ret, tem);
        //cout << h<<" and "<<tem << "\n";
        fill(&visited[0][0], &visited[0][0] + 100 * 100, 0);
    }
    cout << ret;
    return 0;
}