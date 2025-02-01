#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[100][100];
int visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int y, x, ny, nx;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tme;
        cin >> tme;
        for (int j = 0; j < m; j++) {
            a[i][j] = tme[j]-48;
        }
    }
    // bfs의 level 찾기
    queue < pair<int, int>> q;
    q.push({ 0,0 });
    while (q.size()) {
        visited[0][0] = 1;
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || a[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx }); 
        }
    }
    //for (int i = 0; i < n; i++) {

    //    for (int j = 0; j < m; j++) {
    //        cout << a[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
    //for (int i = 0; i < n; i++) {

    //    for (int j = 0; j < m; j++) {
    //        cout << visited[i][j] << " ";
    //    }
    //    cout << "\n";
    //}
    cout << visited[n-1][m-1];
    return 0;
}