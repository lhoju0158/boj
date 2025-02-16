#include <bits/stdc++.h>
using namespace std;
int n, ret = 0;
int dy[8] = { 0,0,-1,1,-1,-1,1,1 };
int dx[8] = { -1,1,0,0,1,-1,1,-1 };

void go(int row, int(&a)[16][16]) {
    if (row >= n) {
        ret++;
        return;
    }

    for (int x = 0; x < n; x++) {
        if (a[row][x] == 1 || a[row][x] == -1) continue;

        int temp[16][16];
        memcpy(temp, a, sizeof(a));

        a[row][x] = 1;
        for (int i = 0; i < 8; i++) {
            int ny = row, nx = x;
            while (true) {
                ny += dy[i];
                nx += dx[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                a[ny][nx] = -1;
            }
        }

        go(row + 1, a);
        memcpy(a, temp, sizeof(a));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int a[16][16] = { 0 };
    go(0, a);

    cout << ret;
    return 0;
}
