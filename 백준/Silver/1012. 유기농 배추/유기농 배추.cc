#include<bits/stdc++.h>
using namespace std;
int t, m, n, k, x, y, cnt, ny, nx;
int a[51][51];
int visited[51][51];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };
void go(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]){
            go(ny, nx);
        }
    }
  
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int w = 0; w < t; w++) {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        cnt = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        } // connected components 개수 찾기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j][i] && !visited[j][i]) {
                    go(j, i);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}