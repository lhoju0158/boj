#include<bits/stdc++.h>
using namespace std;

int a[10];  // 현재 보드 상태
int backup[10];  // 원래 보드 상태 백업
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ret = INT_MAX;

// (y, x) 위치와 인접한 전구 상태 변경
void toggle(int y, int x, int board[10]) {
    board[y] ^= (1 << x);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) continue;
        board[ny] ^= (1 << nx);
    }
}

// 켜진 전구 개수 세기
int countLights(int board[10]) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i] & (1 << j)) count++;
        }
    }
    return count;
}

// 첫 번째 행의 특정 구성에 대한 해결책 시도
void solve(int firstRowConfig) {
    // 원래 보드 복사
    int board[10];
    for (int i = 0; i < 10; i++) {
        board[i] = backup[i];
    }

    int pressCount = 0;

    // 첫 번째 행 구성 적용
    for (int j = 0; j < 10; j++) {
        if (firstRowConfig & (1 << j)) {
            toggle(0, j, board);
            pressCount++;
        }
    }

    // 이후 각 행에 대해, 윗 행의 상태에 따라 전구 토글
    for (int i = 1; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i - 1] & (1 << j)) {
                toggle(i, j, board);
                pressCount++;
            }
        }
    }

    // 모든 전구가 꺼졌는지 확인
    bool allOff = true;
    for (int i = 0; i < 10; i++) {
        if (board[i] != 0) {
            allOff = false;
            break;
        }
    }

    if (allOff) {
        ret = min(ret, pressCount);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // 보드의 초기 상태 읽기
    string s;
    for (int i = 0; i < 10; i++) {
        cin >> s;
        backup[i] = 0;
        for (int j = 0; j < 10; j++) {
            if (s[j] == 'O') {  // 'O'가 켜진 전구
                backup[i] |= (1 << j);
            }
        }
    }

    // 첫 번째 행의 모든 가능한 구성 시도 (2^10 = 1024가지)
    for (int config = 0; config < (1 << 10); config++) {
        solve(config);
    }

    if (ret == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ret;
    }

    return 0;
}