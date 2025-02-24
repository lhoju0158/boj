#include<bits/stdc++.h>
using namespace std;
int n;
int m[14][14];
int visited[14][14];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<int> nums;
int ret = 1e7;
int make(int y, int x) {
	int tem = m[y][x];	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		tem += m[ny][nx]; visited[ny][nx] = 1;
	}
	return tem;
}
void clear(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}
bool check(int y, int x) {
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; int nx = x + dx[i];
		if (nx<0||ny<0||nx>=n||ny>=n||visited[ny][nx]) return false;
	}
	return true;
}

void go(int cnt, int temret) {
	if (cnt == 3) { ret = min(ret, temret); return; }
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				go(cnt + 1, temret+make(i, j));
				clear(i, j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> m[i][j];
	}
	vector<int> vec;
	go(0, 0);
	cout << ret;
	
	return 0;
}