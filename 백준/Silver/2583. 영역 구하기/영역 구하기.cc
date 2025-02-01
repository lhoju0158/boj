#include<bits/stdc++.h>
using namespace std;
int m, n, k, sx, sy, ex, ey, ny, nx;
int cnt = 0;
int tem = 0;
vector<int> v;
int a[101][101];
int visited[101][101];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void go(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
        if (a[ny][nx] == 0 && !visited[ny][nx]) {
             go(ny, nx);
        }
    }
    tem++;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for (int q = 0; q < k; q++) {
        cin >> sx >> sy >> ex >> ey;
        for (int i = sx; i < ex ; i++) {
            for (int j = sy; j < ey ; j++) {
                a[j][i] = 1;
            }
        }
    }
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << a[j][i] << " ";
    //    }
    //    cout << "\n";

    //}
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j][i] == 0 &&!visited[j][i]) {
                go(j, i);
                cnt++;
                v.push_back(tem);
                tem = 0;
            }
        }
    }
    cout << cnt << "\n";
    sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << " ";
    }
    return 0;
}