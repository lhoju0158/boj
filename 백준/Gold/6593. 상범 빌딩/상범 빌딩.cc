#include<bits/stdc++.h>
using namespace std;

int c, r, l;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int visited[34][34][34];
char a[34][34][34];
struct trip {
    int z, y, x;
};
trip sang;
trip Exit;
string s;
int ret = -1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> s;
                for (int k = 0; k < c; k++) {
                    a[i][j][k] = s[k];
                    if (a[i][j][k] == 'S') sang = { i,j,k };
                    else if (a[i][j][k] == 'E') Exit = { i,j,k };
                }
            }
        }
        memset(visited, 0, sizeof(visited)); ret = -1;
        queue<trip> q; q.push(sang); visited[sang.z][sang.y][sang.x] = 1;
        while (!q.empty()) {
            trip _now = q.front(); q.pop();
            if (_now.z == Exit.z && _now.y == Exit.y && _now.x == Exit.x) {
                // 찾음
                ret = visited[_now.z][_now.y][_now.x];
                break;
            }
            for (int i = 0; i < 6; i++) {
                int nz = _now.z + dz[i]; int ny = _now.y + dy[i]; int nx = _now.x + dx[i];
                if (nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) continue;
                if (visited[nz][ny][nx] || a[nz][ny][nx] == '#') continue;
                visited[nz][ny][nx] = visited[_now.z][_now.y][_now.x] + 1;
                q.push({ nz, ny,nx });
            }
        }
        if (ret != -1) {
            cout << "Escaped in " << ret -1 << " minute(s).\n";
        }
        else {
            cout << "Trapped!\n";
        }
    }
    return 0;
}
